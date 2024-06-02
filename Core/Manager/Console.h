#pragma once

class Console : public Singleton<Console>, public Callback
{
public:
	class MessageBase
	{
	public:
		std::string prefix = "";
		std::string message = "";
		ImVec4 prefixColor = ImVec4(1.f, 1.f, 1.f, 1.f);
		ImVec4 messageColor = ImVec4(1.f, 1.f, 1.f, 1.f);

		MessageBase(std::string prefix, std::string message, ImVec4 prefixColor = ImVec4(1.f, 1.f, 1.f, 1.f), ImVec4 messageColor = ImVec4(1.f, 1.f, 1.f, 1.f)) : prefix(prefix), message(message), prefixColor(prefixColor), messageColor(messageColor) { }
	};
	class CommandBase
	{
	public:
		struct CommandParameter
		{
			int index = 0;
			bool isVariable = false;
			std::string hiddenBasisParameter = "";
			std::string hiddenBasisValue = "";
			int hiddenBasisIndex = 0;
			std::vector<CommandParameter> formalParameters = {};
			std::string name = "";

			CommandParameter(std::string name) : name(name)
			{
				if (name.size() > 3)
				{
					isVariable = name.substr(name.size() - 3) == XOR("...");
					if (isVariable)
					{
						this->name = name.substr(0, name.size() - 3);
					}
				}
				//[value]{type=\"set\"} 解析这样的语法
				// \"和\"里是隐藏hiddenBasisValue
				if (name.size() > 9)
				{
					auto start = name.find_first_of('{');
					if (start != std::string::npos)
					{
						auto end = name.find_first_of('}');
						if (end != std::string::npos)
						{
							hiddenBasisParameter = name.substr(start + 1, name.substr(start + 1, name.size() - start - 1).find_first_of('='));
							start = name.find_first_of('\"');
							if (start != std::string::npos)
							{
								end = name.find_last_of('\"');
								if (end != std::string::npos)
								{
									hiddenBasisValue = name.substr(start + 1, end - start - 1);
								}
							}
						}
						this->name = name.substr(0, name.find_first_of('{'));
					}
				}
			}
			CommandParameter(const char* name) : CommandParameter(std::string(name)) { }

			void SetHiddenBasisIndex(std::vector<CommandParameter>& parameters)
			{
				formalParameters = parameters;
				for (size_t i = 0; i < parameters.size(); i++)
				{
					if (parameters[i].name == hiddenBasisParameter)
					{
						hiddenBasisIndex = (int)i;
						break;
					}
				}
			}

			bool IsHidden(std::vector<std::string> actualParameters) const
			{
				if (hiddenBasisParameter.empty() || hiddenBasisValue.empty())
				{
					return false;
				}
				if (hiddenBasisIndex + 1 > actualParameters.size())
				{
					return true;
				}
				if (formalParameters[hiddenBasisIndex].IsHidden(actualParameters))
				{
					return true;
				}
				return actualParameters[hiddenBasisIndex] != hiddenBasisValue;
			}

			bool IsPassed(std::vector<std::string> actualParameters) const
			{
				if (IsHidden(actualParameters))
				{
					return false;
				}
				if (actualParameters.size() < index + 1)
				{
					return false;
				}
				return true;
			}

			operator std::string() const { return name; }

			bool operator==(const std::string& name) const
			{
				return this->name == name;
			}

			const char* c_str() const
			{
				return name.c_str();
			}
		};
		const std::string name = "";
		std::vector<CommandParameter> parameter = {};
		bool hasVariableParameter = false;

		CommandBase(std::string name, std::vector<CommandParameter> parameter = {})
			: name(name), parameter(parameter)
		{
			if (!parameter.empty())
			{
				hasVariableParameter = this->parameter.back().isVariable;
			}
			for (size_t i = 0; i < parameter.size(); i++)
			{
				this->parameter[i].index = (int)i;
				if (!this->parameter[i].hiddenBasisParameter.empty())
				{
					this->parameter[i].SetHiddenBasisIndex(this->parameter);
				}
			}
			Console::Get()->RegisterCommand(this);
		}

		std::vector<std::string> GetParameterNames()
		{
			std::vector<std::string> result;
			for (size_t i = 0; i < parameter.size(); i++)
			{
				result.push_back(parameter[i].name);
			}
			return result;
		}

		virtual void Executer(std::vector<std::string> parameters) = 0;
	};
	class CommandLog
	{
	public:
		CommandLog() { }
		CommandLog(CommandBase* command, std::vector<std::string> parameters) : command(command), time(NaTime::Now()), parameters(parameters) { }
		CommandBase* command = nullptr;
		NaTime time = NaTime();
		std::vector<std::string> parameters = {};

		bool operator==(const CommandLog& log) const
		{
			return command == log.command && parameters == log.parameters && time == log.time;
		}

		bool operator!=(const CommandLog& log) const
		{
			return !(*this == log);
		}

		operator bool() const
		{
			return command != nullptr;
		}
	};

	void RegisterCommand(CommandBase* command)
	{
		commands[command->name] = command;
	}

	void AddCommandLog(CommandLog log)
	{
		if (commandHistory.size() >= setting.maxCommandLogCount)
		{
			commandHistory.erase(commandHistory.begin());
		}
		commandHistory.push_back(log);
	}

	std::pair<std::string, std::vector<std::string>> ParseInput(const std::string& input)
	{
		std::string command;
		std::vector<std::string> parameters;
		std::string current;
		bool inQuotes = false, commandSet = false;

		for (size_t i = 0; i < input.length(); ++i)
		{
			char ch = input[i];
			if (ch == '\"')
			{
				inQuotes = !inQuotes; // Toggle state
			}
			else if (!inQuotes && ch == ' ')
			{
				if (!current.empty())
				{
					// If we have accumulated a word and it's not within quotes
					if (!commandSet)
					{
						command = current; // Set command if not already set
						commandSet = true;
					}
					else
					{
						parameters.push_back(current); // Add to parameters if command is set
					}
					current.clear(); // Reset current word accumulator
				}
			}
			else
			{
				current += ch; // Accumulate characters for the current word
			}

			// Handle case where last parameter is within quotes
			if (inQuotes && i == input.length() - 1)
			{
				current += ch; // Include the last quote character
			}
		}

		// Check for last word/parameter after the loop
		if (!current.empty())
		{
			if (!commandSet)
			{
				command = current;
			}
			else
			{
				parameters.push_back(current);
			}
		}

		return { command, parameters };
	}
public:
	class Message : public MessageBase
	{
	public:
		Message(std::string message, ImVec4 messageColor = ImVec4(1.f, 1.f, 1.f, 1.f)) : MessageBase(XOR("[Console]"), message, ImVec4(1.f, 1.f, 1.f, 1.f), messageColor) { }
	};

	struct Setting
	{
		int maxMessageCount = 100;
		int maxCommandLogCount = 10;
		int maxCommandShownCount = 3;
	} setting;

	std::vector<MessageBase> messages = {};
	std::unordered_map<std::string, CommandBase*> commands = {};
	std::vector<CommandLog> commandHistory = {};
	std::string currentInput = "";
	CommandLog currentInputHistory = CommandLog();
	std::string inputCache = "";
	std::string currentCommand = "";
	std::vector<std::string> currentParameters;

	Console() : Callback(XOR("ImGui Frame")) {}

	void AddMessage(MessageBase message)
	{
		if (messages.size() >= setting.maxMessageCount)
		{
			messages.clear();
		}
		messages.push_back(message);
	}

	void InvokeCommand(std::string commandName, std::vector<std::string> parameters)
	{
		auto command = commands.find(commandName);
		if (command == commands.end())
		{
			AddMessage(Message(XOR("Command not found"), ImVec4(1.f, 0.f, 0.f, 1.f)));
			return;
		}
		command->second->Executer(parameters);
		AddCommandLog(CommandLog(command->second, parameters));
	}

	void Invoker() override
	{
		auto filterCommand = [](std::string input, std::string command) -> bool
			{
				if (input.size() > command.size())
					return false;
				for (int i = 0; i < input.size(); i++)
				{
					if (std::tolower(input[i]) != std::tolower(command[i]))
					{
						return false;
					}
				}
				return true;
			};
		auto searchCommands = [&](const std::string& input) -> std::vector<CommandBase*>
			{
				std::string currentCommandName = ParseInput(input).first;
				std::vector<CommandBase*> foundCommands;
				for (auto& [_, command] : commands)
				{
					if (filterCommand(currentCommandName, command->name))
					{
						foundCommands.push_back(command);
					}
				}
				return foundCommands;
			};
		ImGui::Begin(XOR("Console"));
		if (inputCache != currentInput)
		{
			inputCache = currentInput;
			if (!inputCache.empty())
			{
				auto ParseResult = ParseInput(inputCache);
				currentCommand = ParseResult.first;
				currentParameters = ParseResult.second;
			}
		}
		ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
		if (ImGui::InputText(XOR("#Input"), &currentInput, ImGuiInputTextFlags_EnterReturnsTrue))
		{
			InvokeCommand(currentCommand, currentParameters);
			currentInput = "";
			currentInputHistory = CommandLog();
		}
		if (ImGui::IsItemActive())
		{
			if (!currentInput.empty())
			{
				auto foundCommands = searchCommands(currentCommand);
				if (foundCommands.size() > setting.maxCommandShownCount)
				{
					ImGui::BeginChild(XOR("CommandList"), ImVec2(0.f, 50.f), ImGuiChildFlags_Border);
				}
				for (auto& command : foundCommands)
				{
					for (size_t i = 0; i < currentCommand.size(); i++)
					{
						auto ch = command->name[i];
						ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));
						if (std::tolower(ch) == std::tolower(currentCommand[i]))
						{
							if (ch == currentCommand[i])
							{
								ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.f), XOR("%c"), ch);
							}
							else
							{
								ImGui::Text(XOR("%c"), ch);
							}
						}
						else
						{
							ImGui::Text(XOR("%c"), ch);
						}
						if (i != currentCommand.size() - 1)
						{
							ImGui::SameLine();
						}
						ImGui::PopStyleVar();
					}
					if (currentCommand.size() < command->name.size())
					{
						ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.f, 0.f));
						ImGui::SameLine();
						ImGui::Text(XOR("%s"), command->name.substr(currentCommand.size()).c_str());
						ImGui::PopStyleVar();
					}

					for (size_t i = 0; i < command->parameter.size(); i++)
					{
						if (i > command->parameter.size())
						{
							break;
						}
						if (command->parameter[i].IsHidden(currentParameters))
						{
							continue;
						}
						ImGui::SameLine();
						if (command->parameter[i].IsPassed(currentParameters))
							ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.f), XOR("%s"), command->parameter[i].c_str());
						else
							ImGui::Text(XOR("%s"), command->parameter[i].c_str());
					}
					if (currentParameters.size() <= command->parameter.size())
						continue;
					if (command->hasVariableParameter)
					{
						for (size_t i = command->parameter.size(); i < currentParameters.size(); i++)
						{
							if (command->parameter.back().IsHidden(currentParameters))
							{
								continue;
							}
							ImGui::SameLine();
							ImGui::TextColored(ImVec4(0.5f, 0.5f, 0.5f, 1.f), XOR("%s"), command->parameter.back().c_str());
						}
					}
				}
				if (foundCommands.size() > setting.maxCommandShownCount)
				{
					ImGui::EndChild();
				}
			}
			if (!commandHistory.empty() && (ImGui::IsKeyPressed(ImGuiKey_UpArrow) || ImGui::IsKeyPressed(ImGuiKey_DownArrow)))
			{
				if (ImGui::IsKeyPressed(ImGuiKey_UpArrow))
				{
					if (currentInputHistory)
					{
						auto it = std::find(commandHistory.begin(), commandHistory.end(), currentInputHistory);
						if (it != commandHistory.begin())
						{
							currentInputHistory = *(it - 1);
						}
					}
					else
					{
						currentInputHistory = commandHistory.back();
					}
				}
				else if (ImGui::IsKeyPressed(ImGuiKey_DownArrow) && currentInputHistory)
				{
					auto it = std::find(commandHistory.begin(), commandHistory.end(), currentInputHistory);
					if (it != commandHistory.end() - 1)
					{
						currentInputHistory = *(it + 1);
					}
					else
					{
						currentInputHistory = CommandLog();
					}
				}
				if (currentInputHistory)
				{
					currentInput = Utils::Format(XOR("%s %s"), currentInputHistory.command->name.c_str(), Utils::Join(currentInputHistory.parameters, XOR(" ")).c_str());
				}
				else
				{
					currentInput = "";
				}
				if (ImGuiInputTextState* inputState = ImGui::GetInputTextState(ImGui::GetID(XOR("#Input"))))
					inputState->ReloadUserBufAndSelectAll();
			}
		}
		else if (currentInputHistory)
		{
			currentInputHistory = CommandLog();
		}
		ImGui::Separator();
		ImGui::BeginChild(XOR("Console"), ImVec2(0.f, 0.f));
		for (auto& message : messages)
		{
			ImGui::TextColored(message.prefixColor, message.prefix.c_str());
			ImGui::SameLine();
			ImGui::TextColored(message.messageColor, message.message.c_str());
		}
		if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		{
			ImGui::SetScrollHereY(1.f);
		}
		ImGui::EndChild();
		ImGui::End();
	}
public:
	class ConsoleClear : public Console::CommandBase
	{
	public:
		ConsoleClear() : Console::CommandBase(XOR("Clear")) { }
		void Executer(std::vector<std::string> parameters) override
		{
			Console::Get()->messages.clear();
		}
	};
	class ConsoleHelp : public Console::CommandBase
	{
	public:
		ConsoleHelp() : Console::CommandBase(XOR("Help")) { }
		void Executer(std::vector<std::string> parameters) override
		{
			for (auto& [_, command] : Console::Get()->commands)
			{
				Console::Get()->AddMessage(Console::Message(Utils::Format(XOR("%s %s"), command->name.c_str(), Utils::Join(command->GetParameterNames(), XOR(" ")).c_str())));
			}
		}
	};
	class ConsoleEcho : public Console::CommandBase
	{
	public:
		ConsoleEcho() : Console::CommandBase(XOR("Echo"), { XOR("<message>...") }) {}
		void Executer(std::vector<std::string> parameters) override
		{
			Console::Get()->AddMessage(Console::Message(Utils::Join(parameters, XOR(", "))));
		}
	};
	class ConsoleTest : public Console::CommandBase
	{
	public:
		ConsoleTest() : Console::CommandBase(XOR("Test"), { XOR("[a]"), XOR("[b]{[a]=\"b\"}") , XOR("[c]{[b]=\"c\"}...") }) { }
		void Executer(std::vector<std::string> parameters) override
		{
			Console::Get()->AddMessage(Console::Message(Utils::Join(parameters, XOR(", "))));
		}
	};
};
SINGLETON_ACTIVATE_FAST(Console::ConsoleClear);
SINGLETON_ACTIVATE_FAST(Console::ConsoleHelp);
SINGLETON_ACTIVATE_FAST(Console::ConsoleEcho);
SINGLETON_ACTIVATE_FAST(Console::ConsoleTest);

namespace ManagerCommands
{
	class Unload : public Console::CommandBase
	{
	public:
		Unload() : Console::CommandBase(XOR("Unload")) { }

		void Executer(std::vector<std::string> parameters) override
		{
			Application::Get()->Unload();
		}
	};
	SINGLETON_ACTIVATE_FAST(Unload);

#ifdef _DEBUG
	class CallbackList : public Console::CommandBase
	{
	public:
		CallbackList() : Console::CommandBase(XOR("CallbackList")) { }

		void Executer(std::vector<std::string> parameters) override
		{
			for (auto& item : CallbackManager::Get()->callbacks)
			{
				Console::Get()->AddMessage(Console::Message(Utils::Format(XOR("%s %s"), item->functionName.c_str(), item->period.c_str())));
			}
		}
	};
	SINGLETON_ACTIVATE_FAST(CallbackList);

	class HookList : public Console::CommandBase
	{
	public:
		HookList() : Console::CommandBase(XOR("HookList")) { }

		void Executer(std::vector<std::string> parameters) override
		{
			for (auto& item : HookManager::Get()->items)
			{
				Console::Get()->AddMessage(Console::Message(Utils::Format(XOR("%s %s"), item->hookName.c_str(), item->hooked ? XOR("Hooked") : XOR("Unhooked"))));
			}
		}
	};
	SINGLETON_ACTIVATE_FAST(HookList);

	class ResourceList : public Console::CommandBase
	{
	public:
		ResourceList() : Console::CommandBase(XOR("ResourceList")) { }

		void Executer(std::vector<std::string> parameters) override
		{
			for (auto& item : ResourceManager::Get()->resources)
			{
				Console::Get()->AddMessage(Console::Message(Utils::Format(XOR("%s %d"), item->suffix.c_str(), item->id)));
			}
		}
	};
	SINGLETON_ACTIVATE_FAST(ResourceList);

	class SingletonList : public Console::CommandBase
	{
	public:
		SingletonList() : Console::CommandBase(XOR("SingletonList")) { }

		void Executer(std::vector<std::string> parameters) override
		{
			for (auto& [name, instance] : singletonManager.instances)
			{
				Console::Get()->AddMessage(Console::Message(Utils::Format(XOR("%s %p"), name.c_str(), instance.instance)));
			}
		}
	};
	SINGLETON_ACTIVATE_FAST(SingletonList);
#endif
}
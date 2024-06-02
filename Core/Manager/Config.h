#pragma once

//namespace ConfigReflection
//{
//	class Object;
//	class ObjectTree;
//
//	class SmartConfigManager : public Singleton<SmartConfigManager>
//	{
//	public:
//		std::unordered_map<std::string, ObjectTree*> trees = {};
//
//		void AddTree(ObjectTree* tree);
//
//		ObjectTree* GetTree(const std::string& name);
//	};
//
//	class ObjectTree
//	{
//	public:
//		std::string name = "";
//
//		std::unordered_map<std::string, ObjectTree*> trees = {};
//		std::vector<Object*> content = {};
//
//		ObjectTree() = default;
//		ObjectTree(const ObjectTree*& tree) 
//			: name(std::move(tree->name)), trees(std::move(tree->trees)), content(std::move(tree->content)) {}
//		ObjectTree(const std::string& name) : name(name)
//		{
//			SmartConfigManager::Get()->AddTree(this);
//		}
//		ObjectTree(const std::string& name, const std::string& parent) : name(name)
//		{
//			SmartConfigManager::Get()->GetTree(parent)->AddTree(this);
//		}
//
//		void AddTree(ObjectTree* tree)
//		{
//			auto it = trees.find(tree->name);
//			if (it != trees.end())
//			{
//				tree = it->second;
//				delete it->second;
//				trees[tree->name] = tree;
//			}
//			else
//			{
//				trees.insert({ tree->name, tree });
//			}
//		}
//
//		ObjectTree* GetTree(const std::string& name)
//		{
//			auto it = trees.find(name);
//			if (it == trees.end())
//			{
//				AddTree(new ObjectTree(name));
//			}
//			return it->second;
//		}
//
//		void AddObject(Object* object)
//		{
//			content.push_back(object);
//		}
//
//		bool IsTerminal() const { return trees.empty(); }
//
//		ObjectTree* operator =(const ObjectTree*& tree)
//		{
//			name = std::move(tree->name);
//			trees = std::move(tree->trees);
//			content = std::move(tree->content);
//		}
//	};
//
//	void SmartConfigManager::AddTree(ObjectTree* tree)
//	{
//		auto it = trees.find(tree->name);
//		if (it != trees.end())
//		{
//			tree = it->second;
//			delete it->second;
//			trees[tree->name] = tree;
//		}
//		else
//		{
//			trees.insert({ tree->name, tree });
//		}
//	}
//
//	ObjectTree* SmartConfigManager::GetTree(const std::string& name)
//	{
//		auto it = trees.find(name);
//		if (it == trees.end())
//		{
//			AddTree(new ObjectTree(name));
//		}
//		return it->second;
//	}
//
//	class Object
//	{
//	public:
//		std::string name = "";
//		std::string type = "";
//
//		Object(const std::string& name, const std::string& type) : name(name), type(type) {}
//
//		virtual std::string ToString() = 0;
//
//		virtual bool Parse(const std::string& value) = 0;
//	};
//
//	class Boolean : public Object
//	{
//	public:
//		bool value = false;
//
//		Boolean(bool defaultValue = false)
//			: value(defaultValue) {}
//
//		std::string ToString() override
//		{
//			return value ? XOR("true") : XOR("false");
//		}
//
//		bool Parse(const std::string& value) override
//		{
//			return Utils::TryParse(value, this->value);
//		}
//
//		operator bool() const { return value; }
//		bool operator!() const { return !value; }
//	};
//
//	class Integer : public Object
//	{
//	public:
//		int value = 0;
//
//		Integer(int defaultValue = 0)
//			: value(defaultValue) {}
//
//		std::string ToString() override
//		{
//			return Utils::Format(XOR("%d"), value);
//		}
//
//		bool Parse(const std::string& value) override
//		{
//			return Utils::TryParse(value, this->value);
//		}
//
//		operator int() const { return value; }
//	};
//
//	class Single : public Object
//	{
//	public:
//		float value = 0.f;
//
//		Single(float defaultValue = 0.f)
//			: value(defaultValue) {}
//
//		std::string ToString() override
//		{
//			return Utils::Format(XOR("%.2f"), value);
//		}
//
//		bool Parse(const std::string& value) override
//		{
//			return Utils::TryParse(value, this->value);
//		}
//
//		operator float() const { return value; }
//	};
//
//	class String : public Object
//	{
//	public:
//		std::string value = "";
//
//		String(const std::string& defaultValue = "")
//			: value(defaultValue) {}
//
//		std::string ToString() override
//		{
//			return value;
//		}
//
//		bool Parse(const std::string& value) override
//		{
//			this->value = value;
//			return true;
//		}
//
//		operator std::string() const { return value; }
//	};
//
//	class Vector4 : public Object
//	{
//	public:
//		ImVec4 value = ImVec4();
//
//		Vector4(ImVec4 defaultValue = ImVec4())
//			: value(defaultValue) {}
//
//		std::string ToString() override
//		{
//			return Utils::Format(XOR("(%.2f, %.2f, %.2f, %.2f)"), value.x, value.y, value.z, value.w);
//		}
//
//		bool Parse(const std::string& value) override
//		{
//			return Utils::TryParse(value, this->value);
//		}
//
//		operator ImVec4() const { return value; }
//	};
//
//	struct RealConfig : public Singleton<RealConfig>
//	{
//		struct guiReflectionRegister
//		{
//			ObjectTree tree = ObjectTree("gui");
//		} __gui_reflection_register;
//		struct Gui
//		{
//			struct menuReflectionRegister
//			{
//				ObjectTree tree = ObjectTree("menu");
//			} __menu_reflection_register;
//
//			struct Menu
//			{
//
//			};
//		} gui;
//	};
//	SINGLETON_ACTIVATE(RealConfig);
//}

struct RealConfig : public Singleton<RealConfig>
{
	struct Visual
	{
		struct Player
		{
			bool enabled = false;

			struct Box
			{
				bool enabled = false;
				struct Color
				{
					ImVec4 visible = ImVec4(0.f, 0.5f, 0.f, 1.f);
					ImVec4 invisible = ImVec4(0.5f, 0.f, 0.f, 1.f);
				} color;
			} box;
			struct Name
			{
				bool enabled = false;
				ImVec4 color = ImVec4(0.5f, 0.5f, 0.5f, 1.f);
			} name;
			struct Health
			{
				bool enabled = true;
				ImVec4 color = ImVec4(0.f, 0.5f, 0.f, 1.f);
			} health;
			struct Skeleton
			{
				bool enabled = true;
				struct Color
				{
					ImVec4 visible = ImVec4(0.5f, 0.3f, 0.f, 1.f);
					ImVec4 invisible = ImVec4(0.5f, 0.f, 0.f, 1.f);
				} color;
			} skeleton;
		} teammate, enemy;

		struct Hub
		{
			struct Radar
			{
				bool enabled = true;
				float scale = 1.f;

				struct Window
				{
					bool titleBar = false;
					bool background = true;
					float alpha = 1.f;
					bool lockAsNoMenu = true;
				} window;

				struct Style
				{
					enum class ItemType { Circle, Square };
					float itemSize = 2.f;
					ItemType itemType = ItemType::Circle;
				} style;

				struct Player
				{
					bool enabled = true;
					ImVec4 visible = ImVec4(0.f, 0.5f, 0.f, 1.f);
					ImVec4 invisible = ImVec4(0.5f, 0.f, 0.f, 1.f);
				} teammate, enemy;
			} radar;

			struct Watermark
			{
				bool enabled = true;

				struct Window
				{
					bool background = true;
					float alpha = 1.f;
					bool lookAsNoMenu = true;
				} window;

				struct Style
				{
					bool cheatName = true;
					bool time = true;
					std::string timeFormat = XOR("%H:%M:%S");
					bool fps = true;
				} style;
			} watermark;
		} hub;
	} visual;
	struct Gui
	{
		struct Menu
		{
			bool enabled = true;
			struct Cover
			{
				bool enabled = true;
			} cover;
		} menu;
	} gui;
};

class ConfigManager : public Singleton<ConfigManager>
{
public:
	class Pair
	{
	public:
		enum class Type
		{
			Int,
			Float,
			Bool,
			String,
			ImVec4,
			None
		};
		std::string name;
		Type type;
		void* value;

		std::string ToString()
		{
			switch (type) {
			case Type::Int: return Utils::Format(XOR("%d"), *static_cast<int*>(this->value));
			case Type::Float: return Utils::Format(XOR("%.2f"), *static_cast<float*>(this->value));
			case Type::Bool: return *static_cast<bool*>(this->value) ? XOR("true") : XOR("false");
			case Type::String: return *static_cast<std::string*>(this->value);
			case Type::ImVec4: return Utils::Format(XOR("(%.2f, %.2f, %.2f, %.2f)"), static_cast<ImVec4*>(this->value)->x, static_cast<ImVec4*>(this->value)->y, static_cast<ImVec4*>(this->value)->z, static_cast<ImVec4*>(this->value)->w);
			default: return XOR("Unsupported type");
			}
		}
	};

	std::map<std::string, Pair*> pairs = {};

	void Bind(const std::string& name, int* value)
	{
		Pair* pair = new Pair();
		pair->name = name;
		pair->type = Pair::Type::Int;
		pair->value = value;
		pairs.insert({ name, pair });
	}
	void Bind(const std::string& name, float* value)
	{
		Pair* pair = new Pair();
		pair->name = name;
		pair->type = Pair::Type::Float;
		pair->value = value;
		pairs.insert({ name, pair });
	}
	void Bind(const std::string& name, bool* value)
	{
		Pair* pair = new Pair();
		pair->name = name;
		pair->type = Pair::Type::Bool;
		pair->value = value;
		pairs.insert({ name, pair });
	}
	void Bind(const std::string& name, std::string* value)
	{
		Pair* pair = new Pair();
		pair->name = name;
		pair->type = Pair::Type::String;
		pair->value = value;
		pairs.insert({ name, pair });
	}
	void Bind(const std::string& name, ImVec4* value)
	{
		Pair* pair = new Pair();
		pair->name = name;
		pair->type = Pair::Type::ImVec4;
		pair->value = value;
		pairs.insert({ name, pair });
	}

	void Set(const std::string& name, int value)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return;
		}
		auto pair = pairIt->second;
		if (pair->name == name && pair->type == Pair::Type::Int)
		{
			*static_cast<int*>(pair->value) = value;
		}
	}
	void Set(const std::string& name, float value)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return;
		}
		auto pair = pairIt->second;
		if (pair->name == name && pair->type == Pair::Type::Float)
		{
			*static_cast<float*>(pair->value) = value;
		}
	}
	void Set(const std::string& name, bool value)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return;
		}
		auto pair = pairIt->second;
		if (pair->name == name && pair->type == Pair::Type::Bool)
		{
			*static_cast<bool*>(pair->value) = value;
		}
	}
	void Set(const std::string& name, const std::string& value)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return;
		}
		auto pair = pairIt->second;
		if (pair->name == name && pair->type == Pair::Type::String)
		{
			*static_cast<std::string*>(pair->value) = value;
		}
	}
	void Set(const std::string& name, ImVec4 value)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return;
		}
		auto pair = pairIt->second;
		if (pair->name == name && pair->type == Pair::Type::ImVec4)
		{
			*static_cast<ImVec4*>(pair->value) = value;
		}
	}

	template<typename T>
	T GetValue(const std::string& name)
	{
		auto pairIt = pairs.find(name);
		if (pairIt == pairs.end())
		{
			return T();
		}
		auto pair = pairIt->second;
		if (pair->name == name)
		{
			return *static_cast<T*>(pair->value);
		}
		return T();
	}

	std::string GetValueAsString(const std::string& name)
	{
		auto it = pairs.find(name);
		if (it == pairs.end()) return "";

		Pair& pair = *it->second;
		return pair.ToString();
	}

	Pair::Type GetType(const std::string& name)
	{
		auto it = pairs.find(name);
		if (it == pairs.end()) return Pair::Type::None;

		Pair& pair = *it->second;
		return pair.type;
	}

	ConfigManager()
	{
		Bind(XOR("Gui.Menu.Cover.Enabled"), &RealConfig::Get()->gui.menu.cover.enabled);
	}
	~ConfigManager()
	{
		for (auto& [_, pair] : pairs)
		{
			delete pair;
		}
	}

	std::unordered_set<std::string> GetMainSubjects()
	{
		std::unordered_set<std::string> subjects = {};
		for (auto& [name, pair] : pairs)
		{
			std::string subject = name.substr(0, name.find_first_of('.'));
			if (subjects.find(subject) == subjects.end())
			{
				subjects.insert(subject);
			}
		}
		return subjects;
	}

	int GetRank(const std::string& subject)
	{
		return std::count(subject.begin(), subject.end(), '.') + 1;
	}

	std::string SubstrByRank(std::string subject, int rank)
	{
		int count = 0;
		for (int i = 0; i < subject.size(); i++)
		{
			if (subject[i] == '.')
			{
				count++;
			}
			if (count == rank)
			{
				return subject.substr(0, i);
			}
		}
		return subject;
	}

	int GetChildCount(const std::string& subject, int rank = -1)
	{
		int count = 0;
		for (auto& [_, pair] : pairs)
		{
			if (pair->name.substr(0, subject.size()) == subject && pair->name != subject)
			{
				if (rank != -1)
				{
					if (GetRank(pair->name) == rank)
					{
						count++;
					}
				}
				else
				{
					count++;
				}
				count++;
			}
		}
		return count;
	}

	bool IsPenultimateRank(const std::string subject)
	{
		return GetRank(subject) == GetRank(subject.substr(0, subject.find_last_of('.')));
	}

	std::string GetName(const std::string& subject)
	{
		return subject.substr(subject.find_last_of('.') + 1, subject.size());
	}

	std::vector<std::string> GetChildren(const std::string& subject)
	{
		std::vector<std::string> children = {};
		for (auto& [_, pair] : pairs)
		{
			if (pair->name.substr(0, subject.size()) == subject)
			{
				std::string name = SubstrByRank(pair->name, GetRank(subject) + 1);
				if (std::find(children.begin(), children.end(), name) == children.end())
				{
					children.push_back(name);
				}
			}
		}
		return children;
	}

	json Export()
	{
		json j = {};
		for (auto& [name, pair] : pairs)
		{
			switch (pair->type)
			{
			case Pair::Type::Int:
				j[name] = *static_cast<int*>(pair->value);
				break;
			case Pair::Type::Float:
				j[name] = *static_cast<float*>(pair->value);
				break;
			case Pair::Type::Bool:
				j[name] = *static_cast<bool*>(pair->value);
				break;
			case Pair::Type::String:
				j[name] = *static_cast<std::string*>(pair->value);
				break;
			case Pair::Type::ImVec4:
				j[name] = { static_cast<ImVec4*>(pair->value)->x, static_cast<ImVec4*>(pair->value)->y, static_cast<ImVec4*>(pair->value)->z, static_cast<ImVec4*>(pair->value)->w };
				break;
			};
		}
		return j;
	}

	void Import(const json& j)
	{
		for (auto& [name, value] : j.items())
		{
			auto pairIt = pairs.find(name);
			if (pairIt == pairs.end())
			{
				continue;
			}
			auto& pair = pairIt->second;
			switch (pair->type)
			{
			case Pair::Type::Int:
				*static_cast<int*>(pair->value) = value;
				break;
			case Pair::Type::Float:
				*static_cast<float*>(pair->value) = value;
				break;
			case Pair::Type::Bool:
				*static_cast<bool*>(pair->value) = value;
				break;
			case Pair::Type::String:
				*static_cast<std::string*>(pair->value) = value;
				break;
			case Pair::Type::ImVec4:
				*static_cast<ImVec4*>(pair->value) = ImVec4(value[0], value[1], value[2], value[3]);
				break;
			};
		}
	}
};

class ConfigEditor : public Console::CommandBase
{
public:
	ConfigEditor() : Console::CommandBase(XOR("ConfigEditor"), { XOR("[type]"), XOR("[item]"), XOR("[value]{[type]=\"set\"}") }) { }
	class Message : public Console::MessageBase
	{
	public:
		Message(std::string message, ImVec4 messageColor = ImVec4(1.f, 1.f, 1.f, 1.f)) : Console::MessageBase(XOR("[Config Manager]"), message, ImVec4(1.f, 1.f, 1.f, 1.f), messageColor) { }
	};

	void Inquire(std::string key)
	{
		if (key == XOR("__ALL__"))
		{
			for (auto& pair : ConfigManager::Get()->pairs)
			{
				Inquire(pair.first);
			}
			return;
		}
		std::string value = ConfigManager::Get()->GetValueAsString(key);
		if (value.empty())
		{
			Console::Get()->AddMessage(Message(XOR("Invalid key"), ImVec4(1.f, 0.f, 0.f, 1.f)));
			return;
		}
		Console::Get()->AddMessage(Message(Utils::Format(XOR("%s: %s"), key.c_str(), value.c_str())));
	}

	void Set(std::string key, std::string value)
	{
		ConfigManager::Pair::Type type = ConfigManager::Get()->GetType(key);
		if (type == ConfigManager::Pair::Type::None)
		{
			Console::Get()->AddMessage(Message(XOR("Invalid key"), ImVec4(1.f, 0.f, 0.f, 1.f)));
			return;
		}
		if (type == ConfigManager::Pair::Type::Int)
		{
			int intValue = 0;
			if (!Utils::TryParse(value, intValue))
			{
				Console::Get()->AddMessage(Message(XOR("Invalid value"), ImVec4(1.f, 0.f, 0.f, 1.f)));
				return;
			}
			ConfigManager::Get()->Set(key, intValue);
		}
		else if (type == ConfigManager::Pair::Type::Float)
		{
			float floatValue = 0.f;
			if (!Utils::TryParse(value, floatValue))
			{
				Console::Get()->AddMessage(Message(XOR("Invalid value"), ImVec4(1.f, 0.f, 0.f, 1.f)));
				return;
			}
			ConfigManager::Get()->Set(key, floatValue);
		}
		else if (type == ConfigManager::Pair::Type::Bool)
		{
			bool boolValue = false;
			if (!Utils::TryParse(value, boolValue))
			{
				Console::Get()->AddMessage(Message(XOR("Invalid value"), ImVec4(1.f, 0.f, 0.f, 1.f)));
				return;
			}
			ConfigManager::Get()->Set(key, boolValue);
		}
		else if (type == ConfigManager::Pair::Type::String)
		{
			ConfigManager::Get()->Set(key, value);
		}
		else if (type == ConfigManager::Pair::Type::ImVec4)
		{
			ImVec4 vecValue = ImVec4(0.f, 0.f, 0.f, 0.f);
			if (!Utils::TryParse(value, vecValue))
			{
				Console::Get()->AddMessage(Message(XOR("Invalid value"), ImVec4(1.f, 0.f, 0.f, 1.f)));
				return;
			}
			ConfigManager::Get()->Set(key, vecValue);
		}
		Inquire(key);
	}

	void Executer(std::vector<std::string> parameters) override
	{
		if (parameters.size() < 2 || parameters.size() > 3)
		{
			Console::Get()->AddMessage(Message(XOR("Invalid parameters"), ImVec4(1.f, 0.f, 0.f, 1.f)));
			return;
		}
		std::string commandType = parameters[0];
		std::string key = parameters[1];
		if (commandType == XOR("inquire"))
		{
			Inquire(key);
			return;
		}
		else if (commandType == XOR("set"))
		{
			if (parameters.size() != 3)
			{
				Console::Get()->AddMessage(Message(XOR("Invalid parameters"), ImVec4(1.f, 0.f, 0.f, 1.f)));
				return;
			}
			std::string value = parameters[2];
			Set(key, value);
			return;
		}
		Console::Get()->AddMessage(Message(XOR("Invalid command"), ImVec4(1.f, 0.f, 0.f, 1.f)));
	}
};
SINGLETON_ACTIVATE_FAST(ConfigEditor);
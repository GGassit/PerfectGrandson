#pragma once

void ReadMark(const std::string& content)
{
	ImGui::Text(XOR("(?)"));
	if (ImGui::IsItemHovered())
	{
		ImGui::SetTooltip(content.c_str());
	}
}

void BuildPlayerMenuUI(RealConfig::Visual::Player& config)
{
	ImGui::Checkbox(XOR("Enabled"), &config.enabled);
	if (config.enabled)
	{
		ImGui::Checkbox(XOR("Box"), &config.box.enabled);
		if (config.box.enabled)
		{
			ImGui::ColorEdit4(XOR("Visible##Box"), &config.box.color.visible.x);
			ImGui::ColorEdit4(XOR("Invisible##Box"), &config.box.color.invisible.x);
		}
		ImGui::Checkbox(XOR("Name"), &config.name.enabled);
		if (config.name.enabled)
		{
			ImGui::ColorEdit4(XOR("Color##Name"), &config.name.color.x);
		}
		ImGui::Checkbox(XOR("Health"), &config.health.enabled);
		if (config.health.enabled)
		{
			ImGui::ColorEdit4(XOR("Color##Health"), &config.health.color.x);
		}
		ImGui::Checkbox(XOR("Skeleton"), &config.skeleton.enabled);
		if (config.skeleton.enabled)
		{
			ImGui::ColorEdit4(XOR("Visible##Skeleton"), &config.skeleton.color.visible.x);
			ImGui::ColorEdit4(XOR("Invisible##Skeleton"), &config.skeleton.color.invisible.x);
		}
	}
}

CALLBACK(Menu, XOR("ImGui Frame"))
{
	if (ImGui::IsKeyReleased(ImGuiKey_Insert) || (ImGui::IsKeyReleased(ImGuiKey_GamepadBack) && ImGui::IsKeyReleased(ImGuiKey_GamepadStart)))
	{
		RealConfig::Get()->gui.menu.enabled = !RealConfig::Get()->gui.menu.enabled;
		if (RealConfig::Get()->gui.menu.enabled)
		{
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
		}
		else
		{
			ImGui::GetIO().ConfigFlags &= ~ImGuiConfigFlags_NavEnableGamepad;
		}
	}
	if (!RealConfig::Get()->gui.menu.enabled) return;
	ImGui::ShowDemoWindow();
	ImGui::Begin(XOR(PROJECT_NAME " - " GAME_NAME " " VERSION), &RealConfig::Get()->gui.menu.enabled);
	{
		if (ImGui::BeginTabBar("##Features", ImGuiTabBarFlags_NoTooltip))
		{
			if (ImGui::BeginTabItem(XOR("Esp")))
			{
				if (ImGui::BeginTabBar(XOR("##Esp"), ImGuiTabBarFlags_NoTooltip))
				{
					if (ImGui::BeginTabItem(XOR("Player")))
					{
						ImGui::BeginChild(XOR("##Teammate"),
							ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, ImGui::GetContentRegionAvail().y),
							ImGuiChildFlags_FrameStyle);
						{
							ImGui::Text(XOR("Teammate"));
							ImGui::Separator();
							BuildPlayerMenuUI(RealConfig::Get()->visual.teammate);
							ImGui::EndChild();
						}
						ImGui::SameLine();
						ImGui::BeginChild(XOR("##Enemy"),
							ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y),
							ImGuiChildFlags_FrameStyle);
						{
							ImGui::Text(XOR("Enemy"));
							ImGui::Separator();
							BuildPlayerMenuUI(RealConfig::Get()->visual.enemy);
							ImGui::EndChild();
						}
						ImGui::EndTabItem();
					}
					ImGui::EndTabBar();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(XOR("Hub")))
			{
				if (ImGui::BeginTabBar(XOR("##hub"), ImGuiTabBarFlags_NoTooltip))
				{
					if (ImGui::BeginTabItem(XOR("Radar")))
					{
						ImGui::Checkbox(XOR("Enabled"), &RealConfig::Get()->visual.hub.radar.enabled);
						if (RealConfig::Get()->visual.hub.radar.enabled)
						{
							ImGui::SliderFloat(XOR("Scale"), &RealConfig::Get()->visual.hub.radar.scale, 0.1f, 10.f);
							ImGui::BeginChild(
								XOR("##Window"),
								ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Window"));
								ImGui::Separator();
								ImGui::Checkbox(XOR("Title Bar"), &RealConfig::Get()->visual.hub.radar.window.titleBar);
								ImGui::Checkbox(XOR("Background"), &RealConfig::Get()->visual.hub.radar.window.background);
								ImGui::Checkbox(XOR("Lock As Menu Close"), &RealConfig::Get()->visual.hub.radar.window.lockAsNoMenu);
								ImGui::SliderFloat(XOR("Alpha"), &RealConfig::Get()->visual.hub.radar.window.alpha, 0.f, 1.f);
								ImGui::EndChild();
							}
							ImGui::SameLine();
							ImGui::BeginChild(
								XOR("##Style"),
								ImVec2(ImGui::GetContentRegionAvail().x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Style"));
								ImGui::Separator();
								ImGui::SliderFloat(XOR("Item Size"), &RealConfig::Get()->visual.hub.radar.style.itemSize, 1.f, 10.f);
								const char* itemTypes[] = { XOR("Circle"), XOR("Square") };
								ImGui::Combo(XOR("Item Type"), (int*)&RealConfig::Get()->visual.hub.radar.style.itemType, itemTypes, IM_ARRAYSIZE(itemTypes));
								ImGui::EndChild();
							}
							ImGui::BeginChild(
								XOR("##Teammate"),
								ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Teammate"));
								ImGui::Separator();
								ImGui::Checkbox(XOR("Enabled"), &RealConfig::Get()->visual.hub.radar.teammate.enabled);
								if (RealConfig::Get()->visual.hub.radar.teammate.enabled)
								{
									ImGui::ColorEdit4(XOR("Visible##Teammate"), &RealConfig::Get()->visual.hub.radar.teammate.visible.x);
									ImGui::ColorEdit4(XOR("Invisible##Teammate"), &RealConfig::Get()->visual.hub.radar.teammate.invisible.x);
								}
								ImGui::EndChild();
							}
							ImGui::SameLine();
							ImGui::BeginChild(
								XOR("##Enemy"),
								ImVec2(ImGui::GetContentRegionAvail().x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Enemy"));
								ImGui::Separator();
								ImGui::Checkbox(XOR("Enabled"), &RealConfig::Get()->visual.hub.radar.enemy.enabled);
								if (RealConfig::Get()->visual.hub.radar.enemy.enabled)
								{
									ImGui::ColorEdit4(XOR("Visible##Enemy"), &RealConfig::Get()->visual.hub.radar.enemy.visible.x);
									ImGui::ColorEdit4(XOR("Invisible##Enemy"), &RealConfig::Get()->visual.hub.radar.enemy.invisible.x);
								}
								ImGui::EndChild();
							}
						}
						ImGui::EndTabItem();
					}
					if (ImGui::BeginTabItem(XOR("Watermark")))
					{
						ImGui::Checkbox(XOR("Enabled"), &RealConfig::Get()->visual.hub.watermark.enabled);
						if (RealConfig::Get()->visual.hub.watermark.enabled)
						{
							ImGui::BeginChild(
								XOR("##Window"),
								ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Window"));
								ImGui::Separator();
								ImGui::Checkbox(XOR("Background"), &RealConfig::Get()->visual.hub.watermark.window.background);
								ImGui::Checkbox(XOR("Lock As Menu Close"), &RealConfig::Get()->visual.hub.watermark.window.lookAsNoMenu);
								ImGui::SliderFloat(XOR("Alpha"), &RealConfig::Get()->visual.hub.watermark.window.alpha, 0.f, 1.f);
								ImGui::EndChild();
							}
							ImGui::SameLine();
							ImGui::BeginChild(
								XOR("##Style"),
								ImVec2(ImGui::GetContentRegionAvail().x, 0.f),
								ImGuiChildFlags_AutoResizeY | ImGuiChildFlags_FrameStyle
							);
							{
								ImGui::Text(XOR("Style"));
								ImGui::Separator();
								ImGui::Checkbox(XOR("Cheat Name"), &RealConfig::Get()->visual.hub.watermark.style.cheatName);
								ImGui::Checkbox(XOR("Time"), &RealConfig::Get()->visual.hub.watermark.style.time);
								ImGui::AlignTextToFramePadding();
								ImGui::Text(XOR("Time Format:"));
								ImGui::SameLine();
								static std::string timeFormatTemporary = RealConfig::Get()->visual.hub.watermark.style.timeFormat;
								if (timeFormatTemporary != RealConfig::Get()->visual.hub.watermark.style.timeFormat)
								{
									ImGui::AlignTextToFramePadding();
									ReadMark(XOR("Warning! Your game will crash if your time format is wrong!"));
									ImGui::SameLine();
									if (ImGui::Button(XOR("Apply")))
									{
										RealConfig::Get()->visual.hub.watermark.style.timeFormat = timeFormatTemporary;
									}
									ImGui::SameLine();
								}
								ImGui::InputText(XOR("##TimeFormat"), &timeFormatTemporary);
								ImGui::Checkbox(XOR("FPS"), &RealConfig::Get()->visual.hub.watermark.style.fps);
								ImGui::EndChild();
							}
						}
						ImGui::EndTabItem();
					}
					ImGui::EndTabBar();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(XOR("Misc")))
			{
				if (ImGui::Button(XOR("Unload")))
				{
					ImGui::OpenPopup(XOR("Unload"));
				}
				if (ImGui::BeginPopupModal(XOR("Unload"), NULL, ImGuiWindowFlags_AlwaysAutoResize))
				{
					ImGui::Text(XOR("Are you sure you want to unload the cheat?"));
					if (ImGui::Button(XOR("Yes"), ImVec2(120, 0)))
					{
						Application::Get()->Unload();
						ImGui::CloseCurrentPopup();
					}
					ImGui::SameLine();
					if (ImGui::Button(XOR("No"), ImVec2(120, 0)))
					{
						ImGui::CloseCurrentPopup();
					}
					ImGui::EndPopup();
				}
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(XOR("Gui")))
			{
				ImGui::Checkbox(XOR("Menu.Cover"), &RealConfig::Get()->gui.menu.cover.enabled);
				ImGui::EndTabItem();
			}
			if (ImGui::BeginTabItem(XOR("Config")))
			{
				NaPath configDirectory = NaPath((fs::path)NaPath::GetSystemAppDataPath() / PROJECT_NAME / XOR("Config"), NaPath::Type::Directory);
				static std::string configName = XOR("New Config");
				static NaPath currentConfig = {};
				if (!configDirectory.Exists())
				{
					configDirectory.Create();
				}
				if (ImGui::BeginListBox(XOR("##ConfigList"), ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, ImGui::GetContentRegionAvail().y)))
				{
					ImGui::Text(XOR("Config List"));
					ImGui::Separator();
					for (auto& entry : fs::directory_iterator(configDirectory))
					{
						if (entry.path().extension() == XOR(".json"))
						{
							std::string fileName = entry.path().filename().string().substr(0, entry.path().filename().string().size() - 5);
							std::string currentFileName = ((fs::path)currentConfig).filename().string().substr(0, ((fs::path)currentConfig).filename().string().size() - 5);
							if (ImGui::Selectable(fileName.c_str(), currentFileName == fileName))
							{
								configName = fileName;
								currentConfig = entry.path();
							}
						}
					}
					ImGui::EndListBox();
				}
				ImGui::SameLine();
				ImGui::BeginChild(XOR("##Config"), ImVec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y), ImGuiChildFlags_FrameStyle);
				{
					ImGui::Text(XOR("Config Name"));
					ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x);
					ImGui::InputText(XOR("##ConfigName"), &configName);
					if (ImGui::Button(XOR("Create"), ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 30.f)))
					{
						NaPath newConfigPath = configDirectory / (configName + XOR(".json"));
						NaFileWriter writer = NaFileWriter(newConfigPath);
						if (writer.IsOpen())
						{
							writer << ConfigManager::Get()->Export();
						}
						writer.Close();
					}
					ImGui::SameLine();
					if (ImGui::Button(XOR("Remove"), ImVec2(ImGui::GetContentRegionAvail().x, 30.f)))
					{
						NaPath removeConfigPath = configDirectory / (configName + XOR(".json"));
						removeConfigPath.Remove();
					}
					if (ImGui::Button(XOR("Save"), ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 30.f)))
					{
						NaFileWriter writer = NaFileWriter(configDirectory / (configName + XOR(".json")));
						if (writer.IsOpen())
						{
							writer << ConfigManager::Get()->Export();
						}
						writer.Close();
					}
					ImGui::SameLine();
					if (ImGui::Button(XOR("Load"), ImVec2(ImGui::GetContentRegionAvail().x, 30.f)))
					{
						NaFileReader reader = NaFileReader(configDirectory / (configName + XOR(".json")));
						if (reader.IsOpen())
						{
							json json = {};
							reader >> json;
							ConfigManager::Get()->Import(json);
						}
						reader.Close();
					}
					if (ImGui::Button(XOR("Rename"), ImVec2(ImGui::GetContentRegionAvail().x / 2 - ImGui::GetStyle().ItemSpacing.x, 30.f)))
					{
						if (configName.empty())
						{
							configName = XOR("New Config");
						}
						NaPath configPath = configDirectory / (configName + XOR(".json"));
						if (currentConfig.Exists())
						{
							currentConfig.Rename(configPath);
						}
					}
					ImGui::EndChild();
				}
				ImGui::EndTabItem();
			}
			ImGui::EndTabBar();
		}
	}
	ImGui::End();
}
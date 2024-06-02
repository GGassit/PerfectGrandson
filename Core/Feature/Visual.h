#pragma once

namespace Feature
{
	class Esp : public Callback
	{
	public:
		Esp() : Callback(XOR("Feature Runtime")) { }

		void Invoker() override
		{


		}
	};
	SINGLETON_ACTIVATE_FAST(Esp);

	namespace Hub
	{
		class Radar : public Callback
		{
		public:
			ImDrawList* drawList = nullptr;

			Radar() : Callback(XOR("Feature Runtime")) { }

			void Circle(ImVec2 position, bool visible, RealConfig::Visual::Hub::Radar::Player config)
			{
				ImRender->Circle(position,
					RealConfig::Get()->visual.hub.radar.style.itemSize,
					visible ? config.visible : config.invisible, "Outline:true;Fill:true;", drawList);
			}

			void Square(ImVec2 position, bool visible, RealConfig::Visual::Hub::Radar::Player config)
			{
				ImRender->Rect(position - ImVec2(0.5f, 0.5f) * RealConfig::Get()->visual.hub.radar.style.itemSize,
					ImVec2(RealConfig::Get()->visual.hub.radar.style.itemSize, RealConfig::Get()->visual.hub.radar.style.itemSize),
					visible ? config.visible : config.invisible, "Outline:true;Fill:true;", drawList);
			}

			void Invoker() override
			{
				ImGuiWindowFlags flags = NULL;
				if (!RealConfig::Get()->visual.hub.radar.window.titleBar)
					flags |= ImGuiWindowFlags_NoTitleBar;
				if (!RealConfig::Get()->visual.hub.radar.window.background)
					flags |= ImGuiWindowFlags_NoBackground;
				else
					ImGui::SetNextWindowBgAlpha(RealConfig::Get()->visual.hub.radar.window.alpha);
				if (RealConfig::Get()->visual.hub.radar.window.lockAsNoMenu && !RealConfig::Get()->gui.menu.enabled)
					flags |= ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize;

				ImGui::Begin(XOR("Radar"), NULL, flags);
				drawList = ImGui::GetWindowDrawList();
				ImVec2 windowPosition = ImGui::GetWindowPos();
				ImVec2 windowSize = ImGui::GetWindowSize();
				ImVec2 windowCenter = windowPosition + windowSize * 0.5f;

				drawList->AddLine(windowPosition + windowSize * ImVec2(0.f, 0.5f), windowPosition + windowSize * ImVec2(1.f, 0.5f), ImGui::GetColorU32(ImGuiCol_FrameBg));
				drawList->AddLine(windowPosition + windowSize * ImVec2(0.5f, 0.f), windowPosition + windowSize * ImVec2(0.5f, 1.f), ImGui::GetColorU32(ImGuiCol_FrameBg));

				//for (Player p : players)
				//{
				//	RealConfig::Visual::Hub::Radar::Player espConfig = (p.teamId == localPlayer.teamId)
				//		? RealConfig::Get()->visual.hub.radar.teammate
				//		: RealConfig::Get()->visual.hub.radar.enemy;
				//	if (!espConfig.enabled)
				//		continue;

				//	ImVec2 position = ImVec2(p.position.x, p.position.z);

				//	float distance = localPlayer.position.Distance(p.position);

				//	float angle = localPlayer.yaw - atan2f(position.y - localPlayer.position.z, position.x - localPlayer.position.x);

				//	float x = cosf(angle) * distance;
				//	float y = sinf(angle) * distance;

				//	ImVec2 radarPosition = windowCenter + ImVec2(-x, y) * RealConfig::Get()->visual.hub.radar.scale;

				//	switch (RealConfig::Get()->visual.hub.radar.style.itemType)
				//	{
				//	case RealConfig::Visual::Hub::Radar::Style::ItemType::Circle:
				//		Circle(radarPosition, p.visible, espConfig);
				//		break;
				//	case RealConfig::Visual::Hub::Radar::Style::ItemType::Square:
				//		Square(radarPosition, p.visible, espConfig);
				//		break;
				//	default:
				//		break;
				//	}
				//}

				ImGui::End();
			}
		};
		SINGLETON_ACTIVATE_FAST(Radar);

		class Watermark : public Callback
		{
		public:
			Watermark() : Callback(XOR("ImGui Frame")) {}

			std::vector<std::string> watermarkContent = {};

			void AddContent(const std::string& content)
			{
				watermarkContent.push_back(content);
			}

			void Invoker() override
			{
				if (!RealConfig::Get()->visual.hub.watermark.enabled)
					return;

				if (RealConfig::Get()->visual.hub.watermark.style.cheatName)
				{
					AddContent(XOR(PROJECT_NAME));
					AddContent(XOR(VERSION));
				}
				if (RealConfig::Get()->visual.hub.watermark.style.time)
				{
					AddContent(Utils::Format(XOR("%s"), NaTime::Now().ToString(RealConfig::Get()->visual.hub.watermark.style.timeFormat).c_str()));
				}
				if (RealConfig::Get()->visual.hub.watermark.style.fps)
				{
					AddContent(Utils::Format(XOR("%.1f"), ImGui::GetIO().Framerate));
				}

				ImGuiWindowFlags flags = NULL;
				if (RealConfig::Get()->visual.hub.watermark.window.lookAsNoMenu && !RealConfig::Get()->gui.menu.enabled)
					flags |= ImGuiWindowFlags_NoMove;

				ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
				ImGui::Begin(XOR("Watermark"), NULL, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | flags);
				for (size_t i = 0; i < watermarkContent.size(); i++)
				{
					ImGui::Text(XOR("%s"), watermarkContent[i].c_str());
					if (i != watermarkContent.size() - 1)
					{
						ImGui::SameLine();
						ImGui::SeparatorEx(ImGuiSeparatorFlags_Vertical);
						ImGui::SameLine();
					}
				}
				ImGui::End();

				watermarkContent.clear();
			}
		};
		SINGLETON_ACTIVATE_FAST(Watermark);
	}
}
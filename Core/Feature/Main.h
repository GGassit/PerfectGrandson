#pragma once

namespace Feature
{
	using namespace SDK;

	namespace Package
	{
		struct Object
		{

		};

		UEngine* engine = nullptr;
		UWorld* world = nullptr;
		UGameInstance* gameInstance = nullptr;
		UPlayer* localPlayer = nullptr;
		APlayerController* localPlayerController = nullptr;

		void Clear()
		{
			gameInstance = nullptr;
			localPlayer = nullptr;
			localPlayerController = nullptr;
		}
	}
	using namespace Package;

	DISPOSABLE_CALLBACK(BasicDataInitialize, XOR("Dll Initialize"))
	{
		engine = UEngine::GetEngine();

		world =UWorld::GetWorld();
	}

	CALLBACK(MainLoop, XOR("ImGui Frame"))
	{
		ImRender->Loop();
		if (IsBadPtr(engine))
			return;
		if (IsBadPtr(world))
			return;
		gameInstance = world->OwningGameInstance;
		if (IsBadPtr(gameInstance))
			return;
		localPlayer = gameInstance->LocalPlayers[0];
		if (IsBadPtr(localPlayer))
			return;		
		localPlayerController = localPlayer->PlayerController;
		if (IsBadPtr(localPlayerController))
			return;
		const auto& levels = world->Levels;
		if (levels.IsValid())
			return;
		for (const auto& level : levels)
		{
			if (IsBadPtr(level))
				continue;
			const auto& actors = level->Actors;
			for (const auto& actor : actors)
			{
				if (IsBadPtr(actor))
					continue;
				FVector location = actor->K2_GetActorLocation();
				FVector2D screenPosition = FVector2D();
				if (!UGameplayStatics::ProjectWorldToScreen(localPlayerController, location, &screenPosition, false))
					continue;
				ImRender->Text(Utils::Format(XOR("%s (0x%p)"), actor->GetFullName().c_str(), actor)
					, ImVec2(screenPosition.X, screenPosition.Y), ImVec4(1.f, 1.f, 1.f, 1.f), XOR("Outline:true;Horizontal:center;"));
			}
		}
		CallbackManager::Get()->Invoke(XOR("Feature Runtime"));
		Clear();
	}
}
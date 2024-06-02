#pragma once

// Application singleton won't attend the destruction process invoked by manager
// Because it stored the most essential data as key of unloading, local module
struct Application : Singleton<Application, true>
{
	struct Internal
	{
		bool unload = false;
		HMODULE module = NULL;
		HWND window = NULL;

		Internal() = default;
		
		Internal(HMODULE localModule) : module(localModule) {}
	} internal;

	struct Renderer
	{
		ID3D11Device* device = nullptr;
	} renderer;

	void Unload()
	{
		internal.unload = true;
	}

	Application() = default;

	Application(HMODULE module) : internal(module) {}
};
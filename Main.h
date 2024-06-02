#pragma once

#define FRAMEWORK_VERSION 1_2_2
// Perfect Hack Development Framework Update Log:
// (2024/5/29) 1_2_2:
//	1. Add some internal feature template
// (2024/5/29) 1_2_1:
//	1. Add a resource manager
//	2. Add a internal font
//	3. Adjust the struct of callback system
//  4. Add a lot of internal commands
//	5. Remove the unusable functions
// (2024/5/27) 1_2_0:
//	1. Re-struct callback system
//	2. Adjust the struct of dll main and re-distribute the function of part of main
//	3. Add new condition to IsBadPtr

// Version TODO:
// (2024/5/31) 1_2_2:
// 1. Fixup the bug of coving and callup the mouse
// (2024/5/29) 1_2_1:
// 1. Error handle system
// 2. Anti-Anti-Cheat system
//		- Spoof_Call
//			- Develop
//			- Apply the SpoofCall
//		- Hide the memory of module
// 3. Develop smart config system
//		- Config reflection system
// 4. Fixup the bug from Console
//		- In ParseInput, command name parsing with Quotes is wrong
// 5. Add internet module

#include <Windows.h>
#include <d3d11.h>
#include <thread>
#include <regex>
#include <unordered_set>
#include <map>

#include "Resource/resource.h"

#define IMGUI_DEFINE_MATH_OPERATORS


#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/imgui_impl_win32.h>
#include <ImGui/misc/cpp/imgui_stdlib.h>

#include <XorString/XorString.h>
#include <MinHook/MinHook.h>

#include <ImRender/ImRender.h>

#include <Json/json.h>
using namespace nlohmann;

#include <SDK/SDK.hpp>

#include <NaLibrary/NaLibrary.h>

#include "Core/Feature/Utils.h"

#include "Core/Manager/SingletonManager.h"
#include "Core/Manager/CallbackManager.h"

#include "Core/Safety/SpoofCall/SpoofCall.h"

#include "Core/Manager/Application.h"
#include "Core/Manager/ResourceManager.h"
#include "Core/Manager/HookManager.h"
#include "Core/Manager/Console.h"
#include "Core/Manager/Config.h"

inline extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND window, UINT message, WPARAM wideParam, LPARAM longParam);

#define IsBadPtr(ptr) ((ptr) == nullptr ? true : (\
	(IsBadReadPtr((void*)(ptr), sizeof((ptr)))) \
	|| ((uintptr_t)(ptr) < 0x10000) \
	|| ((uintptr_t)(ptr) > 0x00007FFFFFFEFFFF) \
	|| (((uintptr_t)(ptr) & 0x1) != 0)))

#define PROJECT_NAME "PerfectXXX"
#define GAME_NAME "XXX"
#define VERSION "v1.0.0"

#include"Dependence/SDK/SDK.hpp"
#include "Core/Feature/Main.h"
#include "Core/Feature/Visual.h"
#include "Core/Feature/Aimbot.h"

#include "Core/GUI/Menu.h"
#include "Core/GUI/WinUser.h"
#include "Core/GUI/dxgi.h"




#pragma once

namespace WinUser
{
	HOOK(HCURSOR, SetCursor, HCURSOR hCursor)
	{
		if (Application::Get()->internal.unload)
			return oSetCursor(hCursor);
		if (RealConfig::Get()->gui.menu.enabled && RealConfig::Get()->gui.menu.cover.enabled)
			return NULL;
		return oSetCursor(hCursor);
	}
	
	HOOK(BOOL, SetCursorPos, int X, int Y)
	{
		if (Application::Get()->internal.unload)
			return oSetCursorPos(X, Y);
		if (RealConfig::Get()->gui.menu.enabled && RealConfig::Get()->gui.menu.cover.enabled)
			return FALSE;
		return oSetCursorPos(X, Y);
	}
}
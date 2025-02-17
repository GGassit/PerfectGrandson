#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_WidgetBase

#include "Basic.hpp"

#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WBP_WidgetBase.WBP_WidgetBase_C
// 0x0000 (0x0278 - 0x0278)
class UWBP_WidgetBase_C : public UUserWidget
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WBP_WidgetBase_C">();
	}
	static class UWBP_WidgetBase_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWBP_WidgetBase_C>();
	}
};
static_assert(alignof(UWBP_WidgetBase_C) == 0x000008, "Wrong alignment on UWBP_WidgetBase_C");
static_assert(sizeof(UWBP_WidgetBase_C) == 0x000278, "Wrong size on UWBP_WidgetBase_C");

}


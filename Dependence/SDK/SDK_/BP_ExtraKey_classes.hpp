#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ExtraKey

#include "Basic.hpp"

#include "BP_ItemBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ExtraKey.BP_ExtraKey_C
// 0x0000 (0x03F0 - 0x03F0)
class ABP_ExtraKey_C final : public ABP_ItemBase_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ExtraKey_C">();
	}
	static class ABP_ExtraKey_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ExtraKey_C>();
	}
};
static_assert(alignof(ABP_ExtraKey_C) == 0x000010, "Wrong alignment on ABP_ExtraKey_C");
static_assert(sizeof(ABP_ExtraKey_C) == 0x0003F0, "Wrong size on ABP_ExtraKey_C");

}


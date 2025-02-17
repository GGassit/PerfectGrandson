#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ScreamerShake

#include "Basic.hpp"

#include "GameplayCameras_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ScreamerShake.ScreamerShake_C
// 0x0000 (0x0210 - 0x0210)
class UScreamerShake_C final : public ULegacyCameraShake
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ScreamerShake_C">();
	}
	static class UScreamerShake_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UScreamerShake_C>();
	}
};
static_assert(alignof(UScreamerShake_C) == 0x000010, "Wrong alignment on UScreamerShake_C");
static_assert(sizeof(UScreamerShake_C) == 0x000210, "Wrong size on UScreamerShake_C");

}


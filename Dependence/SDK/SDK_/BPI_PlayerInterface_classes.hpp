#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BPI_PlayerInterface

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BPI_PlayerInterface.BPI_PlayerInterface_C
// 0x0000 (0x0028 - 0x0028)
class IBPI_PlayerInterface_C final : public IInterface
{
public:
	void Use(class ABP_Player_C* Player, bool Start);
	void InteractEnd(class ABP_Player_C* Player);
	void InteractCanceled(class ABP_Player_C* Player);
	void Interact(class ABP_Player_C* Player, const struct FHitResult& Hit);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BPI_PlayerInterface_C">();
	}
	static class IBPI_PlayerInterface_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IBPI_PlayerInterface_C>();
	}
};
static_assert(alignof(IBPI_PlayerInterface_C) == 0x000008, "Wrong alignment on IBPI_PlayerInterface_C");
static_assert(sizeof(IBPI_PlayerInterface_C) == 0x000028, "Wrong size on IBPI_PlayerInterface_C");

}


#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LVL_Intro

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass LVL_Intro.LVL_Intro_C
// 0x0028 (0x02C0 - 0x0298)
class ALVL_Intro_C final : public ALevelScriptActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0298(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FVector                                NewVar;                                            // 0x02A0(0x0018)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ATargetPoint*                           TargetPoint_1_ExecuteUbergraph_LVL_Intro_RefProperty; // 0x02B8(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)

public:
	void ReceiveBeginPlay();
	void ExecuteUbergraph_LVL_Intro(int32 EntryPoint);
	void CustomEvent();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LVL_Intro_C">();
	}
	static class ALVL_Intro_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ALVL_Intro_C>();
	}
};
static_assert(alignof(ALVL_Intro_C) == 0x000008, "Wrong alignment on ALVL_Intro_C");
static_assert(sizeof(ALVL_Intro_C) == 0x0002C0, "Wrong size on ALVL_Intro_C");
static_assert(offsetof(ALVL_Intro_C, UberGraphFrame) == 0x000298, "Member 'ALVL_Intro_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(ALVL_Intro_C, NewVar) == 0x0002A0, "Member 'ALVL_Intro_C::NewVar' has a wrong offset!");
static_assert(offsetof(ALVL_Intro_C, TargetPoint_1_ExecuteUbergraph_LVL_Intro_RefProperty) == 0x0002B8, "Member 'ALVL_Intro_C::TargetPoint_1_ExecuteUbergraph_LVL_Intro_RefProperty' has a wrong offset!");

}


#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LVL_Intro

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function LVL_Intro.LVL_Intro_C.ExecuteUbergraph_LVL_Intro
// 0x0170 (0x0170 - 0x0000)
struct LVL_Intro_C_ExecuteUbergraph_LVL_Intro final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_27F7[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0008(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Conv_FloatToVector_ReturnValue;           // 0x0020(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_RandomUnitVector_ReturnValue;             // 0x0038(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Multiply_VectorVector_ReturnValue;        // 0x0050(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Add_VectorVector_ReturnValue;             // 0x0068(0x0018)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FHitResult                             CallFunc_K2_SetActorLocation_SweepHitResult;       // 0x0080(0x00E8)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	bool                                          CallFunc_K2_SetActorLocation_ReturnValue;          // 0x0168(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro) == 0x000008, "Wrong alignment on LVL_Intro_C_ExecuteUbergraph_LVL_Intro");
static_assert(sizeof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro) == 0x000170, "Wrong size on LVL_Intro_C_ExecuteUbergraph_LVL_Intro");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, EntryPoint) == 0x000000, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::EntryPoint' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000008, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_Conv_FloatToVector_ReturnValue) == 0x000020, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_Conv_FloatToVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_RandomUnitVector_ReturnValue) == 0x000038, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_RandomUnitVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_Multiply_VectorVector_ReturnValue) == 0x000050, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_Multiply_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_Add_VectorVector_ReturnValue) == 0x000068, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_Add_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_K2_SetActorLocation_SweepHitResult) == 0x000080, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_K2_SetActorLocation_SweepHitResult' has a wrong offset!");
static_assert(offsetof(LVL_Intro_C_ExecuteUbergraph_LVL_Intro, CallFunc_K2_SetActorLocation_ReturnValue) == 0x000168, "Member 'LVL_Intro_C_ExecuteUbergraph_LVL_Intro::CallFunc_K2_SetActorLocation_ReturnValue' has a wrong offset!");

}


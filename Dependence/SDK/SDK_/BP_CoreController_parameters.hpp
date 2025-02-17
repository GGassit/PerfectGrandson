#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_CoreController

#include "Basic.hpp"

#include "InputCore_structs.hpp"


namespace SDK::Params
{

// Function BP_CoreController.BP_CoreController_C.InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0
// 0x0018 (0x0018 - 0x0000)
struct BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0 final
{
public:
	struct FKey                                   Key;                                               // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
};
static_assert(alignof(BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0) == 0x000008, "Wrong alignment on BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0");
static_assert(sizeof(BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0) == 0x000018, "Wrong size on BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0");
static_assert(offsetof(BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0, Key) == 0x000000, "Member 'BP_CoreController_C_InpActEvt_Shift_Tilde_K2Node_InputKeyEvent_0::Key' has a wrong offset!");

// Function BP_CoreController.BP_CoreController_C.ExecuteUbergraph_BP_CoreController
// 0x0038 (0x0038 - 0x0000)
struct BP_CoreController_C_ExecuteUbergraph_BP_CoreController final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2580[0x4];                                     // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AHUD*                                   CallFunc_GetHUD_ReturnValue;                       // 0x0008(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	class ABP_CoreHUD_C*                          K2Node_DynamicCast_AsBP_Core_HUD;                  // 0x0010(0x0008)(ZeroConstructor, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2581[0x7];                                     // 0x0019(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FKey                                   K2Node_InputKeyEvent_Key;                          // 0x0020(0x0018)(HasGetValueTypeHash)
};
static_assert(alignof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController) == 0x000008, "Wrong alignment on BP_CoreController_C_ExecuteUbergraph_BP_CoreController");
static_assert(sizeof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController) == 0x000038, "Wrong size on BP_CoreController_C_ExecuteUbergraph_BP_CoreController");
static_assert(offsetof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController, EntryPoint) == 0x000000, "Member 'BP_CoreController_C_ExecuteUbergraph_BP_CoreController::EntryPoint' has a wrong offset!");
static_assert(offsetof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController, CallFunc_GetHUD_ReturnValue) == 0x000008, "Member 'BP_CoreController_C_ExecuteUbergraph_BP_CoreController::CallFunc_GetHUD_ReturnValue' has a wrong offset!");
static_assert(offsetof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController, K2Node_DynamicCast_AsBP_Core_HUD) == 0x000010, "Member 'BP_CoreController_C_ExecuteUbergraph_BP_CoreController::K2Node_DynamicCast_AsBP_Core_HUD' has a wrong offset!");
static_assert(offsetof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'BP_CoreController_C_ExecuteUbergraph_BP_CoreController::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(BP_CoreController_C_ExecuteUbergraph_BP_CoreController, K2Node_InputKeyEvent_Key) == 0x000020, "Member 'BP_CoreController_C_ExecuteUbergraph_BP_CoreController::K2Node_InputKeyEvent_Key' has a wrong offset!");

}


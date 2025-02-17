#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_RemoteDoor

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BP_InteractableBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_RemoteDoor.BP_RemoteDoor_C
// 0x0048 (0x0338 - 0x02F0)
class ABP_RemoteDoor_C final : public ABP_InteractableBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_BP_RemoteDoor_C;                    // 0x02F0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UBoxComponent*                          Box;                                               // 0x02F8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   SM_RemoteDoor_Cube_001;                            // 0x0300(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh1;                                       // 0x0308(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_NewTrack_0_3067BB2A482F51FB2AB925BB18FA4D75; // 0x0318(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline__Direction_3067BB2A482F51FB2AB925BB18FA4D75; // 0x031C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_253D[0x3];                                     // 0x031D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline;                                          // 0x0320(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	bool                                          Opened;                                            // 0x0328(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_253E[0x7];                                     // 0x0329(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               NewVar_0;                                          // 0x0330(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void Timeline__UpdateFunc();
	void Timeline__FinishedFunc();
	void ReceiveBeginPlay();
	void Open();
	void Interact(class ABP_Player_C* Player, const struct FHitResult& Hit);
	void ExecuteUbergraph_BP_RemoteDoor(int32 EntryPoint);
	void ChangeLampColor();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_RemoteDoor_C">();
	}
	static class ABP_RemoteDoor_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_RemoteDoor_C>();
	}
};
static_assert(alignof(ABP_RemoteDoor_C) == 0x000008, "Wrong alignment on ABP_RemoteDoor_C");
static_assert(sizeof(ABP_RemoteDoor_C) == 0x000338, "Wrong size on ABP_RemoteDoor_C");
static_assert(offsetof(ABP_RemoteDoor_C, UberGraphFrame_BP_RemoteDoor_C) == 0x0002F0, "Member 'ABP_RemoteDoor_C::UberGraphFrame_BP_RemoteDoor_C' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, Box) == 0x0002F8, "Member 'ABP_RemoteDoor_C::Box' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, SM_RemoteDoor_Cube_001) == 0x000300, "Member 'ABP_RemoteDoor_C::SM_RemoteDoor_Cube_001' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, StaticMesh1) == 0x000308, "Member 'ABP_RemoteDoor_C::StaticMesh1' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, StaticMesh) == 0x000310, "Member 'ABP_RemoteDoor_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, Timeline_NewTrack_0_3067BB2A482F51FB2AB925BB18FA4D75) == 0x000318, "Member 'ABP_RemoteDoor_C::Timeline_NewTrack_0_3067BB2A482F51FB2AB925BB18FA4D75' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, Timeline__Direction_3067BB2A482F51FB2AB925BB18FA4D75) == 0x00031C, "Member 'ABP_RemoteDoor_C::Timeline__Direction_3067BB2A482F51FB2AB925BB18FA4D75' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, Timeline) == 0x000320, "Member 'ABP_RemoteDoor_C::Timeline' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, Opened) == 0x000328, "Member 'ABP_RemoteDoor_C::Opened' has a wrong offset!");
static_assert(offsetof(ABP_RemoteDoor_C, NewVar_0) == 0x000330, "Member 'ABP_RemoteDoor_C::NewVar_0' has a wrong offset!");

}


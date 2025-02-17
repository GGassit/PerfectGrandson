#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_MainDoor

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BP_InteractableBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_MainDoor.BP_MainDoor_C
// 0x0048 (0x0338 - 0x02F0)
class ABP_MainDoor_C final : public ABP_InteractableBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_BP_MainDoor_C;                      // 0x02F0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class USceneComponent*                        Scene2;                                            // 0x02F8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   DoubleDoor_SM_DoorPart;                            // 0x0300(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Scene1;                                            // 0x0308(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   DoubleDoor_SM_DoorPart1;                           // 0x0310(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USceneComponent*                        Scene;                                             // 0x0318(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_NewTrack_0_1AC6A2DF477D02B73494AFBB70170887; // 0x0320(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline__Direction_1AC6A2DF477D02B73494AFBB70170887; // 0x0324(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2552[0x3];                                     // 0x0325(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline;                                          // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
	bool                                          Woods;                                             // 0x0330(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Power;                                             // 0x0331(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Code;                                              // 0x0332(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DoorOpend;                                         // 0x0333(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ExtraLock;                                         // 0x0334(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Woods2;                                            // 0x0335(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Extra1;                                            // 0x0336(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Timeline__UpdateFunc();
	void Timeline__FinishedFunc();
	void SpawnExtraLock();
	void ReceiveTick(float DeltaSeconds);
	void Not(const class FText& WriteText);
	void Interact(class ABP_Player_C* Player, const struct FHitResult& Hit);
	void ExecuteUbergraph_BP_MainDoor(int32 EntryPoint);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_MainDoor_C">();
	}
	static class ABP_MainDoor_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_MainDoor_C>();
	}
};
static_assert(alignof(ABP_MainDoor_C) == 0x000008, "Wrong alignment on ABP_MainDoor_C");
static_assert(sizeof(ABP_MainDoor_C) == 0x000338, "Wrong size on ABP_MainDoor_C");
static_assert(offsetof(ABP_MainDoor_C, UberGraphFrame_BP_MainDoor_C) == 0x0002F0, "Member 'ABP_MainDoor_C::UberGraphFrame_BP_MainDoor_C' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Scene2) == 0x0002F8, "Member 'ABP_MainDoor_C::Scene2' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, DoubleDoor_SM_DoorPart) == 0x000300, "Member 'ABP_MainDoor_C::DoubleDoor_SM_DoorPart' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Scene1) == 0x000308, "Member 'ABP_MainDoor_C::Scene1' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, DoubleDoor_SM_DoorPart1) == 0x000310, "Member 'ABP_MainDoor_C::DoubleDoor_SM_DoorPart1' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Scene) == 0x000318, "Member 'ABP_MainDoor_C::Scene' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Timeline_NewTrack_0_1AC6A2DF477D02B73494AFBB70170887) == 0x000320, "Member 'ABP_MainDoor_C::Timeline_NewTrack_0_1AC6A2DF477D02B73494AFBB70170887' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Timeline__Direction_1AC6A2DF477D02B73494AFBB70170887) == 0x000324, "Member 'ABP_MainDoor_C::Timeline__Direction_1AC6A2DF477D02B73494AFBB70170887' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Timeline) == 0x000328, "Member 'ABP_MainDoor_C::Timeline' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Woods) == 0x000330, "Member 'ABP_MainDoor_C::Woods' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Power) == 0x000331, "Member 'ABP_MainDoor_C::Power' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Code) == 0x000332, "Member 'ABP_MainDoor_C::Code' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, DoorOpend) == 0x000333, "Member 'ABP_MainDoor_C::DoorOpend' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, ExtraLock) == 0x000334, "Member 'ABP_MainDoor_C::ExtraLock' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Woods2) == 0x000335, "Member 'ABP_MainDoor_C::Woods2' has a wrong offset!");
static_assert(offsetof(ABP_MainDoor_C, Extra1) == 0x000336, "Member 'ABP_MainDoor_C::Extra1' has a wrong offset!");

}


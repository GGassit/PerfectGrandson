#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NamedSlider

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "WBP_WidgetBase_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass NamedSlider.NamedSlider_C
// 0x0110 (0x0388 - 0x0278)
class UNamedSlider_C final : public UWBP_WidgetBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0278(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UButton*                                Button_73;                                         // 0x0280(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           CanvasPanel_0;                                     // 0x0288(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           CanvasPanel_199;                                   // 0x0290(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UClickableText_C*                       ClickableText;                                     // 0x0298(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image;                                             // 0x02A0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_94;                                          // 0x02A8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 Image_165;                                         // 0x02B0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOverlay*                               Overlay_0;                                         // 0x02B8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UProgressBar*                           ProgressBar_67;                                    // 0x02C0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class URetainerBox*                           RetainerBox_0;                                     // 0x02C8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USlider*                                Slider_110;                                        // 0x02D0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TextBlock;                                         // 0x02D8(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TextBlock_161;                                     // 0x02E0(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, InstancedReference, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          Editing;                                           // 0x02E8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_285A[0x7];                                     // 0x02E9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UMaterialInstanceDynamic*               HighlightMaterialUp;                               // 0x02F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               HighlightMaterialDown;                             // 0x02F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              NormalizedMousePositionOnWidget;                   // 0x0300(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        Value;                                             // 0x0310(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x0318(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	float                                         Percent;                                           // 0x0330(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_285B[0x4];                                     // 0x0334(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	double                                        TextPositionAdd;                                   // 0x0338(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        MinValue;                                          // 0x0340(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        MaxValue;                                          // 0x0348(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	double                                        StepSize;                                          // 0x0350(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MouseUsesStep;                                     // 0x0358(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_285C[0x7];                                     // 0x0359(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 AppendToValue;                                     // 0x0360(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	FMulticastInlineDelegateProperty_             OnValueChanged;                                    // 0x0370(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	int32                                         Maximum_Fractional_Digits;                         // 0x0380(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void SetPercent(double Param_Percent);
	void SelectionHighlightController();
	void PreConstruct(bool IsDesignTime);
	void OnValueChanged__DelegateSignature(double Param_Value, double Param_Percent);
	void ExecuteUbergraph_NamedSlider(int32 EntryPoint);
	void Construct();
	void CheckHandle();
	void BndEvt__NamedSlider_Slider_110_K2Node_ComponentBoundEvent_2_OnMouseCaptureEndEvent__DelegateSignature();
	void BndEvt__NamedSlider_Slider_110_K2Node_ComponentBoundEvent_1_OnMouseCaptureBeginEvent__DelegateSignature();
	void BndEvt__NamedSlider_Slider_110_K2Node_ComponentBoundEvent_0_OnFloatValueChangedEvent__DelegateSignature(float Param_Value);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"NamedSlider_C">();
	}
	static class UNamedSlider_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UNamedSlider_C>();
	}
};
static_assert(alignof(UNamedSlider_C) == 0x000008, "Wrong alignment on UNamedSlider_C");
static_assert(sizeof(UNamedSlider_C) == 0x000388, "Wrong size on UNamedSlider_C");
static_assert(offsetof(UNamedSlider_C, UberGraphFrame) == 0x000278, "Member 'UNamedSlider_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Button_73) == 0x000280, "Member 'UNamedSlider_C::Button_73' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, CanvasPanel_0) == 0x000288, "Member 'UNamedSlider_C::CanvasPanel_0' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, CanvasPanel_199) == 0x000290, "Member 'UNamedSlider_C::CanvasPanel_199' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, ClickableText) == 0x000298, "Member 'UNamedSlider_C::ClickableText' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Image) == 0x0002A0, "Member 'UNamedSlider_C::Image' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Image_94) == 0x0002A8, "Member 'UNamedSlider_C::Image_94' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Image_165) == 0x0002B0, "Member 'UNamedSlider_C::Image_165' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Overlay_0) == 0x0002B8, "Member 'UNamedSlider_C::Overlay_0' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, ProgressBar_67) == 0x0002C0, "Member 'UNamedSlider_C::ProgressBar_67' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, RetainerBox_0) == 0x0002C8, "Member 'UNamedSlider_C::RetainerBox_0' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Slider_110) == 0x0002D0, "Member 'UNamedSlider_C::Slider_110' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, TextBlock) == 0x0002D8, "Member 'UNamedSlider_C::TextBlock' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, TextBlock_161) == 0x0002E0, "Member 'UNamedSlider_C::TextBlock_161' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Editing) == 0x0002E8, "Member 'UNamedSlider_C::Editing' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, HighlightMaterialUp) == 0x0002F0, "Member 'UNamedSlider_C::HighlightMaterialUp' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, HighlightMaterialDown) == 0x0002F8, "Member 'UNamedSlider_C::HighlightMaterialDown' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, NormalizedMousePositionOnWidget) == 0x000300, "Member 'UNamedSlider_C::NormalizedMousePositionOnWidget' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Value) == 0x000310, "Member 'UNamedSlider_C::Value' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Text) == 0x000318, "Member 'UNamedSlider_C::Text' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Percent) == 0x000330, "Member 'UNamedSlider_C::Percent' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, TextPositionAdd) == 0x000338, "Member 'UNamedSlider_C::TextPositionAdd' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, MinValue) == 0x000340, "Member 'UNamedSlider_C::MinValue' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, MaxValue) == 0x000348, "Member 'UNamedSlider_C::MaxValue' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, StepSize) == 0x000350, "Member 'UNamedSlider_C::StepSize' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, MouseUsesStep) == 0x000358, "Member 'UNamedSlider_C::MouseUsesStep' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, AppendToValue) == 0x000360, "Member 'UNamedSlider_C::AppendToValue' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, OnValueChanged) == 0x000370, "Member 'UNamedSlider_C::OnValueChanged' has a wrong offset!");
static_assert(offsetof(UNamedSlider_C, Maximum_Fractional_Digits) == 0x000380, "Member 'UNamedSlider_C::Maximum_Fractional_Digits' has a wrong offset!");

}


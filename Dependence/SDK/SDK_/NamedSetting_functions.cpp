#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: NamedSetting

#include "Basic.hpp"

#include "NamedSetting_classes.hpp"
#include "NamedSetting_parameters.hpp"


namespace SDK
{

// Function NamedSetting.NamedSetting_C.ValueToText
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ESettingLevel                           Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FText                             Param_Text                                             (Parm, OutParm)

void UNamedSetting_C::ValueToText(ESettingLevel Param_Index, class FText* Param_Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "ValueToText");

	Params::NamedSetting_C_ValueToText Parms{};

	Parms.Param_Index = Param_Index;

	UObject::ProcessEvent(Func, &Parms);

	if (Param_Text != nullptr)
		*Param_Text = std::move(Parms.Param_Text);
}


// Function NamedSetting.NamedSetting_C.Tick
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// float                                   InDeltaTime                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::Tick(const struct FGeometry& MyGeometry, float InDeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "Tick");

	Params::NamedSetting_C_Tick Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.InDeltaTime = InDeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.SettingInit
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UNamedSetting_C::SettingInit()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "SettingInit");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.SettingApply
// (Public, BlueprintCallable, BlueprintEvent)

void UNamedSetting_C::SettingApply()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "SettingApply");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.SelectionHighlightController
// (Public, BlueprintCallable, BlueprintEvent)

void UNamedSetting_C::SelectionHighlightController()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "SelectionHighlightController");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.ReturnLevel_Event
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class USettingPopup_C*                  Widget                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)
// ESettingLevel                           Level                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::ReturnLevel_Event(class USettingPopup_C* Widget, ESettingLevel Level)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "ReturnLevel_Event");

	Params::NamedSetting_C_ReturnLevel_Event Parms{};

	Parms.Widget = Widget;
	Parms.Level = Level;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.ResetCaller
// (BlueprintCallable, BlueprintEvent)

void UNamedSetting_C::ResetCaller()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "ResetCaller");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "PreConstruct");

	Params::NamedSetting_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.OnValueChanged__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// double                                  Value                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// double                                  Percent                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::OnValueChanged__DelegateSignature(double Value, double Percent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "OnValueChanged__DelegateSignature");

	Params::NamedSetting_C_OnValueChanged__DelegateSignature Parms{};

	Parms.Value = Value;
	Parms.Percent = Percent;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.ExecuteUbergraph_NamedSetting
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::ExecuteUbergraph_NamedSetting(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "ExecuteUbergraph_NamedSetting");

	Params::NamedSetting_C_ExecuteUbergraph_NamedSetting Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UNamedSetting_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.CheckHandle
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UNamedSetting_C::CheckHandle()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "CheckHandle");

	UObject::ProcessEvent(Func, nullptr);
}


// Function NamedSetting.NamedSetting_C.CallPopup
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_NearMainText                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::CallPopup(bool Param_NearMainText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "CallPopup");

	Params::NamedSetting_C_CallPopup Parms{};

	Parms.Param_NearMainText = Param_NearMainText;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.BndEvt__NamedSetting_HighSetting_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UClickableText_C*                 Param_Text                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::BndEvt__NamedSetting_HighSetting_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature(class UClickableText_C* Param_Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "BndEvt__NamedSetting_HighSetting_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature");

	Params::NamedSetting_C_BndEvt__NamedSetting_HighSetting_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature Parms{};

	Parms.Param_Text = Param_Text;

	UObject::ProcessEvent(Func, &Parms);
}


// Function NamedSetting.NamedSetting_C.BndEvt__NamedSetting_ClickableText_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UClickableText_C*                 Param_Text                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void UNamedSetting_C::BndEvt__NamedSetting_ClickableText_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature(class UClickableText_C* Param_Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("NamedSetting_C", "BndEvt__NamedSetting_ClickableText_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature");

	Params::NamedSetting_C_BndEvt__NamedSetting_ClickableText_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature Parms{};

	Parms.Param_Text = Param_Text;

	UObject::ProcessEvent(Func, &Parms);
}

}


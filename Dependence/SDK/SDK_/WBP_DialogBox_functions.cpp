#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_DialogBox

#include "Basic.hpp"

#include "WBP_DialogBox_classes.hpp"
#include "WBP_DialogBox_parameters.hpp"


namespace SDK
{

// Function WBP_DialogBox.WBP_DialogBox_C.ReturnSecodnOption__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWBP_DialogBox_C::ReturnSecodnOption__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "ReturnSecodnOption__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_DialogBox.WBP_DialogBox_C.ReturnFirstOption__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)

void UWBP_DialogBox_C::ReturnFirstOption__DelegateSignature()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "ReturnFirstOption__DelegateSignature");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_DialogBox.WBP_DialogBox_C.ExecuteUbergraph_WBP_DialogBox
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_DialogBox_C::ExecuteUbergraph_WBP_DialogBox(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "ExecuteUbergraph_WBP_DialogBox");

	Params::WBP_DialogBox_C_ExecuteUbergraph_WBP_DialogBox Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_DialogBox.WBP_DialogBox_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UWBP_DialogBox_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_DialogBox.WBP_DialogBox_C.CompleteDialog
// (BlueprintCallable, BlueprintEvent)

void UWBP_DialogBox_C::CompleteDialog()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "CompleteDialog");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WBP_DialogBox.WBP_DialogBox_C.BndEvt__WBP_DialogBox_Option2_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UClickableText_C*                 Text                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void UWBP_DialogBox_C::BndEvt__WBP_DialogBox_Option2_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature(class UClickableText_C* Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "BndEvt__WBP_DialogBox_Option2_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature");

	Params::WBP_DialogBox_C_BndEvt__WBP_DialogBox_Option2_K2Node_ComponentBoundEvent_1_OnClick__DelegateSignature Parms{};

	Parms.Text = Text;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_DialogBox.WBP_DialogBox_C.BndEvt__WBP_DialogBox_Option1_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UClickableText_C*                 Text                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, NoDestructor, HasGetValueTypeHash)

void UWBP_DialogBox_C::BndEvt__WBP_DialogBox_Option1_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature(class UClickableText_C* Text)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DialogBox_C", "BndEvt__WBP_DialogBox_Option1_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature");

	Params::WBP_DialogBox_C_BndEvt__WBP_DialogBox_Option1_K2Node_ComponentBoundEvent_0_OnClick__DelegateSignature Parms{};

	Parms.Text = Text;

	UObject::ProcessEvent(Func, &Parms);
}

}


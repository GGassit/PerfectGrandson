#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WBP_DebugCanvas

#include "Basic.hpp"

#include "WBP_DebugCanvas_classes.hpp"
#include "WBP_DebugCanvas_parameters.hpp"


namespace SDK
{

// Function WBP_DebugCanvas.WBP_DebugCanvas_C.PrintDebugString
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           String                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// bool                                    PrintToLog                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FLinearColor                     Text_Color                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// double                                  Duration                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_DebugCanvas_C::PrintDebugString(const class FString& String, bool PrintToLog, const struct FLinearColor& Text_Color, double Duration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DebugCanvas_C", "PrintDebugString");

	Params::WBP_DebugCanvas_C_PrintDebugString Parms{};

	Parms.String = std::move(String);
	Parms.PrintToLog = PrintToLog;
	Parms.Text_Color = std::move(Text_Color);
	Parms.Duration = Duration;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WBP_DebugCanvas.WBP_DebugCanvas_C.ExecuteUbergraph_WBP_DebugCanvas
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWBP_DebugCanvas_C::ExecuteUbergraph_WBP_DebugCanvas(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WBP_DebugCanvas_C", "ExecuteUbergraph_WBP_DebugCanvas");

	Params::WBP_DebugCanvas_C_ExecuteUbergraph_WBP_DebugCanvas Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}

}


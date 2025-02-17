#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_SafeKey

#include "Basic.hpp"

#include "BP_SafeKey_classes.hpp"
#include "BP_SafeKey_parameters.hpp"


namespace SDK
{

// Function BP_SafeKey.BP_SafeKey_C.TeleportToSafeLocation
// (BlueprintCallable, BlueprintEvent)

void ABP_SafeKey_C::TeleportToSafeLocation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SafeKey_C", "TeleportToSafeLocation");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_SafeKey.BP_SafeKey_C.Taken
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    ByGranny                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_SafeKey_C::Taken(bool ByGranny)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SafeKey_C", "Taken");

	Params::BP_SafeKey_C_Taken Parms{};

	Parms.ByGranny = ByGranny;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_SafeKey.BP_SafeKey_C.ExecuteUbergraph_BP_SafeKey
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABP_SafeKey_C::ExecuteUbergraph_BP_SafeKey(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SafeKey_C", "ExecuteUbergraph_BP_SafeKey");

	Params::BP_SafeKey_C_ExecuteUbergraph_BP_SafeKey Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_SafeKey.BP_SafeKey_C.CalcSafeLocation
// (BlueprintCallable, BlueprintEvent)

void ABP_SafeKey_C::CalcSafeLocation()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_SafeKey_C", "CalcSafeLocation");

	UObject::ProcessEvent(Func, nullptr);
}

}


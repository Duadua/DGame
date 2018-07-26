#include "DUtility.h"
#include "DGame.h"

UDUtility::UDUtility(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UDUtility::log(FString msg)
{
	UE_LOG(my_log, Warning, TEXT("%s"), *msg);
}

void UDUtility::debug_out(FString msg)
{
	if(GEngine) { GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, msg); }
}

void UDUtility::debug_out_int(int msg)
{
	if(GEngine) { GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::FromInt(msg)); }
}

void UDUtility::debug_out_float(float msg)
{
	if(GEngine) { GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, FString::SanitizeFloat(msg)); }
}



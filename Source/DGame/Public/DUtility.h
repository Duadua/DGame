#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DUtility.generated.h"

UCLASS()
class DGAME_API UDUtility : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

public:
	// show log info
	UFUNCTION(BlueprintCallable)
	static void log(FString msg);

	UFUNCTION(BlueprintCallable)
	static void debug_out(FString msg);
	UFUNCTION(BlueprintCallable)
	static void debug_out_int(int msg);
	UFUNCTION(BlueprintCallable)
	static void debug_out_float(float msg);
};

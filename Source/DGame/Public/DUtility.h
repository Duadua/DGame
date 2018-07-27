#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DUtility.generated.h"

class AGameModeBase;

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

	UFUNCTION(BlueprintCallable)
	static void set_game_mode(AGameModeBase* pGameMode);
	UFUNCTION(BlueprintCallable)
	static AGameModeBase* get_game_mode();

	UFUNCTION(BlueprintCallable, Category = "get")
	static APlayerController* get_local_playercontroller(UObject* WorldContextObject);

private:
	static AGameModeBase* game_mode_instance;
	




};


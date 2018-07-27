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


AGameModeBase* UDUtility::game_mode_instance = nullptr;
void UDUtility::set_game_mode(AGameModeBase* pGameMode) { game_mode_instance = pGameMode; }
AGameModeBase * UDUtility::get_game_mode() { return game_mode_instance; }


APlayerController* UDUtility::get_local_playercontroller(UObject* WorldContextObject)
{
	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		for (auto Iterator = World->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			APlayerController* PlayerController = Cast<APlayerController>(*Iterator);
			if (PlayerController->IsLocalController())
			{
				// For this project, we will only ever have one local player.  
				return PlayerController;
			}
		}
	}
	return nullptr;
}

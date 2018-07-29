#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DTypes.h"
#include "DGameMode.generated.h"

class ADCharacter;
class APlayerStart;
class ADPlayerController;

UCLASS(config = Game)
class DGAME_API ADGameMode : public AGameMode 
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;

	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = TEXT("")) override;
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;
	virtual void PostLogin(APlayerController* NewPlayer);
	virtual void Logout(AController* Exiting) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "client")
	TArray<APlayerStart*> m_player_starts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "client")
	ADPlayerController* m_cur_controller;

	UFUNCTION(BlueprintCallable)
	void get_all_player_start();

public:

	TSubclassOf<ADCharacter> m_pawn_class;
	TArray<ADCharacter*> m_pawns;
	TMap<FString, FPlayerData> m_players;
};

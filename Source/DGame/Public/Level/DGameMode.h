#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DGameMode.generated.h"

class APlayerStart;
class ADPlayerController;

UCLASS(config = Game)
class DGAME_API ADGameMode : public AGameMode {
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "client")
	int m_client_index;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "client")
	TArray<APlayerStart*> m_player_starts;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "client")
	ADPlayerController* m_cur_controller;

	UFUNCTION(BlueprintCallable)
	void get_all_player_start();

};

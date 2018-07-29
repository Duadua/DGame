#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DGameState.generated.h"

class FString;

UCLASS()
class DGAME_API ADGameState : public AGameState
{
	GENERATED_BODY()

	ADGameState();

public:	
	UPROPERTY(Replicated)
	int m_player_cnt;

	UPROPERTY(Replicated)
	TArray<FString> m_player_names;

};

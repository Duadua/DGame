#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DMainGameMode.generated.h"

UCLASS(config = Game)
class DGAME_API ADMainGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;
	
};

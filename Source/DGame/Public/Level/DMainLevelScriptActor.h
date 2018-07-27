#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "DMainLevelScriptActor.generated.h"

UCLASS()
class DGAME_API ADMainLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	ADMainLevelScriptActor();

	virtual void BeginPlay() override;
	virtual void Tick(float Delta) override;

};

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameEngine.h"
#include "DGameEngine.generated.h"

UCLASS()
class DGAME_API UDGameEngine : public UGameEngine 
{
	GENERATED_UCLASS_BODY()
	
	virtual void Init(IEngineLoop* InEngineLoop);

public:

	
};

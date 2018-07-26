#include "DGameEngine.h"
#include "DGame.h"


UDGameEngine::UDGameEngine(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UDGameEngine::Init(IEngineLoop* InEngineLoop)
{
	Super::Init(InEngineLoop);
	UDUtility::log("use my game engine");
}

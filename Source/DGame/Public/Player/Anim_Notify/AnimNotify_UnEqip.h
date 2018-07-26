#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_UnEqip.generated.h"

UCLASS()
class DGAME_API UAnimNotify_UnEqip : public UAnimNotify
{
	GENERATED_UCLASS_BODY()
	
	UFUNCTION()
	bool Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);

	class ADCharacter* m_pawn;
	
	
};

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_Eqip.generated.h"

UCLASS()
class DGAME_API UAnimNotify_Eqip : public UAnimNotify 
{
	GENERATED_BODY()

public:
	UFUNCTION()
	bool Received_Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation);

	class ADCharacter* m_pawn;
};

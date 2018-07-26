#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DTypes.h"
#include "DPlayerController.generated.h"


UCLASS(config = Game)
class DGAME_API ADPlayerController : public APlayerController 
{
	GENERATED_UCLASS_BODY()

public:


	virtual void BeginPlay()                 override; 
	virtual void PlayerTick(float DeltaTime) override; 
	virtual void SetupInputComponent()       override; 

	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

public:
	uint32 m_b_can_rotate : 1;

	void on_can_rotate_pressed();
	void on_can_rotate_released();

	UPROPERTY(BlueprintReadWrite, Replicated)
	int m_client_type;

};

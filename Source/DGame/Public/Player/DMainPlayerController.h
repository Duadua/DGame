#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DMainPlayerController.generated.h"

UCLASS(config = Game)
class DGAME_API ADMainPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

public:
	virtual void BeginPlay()                 override;
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent()       override;

	virtual void TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	void set_camera_pos();

public:
	// ª∂”≠ΩÁ√Ê
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UDMainUI* m_main_ui;
	void init_main_ui();

};

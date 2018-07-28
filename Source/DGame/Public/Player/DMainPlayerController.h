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
	// 欢迎界面
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UDMainUI* m_main_ui;
	void init_main_ui();

	UFUNCTION()
	void on_login_bt();
	UFUNCTION()
	void on_localin_bt();
	UFUNCTION()
	void on_option_bt();
	UFUNCTION()
	void on_exit_bt();

	// 登录界面
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UDLoginUI* m_login_ui;
	void init_login_ui();

	UFUNCTION()
	void on_login_login_bt();
	UFUNCTION()
	void on_login_cancel_bt();

};

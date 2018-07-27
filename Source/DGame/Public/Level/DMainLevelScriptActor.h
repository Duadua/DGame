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

	// ª∂”≠ΩÁ√Ê
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UDMainUI* m_main_ui;
	void init_main_ui();

	UFUNCTION()
	void on_exit_bt();

public:
	UFUNCTION(BlueprintImplementableEvent)
	void bp_bind_camera();
};

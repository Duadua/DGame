#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DMainUI.generated.h"

UCLASS()
class DGAME_API UDMainUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//初始化
	virtual bool Initialize() override;
	void init();

public:
	// 改变模式按钮
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_login_bt;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_localin_bt;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_option_bt;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_exit_bt;
	
};

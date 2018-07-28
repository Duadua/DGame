#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DLoginUI.generated.h"

UCLASS()
class DGAME_API UDLoginUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//初始化
	virtual bool Initialize() override;
	void init();

public:
	// 改变模式按钮
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* m_username_text;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* m_ip_text;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UEditableTextBox* m_port_text;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_login_bt;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UButton* m_cancel_bt;
};

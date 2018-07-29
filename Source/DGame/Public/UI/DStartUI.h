#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DStartUI.generated.h"

UCLASS()
class DGAME_API UDStartUI : public UUserWidget
{
	GENERATED_BODY()

public:
	//≥ı ºªØ
	virtual bool Initialize() override;
	void init();

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UTextBlock* m_hc_text;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UI")
	class UScrollBox* m_namelist_sb;

	
};

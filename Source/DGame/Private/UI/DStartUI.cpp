#include "DStartUI.h"
#include "DGame.h"



bool UDStartUI::Initialize() {
	if (!Super::Initialize()) return false;
	init();
	return true;
}

void UDStartUI::init()
{
	m_hc_text = Cast<UTextBlock>(GetWidgetFromName(TEXT("txt_hc")));
	m_namelist_sb = Cast<UScrollBox>(GetWidgetFromName(TEXT("sb_namelist")));
}

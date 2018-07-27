#include "DMainUI.h"
#include "DGame.h"


bool UDMainUI::Initialize() {
	if (!Super::Initialize()) return false;
	init();
	return true;
}

void UDMainUI::init()
{
	m_login_bt   = Cast<UButton>(GetWidgetFromName(TEXT("bt_login"))); 
	m_localin_bt = Cast<UButton>(GetWidgetFromName(TEXT("bt_localin"))); 
	m_option_bt  = Cast<UButton>(GetWidgetFromName(TEXT("bt_option"))); 
	m_exit_bt    = Cast<UButton>(GetWidgetFromName(TEXT("bt_exit"))); 

}

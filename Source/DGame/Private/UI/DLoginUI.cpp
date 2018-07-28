#include "DLoginUI.h"
#include "Dgame.h"

bool UDLoginUI::Initialize() {
	if (!Super::Initialize()) return false;
	init();
	return true;
}

void UDLoginUI::init()
{
	m_username_text = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("txt_username")));
	m_ip_text       = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("txt_ip")));
	m_port_text     = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("txt_port")));
	m_login_bt      = Cast<UButton>(GetWidgetFromName(TEXT("bt_login")));        
	m_cancel_bt     = Cast<UButton>(GetWidgetFromName(TEXT("bt_cancel")));       

}

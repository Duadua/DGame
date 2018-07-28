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

	// 给界面的控件注册事件
	m_login_bt->OnClicked.AddDynamic(this, &UDMainUI::on_login_bt);
	m_localin_bt->OnClicked.AddDynamic(this, &UDMainUI::on_localin_bt);
	m_exit_bt->OnClicked.AddDynamic(this, &UDMainUI::on_exit_bt);


}

void UDMainUI::on_login_bt()
{
	
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		
		if (PC->Role == ROLE_Authority) { PC->ConsoleCommand("open mp_start"); }
		//FString URL = FString::Printf(TEXT("%s:%s?Alias=%s"), *(TxtServerIP->GetText().ToString()), *(TxtServerPort->GetText().ToString()), *(TxtUsername->GetText().ToString()));
		FString URL = TEXT("127.0.0.1:17777");

		UDUtility::debug_out(URL);
		PC->ClientTravel(*URL, TRAVEL_Absolute);
	}
}

void UDMainUI::on_localin_bt()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("open mp_start");
}

void UDMainUI::on_exit_bt()
{
	//	UDUtility::debug_out("exit local");
	//UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit);
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("QUIT");

}

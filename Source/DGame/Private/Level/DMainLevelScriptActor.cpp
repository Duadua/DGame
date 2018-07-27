#include "DMainLevelScriptActor.h"
#include "DGame.h"

ADMainLevelScriptActor::ADMainLevelScriptActor()
{

}

void ADMainLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();
	init_main_ui();
	bp_bind_camera();
}
void ADMainLevelScriptActor::Tick(float Delta)
{
	Super::Tick(Delta);
}

void ADMainLevelScriptActor::init_main_ui()
{
	m_main_ui = CreateWidget<UDMainUI>(GetGameInstance(), LoadClass<UDMainUI>(nullptr, TEXT("WidgetBlueprint'/Game/blueprints/UI/wb_main.wb_main_C'")));
	if (!m_main_ui) return;
	// 给界面的控件注册事件
	m_main_ui->m_exit_bt->OnClicked.AddDynamic(this, &ADMainLevelScriptActor::on_exit_bt);
	m_main_ui->AddToViewport();
}
	

void ADMainLevelScriptActor::on_exit_bt()
{
//	UDUtility::debug_out("exit local");
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit);

}

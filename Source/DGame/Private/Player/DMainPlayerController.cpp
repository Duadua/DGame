#include "DMainPlayerController.h"
#include "Dgame.h"


ADMainPlayerController::ADMainPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bShowMouseCursor = true;

	//	UDUtility::debug_out("controller");

}

void ADMainPlayerController::BeginPlay()
{
	Super::BeginPlay();
	set_camera_pos();
	init_main_ui();
	init_login_ui();
}

void ADMainPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void ADMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

}

void ADMainPlayerController::TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void ADMainPlayerController::set_camera_pos()
{
	PlayerCameraManager->SetActorLocation(FVector(0.f, 0.f, 0.f));
	SetViewTarget(PlayerCameraManager);
	bShowMouseCursor = true;
}

void ADMainPlayerController::init_main_ui()
{
	m_main_ui = CreateWidget<UDMainUI>(GetGameInstance(), LoadClass<UDMainUI>(nullptr, TEXT("WidgetBlueprint'/Game/blueprints/UI/wb_main.wb_main_C'")));
	if (!m_main_ui) return;
	
	// 给界面的控件注册事件
	m_main_ui->m_login_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_login_bt);
	m_main_ui->m_localin_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_localin_bt);
	m_main_ui->m_option_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_option_bt);
	m_main_ui->m_exit_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_exit_bt);

	m_main_ui->AddToViewport();
}
void ADMainPlayerController::init_login_ui()
{
	m_login_ui = CreateWidget<UDLoginUI>(GetGameInstance(), LoadClass<UDLoginUI>(nullptr, TEXT("WidgetBlueprint'/Game/blueprints/UI/wb_login.wb_login_C'")));
	if (!m_login_ui) return;
	m_login_ui->m_login_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_login_login_bt);
	m_login_ui->m_cancel_bt->OnClicked.AddDynamic(this, &ADMainPlayerController::on_login_cancel_bt);

}

void ADMainPlayerController::on_login_bt()
{
	/*
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{

	if (PC->Role == ROLE_Authority) { PC->ConsoleCommand("open mp_start"); }
	//FString URL = FString::Printf(TEXT("%s:%s?Alias=%s"), *(TxtServerIP->GetText().ToString()), *(TxtServerPort->GetText().ToString()), *(TxtUsername->GetText().ToString()));
	FString URL = TEXT("127.0.0.1:7777");

	UDUtility::log(URL);
	PC->ClientTravel(*URL, TRAVEL_Absolute);
	}
	*/
	m_main_ui->RemoveFromParent();
	m_login_ui->AddToViewport();
}
void ADMainPlayerController::on_localin_bt()
{
	//GetWorld()->GetFirstPlayerController()->ConsoleCommand("open mp_start");
	ConsoleCommand("open mp_start");
}
void ADMainPlayerController::on_option_bt()
{
	UDUtility::debug_out("option bt clicked");
}
void ADMainPlayerController::on_exit_bt()
{
	//	UDUtility::debug_out("exit local");
	//UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit);
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("QUIT");

}

void ADMainPlayerController::on_login_login_bt()
{
	if (m_login_ui->m_username_text->GetText().ToString().IsEmpty()) {
		UDUtility::debug_out(TEXT("请输入用户名先"));
		return;
	}

//	FString URL = TEXT("127.0.0.1:7777");
	FString url = FString::Printf(TEXT("%s:%s?Alias=%s"), 
								*(m_login_ui->m_ip_text->GetText().ToString()), 
								*(m_login_ui->m_port_text->GetText().ToString()), 
								*(m_login_ui->m_username_text->GetText().ToString()));
	UDUtility::log(url);
	ClientTravel(*url, TRAVEL_Absolute);

}
void ADMainPlayerController::on_login_cancel_bt()
{
	m_login_ui->RemoveFromParent();
	m_main_ui->AddToViewport();
}

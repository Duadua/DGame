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
	m_main_ui->AddToViewport();
}

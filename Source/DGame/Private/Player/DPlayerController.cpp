#include "DPlayerController.h"
#include "DGame.h"

ADPlayerController::ADPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	m_b_can_rotate = false;

//	UDUtility::debug_out("controller");

}

void ADPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ADPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
}

void ADPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("CanRotate", IE_Pressed, this, &ADPlayerController::on_can_rotate_pressed);
	InputComponent->BindAction("CanRotate", IE_Released, this, &ADPlayerController::on_can_rotate_released);

}

void ADPlayerController::TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}

void ADPlayerController::on_can_rotate_pressed() { 
	m_b_can_rotate = true; 
	bShowMouseCursor = false;
	FInputModeGameOnly input;
	SetInputMode(input);
	
}
void ADPlayerController::on_can_rotate_released() { 
	m_b_can_rotate = false; 
	bShowMouseCursor = true;
	FInputModeGameAndUI input;
	SetInputMode(input);
}



void ADPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADPlayerController, m_client_type);
}

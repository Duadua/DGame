#include "DPlayerController.h"
#include "DGame.h"

ADPlayerController::ADPlayerController(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	m_b_can_rotate = false;


}

void ADPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (Role == ROLE_AutonomousProxy && NM_Client == GetNetMode()) {
		init_start_ui();
		FString tmp = FString::Printf(TEXT("欢迎 %s 上线~"), *m_name);
		UDUtility::debug_out(tmp);
	}

}

void ADPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	if (Role == ROLE_AutonomousProxy && NM_Client == GetNetMode()) {
		update_hc();
		update_sb();
	}

//	UDUtility::debug_out("name");
//	UDUtility::debug_out(m_name);
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

	DOREPLIFETIME(ADPlayerController, m_id);
	DOREPLIFETIME(ADPlayerController, m_name);
}


void ADPlayerController::init_start_ui()
{
	m_start_ui = CreateWidget<UDStartUI>(GetGameInstance(), LoadClass<UDStartUI>(nullptr, TEXT("WidgetBlueprint'/Game/blueprints/UI/wb_start.wb_start_C'")));
	if (!m_start_ui) {
		UDUtility::debug_out("init start ui failed");
		return;
	}

	m_start_ui->AddToViewport();
	/*UTextBlock* text_block = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
	if (text_block) {
		UDUtility::debug_out(m_name);
		text_block->SetText(FText::FromString(m_name));
		m_start_ui->m_namelist_sb->AddChild(text_block);
	}*/
	
}

void ADPlayerController::update_hc()
{
	if (!m_start_ui) return;
	if (!m_start_ui->m_namelist_sb) return;
	if (ADGameState* state = Cast<ADGameState>(GetWorld()->GetGameState()))
	{
		m_start_ui->m_hc_text->SetText(FText::FromString(FString::FromInt(state->m_player_cnt)));
	}
}

void ADPlayerController::update_sb()
{
	if (!m_start_ui) return;
	if (!m_start_ui->m_namelist_sb) return;
	m_start_ui->m_namelist_sb->ClearChildren();
	if (ADGameState* state = Cast<ADGameState>(GetWorld()->GetGameState())) {
		for (auto a : state->m_player_names) {
			UTextBlock* text_block = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
			if (text_block) {
				text_block->SetText(FText::FromString(a));
				m_start_ui->m_namelist_sb->AddChild(text_block);
			}
		}
	}
}

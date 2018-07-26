#include "DGameMode.h"
#include "DGame.h"

ADGameMode::ADGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// 设置默认角色控制器
	PlayerControllerClass = ADPlayerController::StaticClass();

	// 设置默认角色
	static ConstructorHelpers::FClassFinder<APawn> player_pawn_class(TEXT("/Game/blueprints/player/bp_pawn"));
	if(player_pawn_class.Class != NULL) { DefaultPawnClass = player_pawn_class.Class; }

	m_client_index = 0;
}


void ADGameMode::BeginPlay()
{
	Super::BeginPlay();
	//UDUtility::debug_out_int(m_client_index);
}
void ADGameMode::Tick(float Delta)
{
	Super::Tick(Delta);
}

void ADGameMode::get_all_player_start()
{
	if (m_player_starts.Num() > 0) return;
	TArray<AActor*> array_actor;
	UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), APlayerStart::StaticClass(), array_actor);
	for(auto it = array_actor.CreateIterator(); it; ++it)
	{
		m_player_starts.Push(Cast<APlayerStart>(*it));
	}

	//UDUtility::debug_out_int(m_player_starts.Num());

}

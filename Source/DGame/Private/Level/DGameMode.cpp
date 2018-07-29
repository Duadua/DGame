#include "DGameMode.h"
#include "DGame.h"

ADGameMode::ADGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// 设置默认角色控制器
	PlayerControllerClass = ADPlayerController::StaticClass();

	// 设置默认角色
	static ConstructorHelpers::FClassFinder<APawn> player_pawn_class(TEXT("/Game/blueprints/player/bp_pawn"));
	if(player_pawn_class.Class != NULL) { 
		DefaultPawnClass = player_pawn_class.Class; 
		m_pawn_class = player_pawn_class.Class;
	}
	
	// 设置默认GameState
	GameStateClass = ADGameState::StaticClass();

	UDUtility::set_game_mode(this);
}


void ADGameMode::BeginPlay()
{
	Super::BeginPlay();

}
void ADGameMode::Tick(float Delta)
{
	Super::Tick(Delta);

}

FString ADGameMode::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	FString res = Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
	if (ADPlayerController* pc = Cast<ADPlayerController>(NewPlayerController))
	{
		FString alias = UGameplayStatics::ParseOption(Options, TEXT("Alias")).TrimStartAndEnd();
		if (alias.Len() == 0 || m_players.Find(alias)) { return res; }
		pc->m_name = alias;						// 获得 controller 的名字

		if (ADGameState* state = GetGameState<ADGameState>()) {
			state->m_player_names.Add(alias);
			//for (auto a : state->m_player_names) { UDUtility::debug_out(a); }
		}

		FPlayerData tpd; tpd.m_name = alias;
		m_players.Add(alias, tpd);
	}
	return res;

}
APlayerController* ADGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}
void ADGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	if (GetNetMode() == NM_DedicatedServer) {

		get_all_player_start();					// 获得所有的player_start

		if (m_pawn_class) {

			if (ADGameState* state = GetGameState<ADGameState>()) { 
				if (m_player_starts.Num() > state->m_player_cnt) {
					int i = state->m_player_cnt;
					if (ADPlayerController* pc = Cast<ADPlayerController>(NewPlayer)) {
						pc->m_id = i;
						if (ADCharacter* pawn = Cast<ADCharacter>(pc->GetPawn())) {
							pawn->SetActorTransform(m_player_starts[i]->GetActorTransform());
							pc->SetControlRotation(m_player_starts[i]->GetActorRotation());
							if (FPlayerData* tpd = m_players.Find(pc->m_name)) {
								tpd->m_pawn = pawn;
							}
							
						}
					}
					// 在当前 start 生成 pawn
					/*if (ADCharacter* pawn = GetWorld()->SpawnActor<ADCharacter>(m_pawn_class, m_player_starts[i]->GetActorLocation(), m_player_starts[i]->GetActorRotation())) {
						m_pawns.Push(pawn);
						pawn->SpawnDefaultController();
						// pawn 信息 插入 map
						if (ADPlayerController* pc = Cast<ADPlayerController>(NewPlayer)) {
							if (FPlayerDdata* tpd = state->m_players.Find(pc->m_name)) {
								tpd->m_pawn = pawn;
							}
						}
					}*/
				}
				
				++state->m_player_cnt; 
			}

		}

	}
}

void ADGameMode::Logout(AController* Exiting)
{
	if (ADGameState* state = GetGameState<ADGameState>()) {
		--state->m_player_cnt; 
		if (ADPlayerController* pc = Cast<ADPlayerController>(Exiting)) {
			state->m_player_names.Remove(pc->m_name);
		}
	}

	Super::Logout(Exiting);
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

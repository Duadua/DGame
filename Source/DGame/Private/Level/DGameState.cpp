#include "DGameState.h"
#include "DGame.h"


ADGameState::ADGameState()
{
	m_player_cnt = 0;
}

void ADGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADGameState, m_player_cnt);
	DOREPLIFETIME(ADGameState, m_player_names);
}

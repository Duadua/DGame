#include "DMainGameMode.h"
#include "DGame.h"

ADMainGameMode::ADMainGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// ����Ĭ�Ͻ�ɫ������
	PlayerControllerClass = APlayerController::StaticClass();

	// ����Ĭ�Ͻ�ɫ
	DefaultPawnClass = nullptr;

	UDUtility::set_game_mode(this);
}


void ADMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}
void ADMainGameMode::Tick(float Delta)
{
	Super::Tick(Delta);

}
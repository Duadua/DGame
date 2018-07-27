#include "DMainGameMode.h"
#include "DGame.h"

ADMainGameMode::ADMainGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// 设置默认角色控制器
	PlayerControllerClass = APlayerController::StaticClass();

	// 设置默认角色
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
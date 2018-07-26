#include "DGameInstance.h"
#include "DGame.h"


UDGameInstance::UDGameInstance(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UDGameInstance::Tick(float DeltaSeconds) 
{
	return true;
}

void UDGameInstance::Init()
{
	Super::Init();
	UDUtility::log("use my gameinstance");
}
void UDGameInstance::Shutdown()
{
	Super::Shutdown();

}
void UDGameInstance::StartGameInstance()
{

}
void UDGameInstance::ReceivedNetworkEncryptionToken(const FString& EncryptionToken, const FOnEncryptionKeyResponse& Delegate)
{

}
void UDGameInstance::ReceivedNetworkEncryptionAck(const FOnEncryptionKeyResponse& Delegate)
{

}


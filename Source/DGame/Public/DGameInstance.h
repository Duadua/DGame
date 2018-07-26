#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DGameInstance.generated.h"

UCLASS(config = Game)
class DGAME_API UDGameInstance : public UGameInstance
{
	
public:
	GENERATED_UCLASS_BODY()

public:

	bool Tick(float DeltaSeconds);

	//AShooterGameSession* GetGameSession() const;

	virtual void Init() override;
	virtual void Shutdown() override;
	virtual void StartGameInstance() override;
	virtual void ReceivedNetworkEncryptionToken(const FString& EncryptionToken, const FOnEncryptionKeyResponse& Delegate) override;
	virtual void ReceivedNetworkEncryptionAck(const FOnEncryptionKeyResponse& Delegate) override;

	
};

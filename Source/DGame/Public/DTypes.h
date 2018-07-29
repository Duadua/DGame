#pragma once

#include "CoreMinimal.h"
#include "DTypes.generated.h"

UENUM(BlueprintType)
enum class client_type:uint8
{
	ECLIENT_A UMETA(DisplayName = "client_a"),
	ECLIENT_B UMETA(DisplayName = "client_b"),
};

class ADCharacter;

USTRUCT(BlueprintType)
struct FPlayerData 
{
	GENERATED_BODY()
public:
	FString m_name;
	ADCharacter* m_pawn;
	FPlayerData() { m_pawn = nullptr; }
};
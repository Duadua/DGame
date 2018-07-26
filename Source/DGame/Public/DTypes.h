#pragma once

#include "CoreMinimal.h"
#include "DTypes.generated.h"

UENUM(BlueprintType)
enum class client_type:uint8
{
	ECLIENT_A UMETA(DisplayName = "client_a"),
	ECLIENT_B UMETA(DisplayName = "client_b"),
};
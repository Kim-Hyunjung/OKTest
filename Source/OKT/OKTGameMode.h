// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OKTGameMode.generated.h"

class UOKTDefaultHUD;

UCLASS(minimalapi)
class AOKTGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOKTGameMode();

protected:
	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<UOKTDefaultHUD> DefaultHUDClass;
};

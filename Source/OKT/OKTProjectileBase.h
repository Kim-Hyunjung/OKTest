// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OKTProjectileBase.generated.h"

class UArrowComponent;

UCLASS()
class AOKTProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	AOKTProjectileBase();

	void Tick(float DeltaSeconds) override;

protected:
	void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DestroyTime = 3.0f;

protected:
	UPROPERTY()
	UArrowComponent* ArrowComponent;
	UPROPERTY()
	float AccumulateTime;
};

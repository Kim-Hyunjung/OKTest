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

	virtual void Disappear();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DestroyTime = 3.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* DefaultArrow;
	UPROPERTY()
	float AccumulateTime;
};

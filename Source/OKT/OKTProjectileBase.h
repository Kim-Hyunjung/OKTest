// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OKTProjectileBase.generated.h"

class UArrowComponent;
class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class AOKTProjectileBase : public AActor
{
	GENERATED_BODY()

public:
	AOKTProjectileBase();

	void Tick(float DeltaSeconds) override;
	void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

protected:
	void BeginPlay() override;

	virtual void Disappear();

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float DestroyTime = 3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Speed = 100.0f;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* DefaultArrow;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UProjectileMovementComponent* MoveComponent;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USphereComponent* CollisionComponent;
	UPROPERTY()
	float AccumulateTime;
};

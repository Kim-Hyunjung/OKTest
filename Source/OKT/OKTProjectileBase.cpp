// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectileBase.h"
#include "Components/ArrowComponent.h"

AOKTProjectileBase::AOKTProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("BaseArrow"));
	ArrowComponent->SetupAttachment(GetRootComponent());
}

void AOKTProjectileBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AccumulateTime += DeltaSeconds;
	if (AccumulateTime >= DestroyTime) 
	{
		Destroy();
	}
}

void AOKTProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	AccumulateTime = 0.0f;
}

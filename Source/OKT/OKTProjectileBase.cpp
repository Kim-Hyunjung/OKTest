// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectileBase.h"
#include "Components/ArrowComponent.h"

AOKTProjectileBase::AOKTProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	DefaultArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DefaultArrow"));
	DefaultArrow->SetupAttachment(GetRootComponent());
	DefaultArrow->SetHiddenInGame(false);
}

void AOKTProjectileBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AccumulateTime += DeltaSeconds;
	if (AccumulateTime >= DestroyTime) 
	{
		Disappear();
	}
}

void AOKTProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	AccumulateTime = 0.0f;
}

void AOKTProjectileBase::Disappear()
{
	Destroy();
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectile_Split.h"
#include "Components/ArrowComponent.h"
#include "Math/Vector.h"

AOKTProjectile_Split::AOKTProjectile_Split()
{
	FRotator LeftRot = FVector::LeftVector.ToOrientationRotator() * 0.5f;
	LeftArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("LeftArrow"));
	LeftArrow->SetupAttachment(GetRootComponent());
	LeftArrow->SetHiddenInGame(false);
	LeftArrow->SetRelativeRotation(LeftRot);

	FRotator RightRot = FVector::RightVector.ToOrientationRotator() * 0.5f;
	RightArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("RightArrow"));
	RightArrow->SetupAttachment(GetRootComponent());
	RightArrow->SetHiddenInGame(false);
	RightArrow->SetRelativeRotation(RightRot);
}

void AOKTProjectile_Split::Disappear()
{
	UWorld* World = GetWorld();
	World->SpawnActor<AOKTProjectileBase>(GetActorLocation(), DefaultArrow->GetComponentRotation());
	World->SpawnActor<AOKTProjectileBase>(GetActorLocation(), LeftArrow->GetComponentRotation());
	World->SpawnActor<AOKTProjectileBase>(GetActorLocation(), RightArrow->GetComponentRotation());

	Super::Disappear();
}

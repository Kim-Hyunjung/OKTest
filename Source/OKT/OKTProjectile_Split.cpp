// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectile_Split.h"
#include "Components/ArrowComponent.h"
#include "Math/Vector.h"

AOKTProjectile_Split::AOKTProjectile_Split()
{
	LeftArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("LeftArrow"));
	LeftArrow->SetupAttachment(GetRootComponent());
	LeftArrow->SetHiddenInGame(false);
	LeftArrow->SetRelativeRotation(FVector::LeftVector.ToOrientationRotator());

	RightArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("RightArrow"));
	RightArrow->SetupAttachment(GetRootComponent());
	RightArrow->SetHiddenInGame(false);
	RightArrow->SetRelativeRotation(FVector::RightVector.ToOrientationRotator());
}

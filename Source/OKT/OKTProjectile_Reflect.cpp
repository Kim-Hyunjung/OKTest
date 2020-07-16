// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectile_Reflect.h"
#include "Components/ArrowComponent.h"
#include "Math/Color.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/Rotator.h"

AOKTProjectile_Reflect::AOKTProjectile_Reflect()
{
	if (DefaultArrow != nullptr)
	{
		DefaultArrow->SetArrowColor(FLinearColor(0.0f, 0.0f, 1.0f, 1.0f));
	}

	if (MoveComponent != nullptr)
	{
		MoveComponent->OnProjectileStop.AddDynamic(this, &AOKTProjectile_Reflect::OnStop);
	}
}

void AOKTProjectile_Reflect::OnStop(const FHitResult& Hit)
{
	if (MoveComponent != nullptr)
	{
		MoveComponent->SetUpdatedComponent(GetDefaultAttachComponent());
		MoveComponent->UpdateComponentVelocity();
	}
}

void AOKTProjectile_Reflect::Blocked()
{
	FRotator CurrentRot = GetActorRotation() + FRotator(0.0f, 180.0f, 0.0f);
	SetActorRotation(CurrentRot);
}

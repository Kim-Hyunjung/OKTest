// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectileBase.h"
#include "Components/ArrowComponent.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/SphereComponent.h>

AOKTProjectileBase::AOKTProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = SceneComponent;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->InitSphereRadius(15.0f);
	CollisionComponent->BodyInstance.SetInstanceNotifyRBCollision(true);

	DefaultArrow = CreateDefaultSubobject<UArrowComponent>(TEXT("DefaultArrow"));
	DefaultArrow->SetupAttachment(GetDefaultAttachComponent());
	DefaultArrow->SetHiddenInGame(false);

	MoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComponent"));
	MoveComponent->SetUpdatedComponent(GetDefaultAttachComponent());
	MoveComponent->InitialSpeed = 0.0f;
	MoveComponent->ProjectileGravityScale = 0.0f;
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

void AOKTProjectileBase::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

void AOKTProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	AccumulateTime = 0.0f;
	MoveComponent->Velocity = (GetActorForwardVector() * Speed);
}

void AOKTProjectileBase::Disappear()
{
	Destroy();
}

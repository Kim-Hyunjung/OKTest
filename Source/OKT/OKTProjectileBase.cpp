// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectileBase.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Engine/CollisionProfile.h"

AOKTProjectileBase::AOKTProjectileBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetHiddenInGame(false);
	CollisionComponent->SetCollisionProfileName(FName("CharacterMesh"));
	RootComponent = CollisionComponent;

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
	MoveComponent->Velocity = GetActorForwardVector() * Speed;
}

void AOKTProjectileBase::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	Blocked();
}

void AOKTProjectileBase::BeginPlay()
{
	Super::BeginPlay();

	AccumulateTime = 0.0f;
}

void AOKTProjectileBase::Blocked()
{
	Destroy();
}

void AOKTProjectileBase::Disappear()
{
	Destroy();
}

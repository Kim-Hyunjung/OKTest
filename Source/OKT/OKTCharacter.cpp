// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AOKTCharacter::AOKTCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
}

void AOKTCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AOKTCharacter::Input_Axis);

	PlayerInputComponent->BindAction("KeyCodeQ", IE_Pressed, this, &AOKTCharacter::Input_KeyCodeQ_Pressed);
	PlayerInputComponent->BindAction("KeyCodeQ", IE_Released, this, &AOKTCharacter::Input_KeyCodeQ_Released);
	PlayerInputComponent->BindAction("KeyCodeW", IE_Pressed, this, &AOKTCharacter::Input_KeyCodeW_Pressed);
	PlayerInputComponent->BindAction("KeyCodeW", IE_Released, this, &AOKTCharacter::Input_KeyCodeW_Released);
}

void AOKTCharacter::Input_Axis(float InVal)
{
	AddMovementInput(FVector::LeftVector, InVal);
}

void AOKTCharacter::Input_KeyCodeQ_Pressed()
{
	LastSec_KeyCodeQ = GetWorld()->GetTimeSeconds();
}

void AOKTCharacter::Input_KeyCodeQ_Released()
{
	if (LastSec_KeyCodeQ == TNumericLimits<float>::Min())
		return;

	float CurrentSec = GetWorld()->GetTimeSeconds();
	float PressSec_Q = CurrentSec - LastSec_KeyCodeQ;

	bool bChargeFire = PressSec_Q >= ChargeTime;
	if (bChargeFire)
	{
		ChargeFire();
	}
	else
	{
		NormalFire();
	}
}

void AOKTCharacter::Input_KeyCodeW_Pressed()
{
	LastSec_KeyCodeW = GetWorld()->GetTimeSeconds();

	float CurrentSec = LastSec_KeyCodeW;
	float PressSec_Q = CurrentSec - LastSec_KeyCodeQ;

	bool bSplitFire = PressSec_Q <= SplitTime;
	if (bSplitFire)
	{
		SplitFire();
	}
}

void AOKTCharacter::Input_KeyCodeW_Released()
{
	if (LastSec_KeyCodeW == TNumericLimits<float>::Min())
		return;

	ReflectFire();
}

void AOKTCharacter::Fire()
{
	LastSec_KeyCodeQ = TNumericLimits<float>::Min();
	LastSec_KeyCodeW = TNumericLimits<float>::Min();
}

void AOKTCharacter::NormalFire()
{
	Fire();

	UE_LOG(LogTemp, Log, TEXT("NormalFire"));
}

void AOKTCharacter::ChargeFire()
{
	Fire();

	UE_LOG(LogTemp, Log, TEXT("ChargeFire"));
}

void AOKTCharacter::SplitFire()
{
	Fire();

	UE_LOG(LogTemp, Log, TEXT("SplitFire"));
}

void AOKTCharacter::ReflectFire()
{
	Fire();

	UE_LOG(LogTemp, Log, TEXT("ReflectFire"));
}

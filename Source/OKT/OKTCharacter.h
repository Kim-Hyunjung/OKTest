// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OKTCharacter.generated.h"

UCLASS(config=Game)
class AOKTCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOKTCharacter();

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

	// Input
	void Input_Axis(float InVal);
	void Input_KeyCodeQ_Pressed();
	void Input_KeyCodeQ_Released();
	void Input_KeyCodeW_Pressed();
	void Input_KeyCodeW_Released();

	// Fire
	virtual void Fire();
	virtual void NormalFire();
	virtual void ChargeFire();
	virtual void SplitFire();
	virtual void ReflectFire();

public:
	// Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// Input
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float LastSec_KeyCodeQ;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input)
	float LastSec_KeyCodeW;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ChargeTime = 3.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float SplitTime = 1.0f;
};

// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OKTCharacter.generated.h"

class AOKTProjectileBase;

UCLASS(config=Game)
class AOKTCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AOKTCharacter();

	// UI
	void ResetProjectileCount();
	int GetNormalProjectileCount() const { return NormalCount; }
	int GetChargeProjectileCount() const { return ChargeCount; }
	int GetSplitProjectileCount() const { return SplitCount; }
	int GetReflectProjectileCount() const { return ReflectCount; }

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
	virtual AOKTProjectileBase* Fire(TSubclassOf<AOKTProjectileBase> InClass);
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

protected:
	// UI
	UPROPERTY()
	int NormalCount = 0;
	UPROPERTY()
	int ChargeCount = 0;
	UPROPERTY()
	int SplitCount = 0;
	UPROPERTY()
	int ReflectCount = 0;
};

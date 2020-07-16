// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OKTDefaultHUD.generated.h"

class AOKTCharacter;
class UProgressBar;
class UTextBlock;
class UButton;

UCLASS()
class OKT_API UOKTDefaultHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	void NativeOnInitialized() override;
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void OnReset();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  meta = (BindWidget))
	UProgressBar* P_Charge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* T_Information;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UButton* BTN_Reset;

protected:
	UPROPERTY()
	AOKTCharacter* OwnerCharRef;
};

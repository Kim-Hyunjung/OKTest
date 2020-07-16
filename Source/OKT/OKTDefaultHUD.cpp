// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTDefaultHUD.h"
#include "OKTCharacter.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

void UOKTDefaultHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	OwnerCharRef = GetOwningPlayerPawn<AOKTCharacter>();

	BTN_Reset->OnClicked.AddDynamic(this, &UOKTDefaultHUD::OnReset);
}

void UOKTDefaultHUD::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (OwnerCharRef == nullptr)
		return;

	if (P_Charge != nullptr)
	{
		float CurrentSec = GetWorld()->GetTimeSeconds();
		float PressSec_Q = CurrentSec - OwnerCharRef->LastSec_KeyCodeQ;
		bool bIsActive = OwnerCharRef->LastSec_KeyCodeQ != TNumericLimits<float>::Min();
		if (bIsActive)
		{
			float ChargeRate = PressSec_Q / OwnerCharRef->ChargeTime;
			P_Charge->SetPercent(ChargeRate);
		}
		P_Charge->SetVisibility(bIsActive ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}

	if (T_Information != nullptr)
	{
		FString InfoStr = TEXT(" Projectile Counting");
		InfoStr += TEXT("\n Normal Projectile : ");
		InfoStr += FString::FormatAsNumber(OwnerCharRef->GetNormalProjectileCount());
		InfoStr += TEXT("\n Charge Projectile : ");
		InfoStr += FString::FormatAsNumber(OwnerCharRef->GetChargeProjectileCount());
		InfoStr += TEXT("\n Split Projectile : ");
		InfoStr += FString::FormatAsNumber(OwnerCharRef->GetSplitProjectileCount());
		InfoStr += TEXT("\n Reflect Projectile : ");
		InfoStr += FString::FormatAsNumber(OwnerCharRef->GetReflectProjectileCount());
		T_Information->SetText(FText::FromString(InfoStr));
	}
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UOKTDefaultHUD::OnReset()
{
	if (OwnerCharRef == nullptr)
		return;

	OwnerCharRef->ResetProjectileCount();
}

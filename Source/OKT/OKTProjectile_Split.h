// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OKTProjectileBase.h"
#include "OKTProjectile_Split.generated.h"

class UArrowComponent;

UCLASS()
class AOKTProjectile_Split : public AOKTProjectileBase
{
	GENERATED_BODY()

public:
	AOKTProjectile_Split();

protected:
	void Disappear() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* LeftArrow;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UArrowComponent* RightArrow;
};

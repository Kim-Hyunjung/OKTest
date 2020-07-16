// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OKTProjectileBase.h"
#include "OKTProjectile_Reflect.generated.h"

UCLASS()
class AOKTProjectile_Reflect : public AOKTProjectileBase
{
	GENERATED_BODY()

public:
	AOKTProjectile_Reflect();

	UFUNCTION()
	void OnStop(const FHitResult& Hit);

protected:
	virtual void Blocked() override;
};

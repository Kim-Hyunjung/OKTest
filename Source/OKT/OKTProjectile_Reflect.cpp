// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectile_Reflect.h"
#include "Components/ArrowComponent.h"
#include "Math/Color.h"

AOKTProjectile_Reflect::AOKTProjectile_Reflect()
{
	if (DefaultArrow != nullptr)
	{
		DefaultArrow->SetArrowColor(FLinearColor(0.0f, 0.0f, 1.0f, 1.0f));
	}
}

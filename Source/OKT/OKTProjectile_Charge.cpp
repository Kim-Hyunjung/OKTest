// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTProjectile_Charge.h"
#include "Components/ArrowComponent.h"

AOKTProjectile_Charge::AOKTProjectile_Charge()
{
	if (DefaultArrow != nullptr)
	{
		DefaultArrow->ArrowSize *= 3.0f;
	}
	DestroyTime = 5.0f;
}

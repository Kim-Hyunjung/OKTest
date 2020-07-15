// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTGameMode.h"
#include "OKTCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOKTGameMode::AOKTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "OKTGameMode.h"
#include "OKTCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "OKTDefaultHUD.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"

AOKTGameMode::AOKTGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<UOKTDefaultHUD> PlayerDefaultHUDClass(TEXT("/Game/UI/DefaultHUD"));
	if (PlayerDefaultHUDClass.Class != NULL)
	{
		DefaultHUDClass = PlayerDefaultHUDClass.Class;
	}
}

void AOKTGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController != nullptr)
	{
		UOKTDefaultHUD* DefaultHUD = CreateWidget<UOKTDefaultHUD>(PlayerController, DefaultHUDClass);
		if (DefaultHUD != nullptr)
		{
			DefaultHUD->AddToViewport(-10);
		}
	}
}

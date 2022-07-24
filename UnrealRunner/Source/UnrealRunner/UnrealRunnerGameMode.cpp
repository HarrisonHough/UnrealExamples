// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealRunnerGameMode.h"
#include "UnrealRunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealRunnerGameMode::AUnrealRunnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

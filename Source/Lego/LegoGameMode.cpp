// Copyright Epic Games, Inc. All Rights Reserved.

#include "LegoGameMode.h"
#include "LegoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALegoGameMode::ALegoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

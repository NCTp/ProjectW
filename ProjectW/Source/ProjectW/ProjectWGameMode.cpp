// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectWGameMode.h"
#include "ProjectWCharacter.h"

AProjectWGameMode::AProjectWGameMode()
{
	// Set default pawn class to our character
	DefaultPawnClass = AProjectWCharacter::StaticClass();	
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NightWitchGhoul.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTW_API ANightWitchGhoul : public APaperCharacter
{
	GENERATED_BODY()

	ANightWitchGhoul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

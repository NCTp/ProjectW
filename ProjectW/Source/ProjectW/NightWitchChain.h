// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CableActor.h"
#include "NightWitchChain.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTW_API ANightWitchChain : public ACableActor
{
	GENERATED_BODY()
	
public:
	ANightWitchChain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};

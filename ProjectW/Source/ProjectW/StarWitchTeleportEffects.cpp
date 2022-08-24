// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitchTeleportEffects.h"

// Sets default values
AStarWitchTeleportEffects::AStarWitchTeleportEffects()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	delay = 1.5f;
}

// Called when the game starts or when spawned
void AStarWitchTeleportEffects::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AStarWitchTeleportEffects::DestroyMyself, delay, false);
	
}

// Called every frame
void AStarWitchTeleportEffects::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStarWitchTeleportEffects::DestroyMyself()
{
	this->Destroy();
}
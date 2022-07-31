// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitchLaser.h"

// Sets default values
AStarWitchLaser::AStarWitchLaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarWitchLaser::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AStarWitchLaser::DestroyMyself, 0.5f, false);
}

// Called every frame
void AStarWitchLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStarWitchLaser::DestroyMyself()
{
	this->Destroy();
}


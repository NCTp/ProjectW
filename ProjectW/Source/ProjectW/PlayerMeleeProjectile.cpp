// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMeleeProjectile.h"

// Sets default values
APlayerMeleeProjectile::APlayerMeleeProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerMeleeProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerMeleeProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


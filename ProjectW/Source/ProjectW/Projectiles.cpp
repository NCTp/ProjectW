// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectiles.h"

// Sets default values
AProjectiles::AProjectiles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjectiles::BeginPlay()
{
	FTimerHandle timer;
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timer, this, &AProjectiles::DestroyMyself, 5.0f, false);
	
}

// Called every frame
void AProjectiles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectiles::DestroyMyself()
{
	this->Destroy();
}


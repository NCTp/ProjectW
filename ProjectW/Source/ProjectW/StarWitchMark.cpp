// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitchMark.h"
#include "Kismet/GameplayStatics.h"
#include "StarWitchThunder.h"
// Sets default values
AStarWitchMark::AStarWitchMark()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarWitchMark::BeginPlay()
{
	Super::BeginPlay();
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	FTimerHandle timer;
	FTimerHandle timer2;
	GetWorldTimerManager().SetTimer(timer, this, &AStarWitchMark::DestroyMyself, 3.0f, false);
	GetWorldTimerManager().SetTimer(timer2, this, &AStarWitchMark::SpawnThunder, 3.0f, false);
}

// Called every frame
void AStarWitchMark::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector playerLocation = Player->GetActorLocation();
	this->SetActorLocation(FVector(playerLocation.X,0,400.0f));
}

void AStarWitchMark::DestroyMyself()
{
	this->Destroy();
}

void AStarWitchMark::SpawnThunder()
{
	AStarWitchThunder* thunder = nullptr;
	thunder = GetWorld()->SpawnActor<AStarWitchThunder>(Effects_Thunder, GetActorLocation(), GetActorRotation(), spawnInfo);

}
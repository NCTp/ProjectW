// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitchBall.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStarWitchBall::AStarWitchBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStarWitchBall::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AStarWitchBall::DestroyMyself, 3.0f, false);

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

// Called every frame
void AStarWitchBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
	FVector playerLocation = Player->GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());

	if (dotProduct < 0) // player is left of starwitch
	{
		
	}
	else // player is right of starwitch
	{

	}

}

void AStarWitchBall::DestroyMyself()
{
	this->Destroy();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchGimmick01Manager.h"
#include "Engine/World.h"

#include "NWGimmick01EnemySpawnPoint.h"
#include "NWGimmick01LaserSpawnPoint.h"
#include "NWGimmick01ChainSpawnPoint.h"
#include "NightWitchGhoul.h"


// Sets default values
ANightWitchGimmick01Manager::ANightWitchGimmick01Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isActive = false;

	spawnDelay = 0.0f;
}

// Called when the game starts or when spawned
void ANightWitchGimmick01Manager::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
}

void ANightWitchGimmick01Manager::SpawnEnemy_Imp()
{
	int const index = FMath::RandRange(0, 11);

	FVector const point = GetPortalPoints()->GetSpawnPoint(index);
	FVector const globalPoint = GetPortalPoints()->GetActorTransform().TransformPosition(point);

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	World->SpawnActor<ANightWitchGhoul>(Ghoul, globalPoint, FRotator(0.0f, 0.0f, 0.0f), spawnParams);
}

void ANightWitchGimmick01Manager::SpawnEnemy()
{
	SpawnEnemy_Imp();
}

// Called every frame
void ANightWitchGimmick01Manager::Tick(float DeltaTime)
{
	if (isActive)
	{
		Super::Tick(DeltaTime);

		spawnDelay += DeltaTime;
		if (spawnDelay >= 3.0f)
		{
			spawnDelay = 0.0f;
			SpawnEnemy();
		}
	}
}

ANWGimmick01EnemySpawnPoint* ANightWitchGimmick01Manager::GetPortalPoints()
{
	return EnemySpawnPoint;
}


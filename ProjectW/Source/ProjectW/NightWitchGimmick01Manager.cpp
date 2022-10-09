// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchGimmick01Manager.h"

#include "NWGimmick01EnemySpawnPoint.h"
#include "NWGimmick01LaserSpawnPoint.h"
#include "NWGimmick01ChainSpawnPoint.h"

// Sets default values
ANightWitchGimmick01Manager::ANightWitchGimmick01Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isActive = false;
}

// Called when the game starts or when spawned
void ANightWitchGimmick01Manager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANightWitchGimmick01Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

ANWGimmick01EnemySpawnPoint* ANightWitchGimmick01Manager::GetPortalPoints()
{
	return EnemySpawnPoint;
}


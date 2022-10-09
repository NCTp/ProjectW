// Fill out your copyright notice in the Description page of Project Settings.


#include "NWGimmick01EnemySpawnPoint.h"

// Sets default values
ANWGimmick01EnemySpawnPoint::ANWGimmick01EnemySpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

FVector ANWGimmick01EnemySpawnPoint::GetSpawnPoint(int const index) const
{
	return SpawnPoints[index];
}

int ANWGimmick01EnemySpawnPoint::PointNum() const
{
	return SpawnPoints.Num();
}

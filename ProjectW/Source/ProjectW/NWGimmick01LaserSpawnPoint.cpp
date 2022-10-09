// Fill out your copyright notice in the Description page of Project Settings.


#include "NWGimmick01LaserSpawnPoint.h"

// Sets default values
ANWGimmick01LaserSpawnPoint::ANWGimmick01LaserSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FVector ANWGimmick01LaserSpawnPoint::GetSpawnPoint(int const index) const
{
	return SpawnPoints[index];
}

int ANWGimmick01LaserSpawnPoint::PointNum() const
{
	return SpawnPoints.Num();
}

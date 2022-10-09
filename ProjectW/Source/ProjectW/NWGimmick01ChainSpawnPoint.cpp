// Fill out your copyright notice in the Description page of Project Settings.


#include "NWGimmick01ChainSpawnPoint.h"

// Sets default values
ANWGimmick01ChainSpawnPoint::ANWGimmick01ChainSpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

FVector ANWGimmick01ChainSpawnPoint::GetSpawnPoint(int const index) const
{
	return SpawnPoints[index];
}

int ANWGimmick01ChainSpawnPoint::PointNum() const
{
	return SpawnPoints.Num();
}

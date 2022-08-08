// Fill out your copyright notice in the Description page of Project Settings.

#include "NightWitchTeleportPoint.h"

// Sets default values
ANightWitchTeleportPoint::ANightWitchTeleportPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

FVector ANightWitchTeleportPoint::GetTeleportPoint(int const index) const
{
	return TeleportPoints[index];
}

int ANightWitchTeleportPoint::PointNum() const
{
	return TeleportPoints.Num();
}

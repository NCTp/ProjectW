// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchChain.h"

ANightWitchChain::ANightWitchChain()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InitialLifeSpan = 2.0f;

}

void ANightWitchChain::BeginPlay()
{
	Super::BeginPlay();

}

void ANightWitchChain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
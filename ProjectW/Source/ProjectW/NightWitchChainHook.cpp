// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchChainHook.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ANightWitchChainHook::ANightWitchChainHook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(RootComponent);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));


}

// Called when the game starts or when spawned
void ANightWitchChainHook::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANightWitchChainHook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


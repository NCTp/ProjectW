// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
		
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement"));
	ProjectileMovement->InitialSpeed = 5000.0f;
	ProjectileMovement->MaxSpeed = 5000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	PaperFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Paper Flipbook"));
	PaperFlipbook->SetupAttachment(RootComponent);

	InitialLifeSpan = 3.0f;
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();		
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


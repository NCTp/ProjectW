// Fill out your copyright notice in the Description page of Project Settings.

#include "NightWitchChainPortal.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CableActor.h"
#include "CableComponent.h"
#include "ProjectWCharacter.h"
#include "NightWitchChain.h"
#include "NightWitchChainHook.h"

// Sets default values
ANightWitchChainPortal::ANightWitchChainPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	Flipbook->SetupAttachment(RootComponent);

	InitialLifeSpan = 2.0f;
}

// Called when the game starts or when spawned
void ANightWitchChainPortal::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
	
	Player = Cast<AProjectWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	m_targetLocation = Player->GetActorLocation();

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	ChainHookRef = World->SpawnActor<ANightWitchChainHook>(ChainHook, GetActorTransform(), spawnParams);
	FVector startLocation = GetActorLocation();
	FVector targetLocation = Player->GetActorLocation();
	FVector direction = (targetLocation - startLocation).GetSafeNormal();
	ChainHookRef->ProjectileMovement->Velocity = direction * 3000.0f;

	ChainRef = World->SpawnActor<ANightWitchChain>(Chain, GetActorTransform(), spawnParams);
	ChainRef->CableComponent->SetAttachEndTo(ChainHookRef, FName(TEXT("None")));
}

// Called every frame
void ANightWitchChainPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


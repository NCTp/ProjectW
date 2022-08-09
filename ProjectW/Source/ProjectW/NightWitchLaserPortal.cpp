// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchLaserPortal.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "ProjectWCharacter.h"
#include "NightWitchLaser.h"

// Sets default values
ANightWitchLaserPortal::ANightWitchLaserPortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Flipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	Flipbook->SetupAttachment(RootComponent);

	bLaserSpawned = false;
}

// Called when the game starts or when spawned
void ANightWitchLaserPortal::BeginPlay()
{
	Super::BeginPlay();
	
	World = GetWorld();

	Player = Cast<AProjectWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	m_targetLocation = Player->GetActorLocation();
}

void ANightWitchLaserPortal::SpawnLaser()
{

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	LaserRef = World->SpawnActor<ANightWitchLaser>(Laser, GetActorTransform(), spawnParams);
}


// Called every frame
void ANightWitchLaserPortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bLaserSpawned)
	{
		timer += DeltaTime;

		if (timer >= 2.0f)
		{
			SpawnLaser();

			timer = 0.0f;
			bLaserSpawned = true;
		}
	}

	if (bLaserSpawned)
	{
		timer += DeltaTime;

		if(timer >= 2.0f)
		{
			Destroy();
		}
	}
}


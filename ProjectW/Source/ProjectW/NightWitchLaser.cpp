// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchLaser.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "ProjectWCharacter.h"

// Sets default values
ANightWitchLaser::ANightWitchLaser()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Cylinder->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ANightWitchLaser::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();

	Player = Cast<AProjectWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	m_targetLocation = Player->GetActorLocation();

	FRotator rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), m_targetLocation);
	rot.Pitch -= 90.0f;

	Cylinder->SetWorldRotation(rot);
}

// Called every frame
void ANightWitchLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


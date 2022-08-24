// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitchRotatingVolt.h"
#include "Kismet/GameplayStatics.h"
#include "StarWitch.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)
// Sets default values
AStarWitchRotatingVolt::AStarWitchRotatingVolt()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_isRotating = true;
	m_isShooting = false;
	m_isLockingOn = false;

}

// Called when the game starts or when spawned
void AStarWitchRotatingVolt::BeginPlay()
{
	Super::BeginPlay();
	// Check the starwitch and player in the scene
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStarWitch::StaticClass(), starWitch);
	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	Dimensions = FVector(100, 0, 0);
	AxisVector = FVector(0,1,0);
	multiplier = 150.0f;
}

// Called every frame
void AStarWitchRotatingVolt::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (m_isRotating)
	{
		AStarWitchRotatingVolt::Rotate(DeltaTime);
	}
	else if (m_isShooting)
	{
		AStarWitchRotatingVolt::Shoot(DeltaTime);
	}

	FTimerHandle shootTimer;
	GetWorldTimerManager().SetTimer(shootTimer, this, &AStarWitchRotatingVolt::ChangeState, 2.0f, false);
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AStarWitchRotatingVolt::DestroyMyself, 10.0f, false);
}

void AStarWitchRotatingVolt::DestroyMyself()
{
	this->Destroy();
}

void AStarWitchRotatingVolt::Rotate(float DeltaTime)
{

	if (starWitch[0])
	{
		PrintString(TEXT("Rotating"));
	}
	//PrintString(TEXT("Rotating"));
	FVector NewLocation = starWitch[0]->GetActorLocation();
	AngleAxis += DeltaTime * multiplier;

	//if (AngleAxis > 360.0f)
		//AngleAxis = 0.0f;

	FVector RotateValue = Dimensions.RotateAngleAxis(AngleAxis, AxisVector);
	NewLocation.X += RotateValue.X;
	NewLocation.Y += RotateValue.Y;
	NewLocation.Z += RotateValue.Z;

	SetActorLocation(NewLocation);
}

void AStarWitchRotatingVolt::Shoot(float DeltaTime)
{
	if(!m_isLockingOn)
	{
		PlayerLocation = Player->GetActorLocation();
		PlayerDirection = (PlayerLocation - GetActorLocation());
		m_isLockingOn = true;
	}

	FVector NewLocation = GetActorLocation();
	NewLocation.X += PlayerDirection.X * 5.0f * DeltaTime;
	NewLocation.Y += PlayerDirection.Y * 5.0f * DeltaTime;
	NewLocation.Z += PlayerDirection.Z * 5.0f * DeltaTime;

	SetActorLocation(NewLocation);

}

void AStarWitchRotatingVolt::ChangeState()
{
	m_isShooting = true;
	m_isRotating = false;
}
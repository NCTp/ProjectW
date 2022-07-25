// Fill out your copyright notice in the Description page of Project Settings.

#include "StarWitch.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"


// Sets default values
AStarWitch::AStarWitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipBook"));


}

// Called when the game starts or when spawned
void AStarWitch::BeginPlay()
{
	Super::BeginPlay();
	StarWitchState = EActorState::StarWitchState_Idle;

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

// Called every frame
void AStarWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	StateMachine(DeltaTime);
	UpdateAnimation();
	
}
// Get Damage
void AStarWitch::GetDamage()
{
	if (health > 0)
		health--;

}

// Flip the sprites
void AStarWitch::Flip()
{
	const FVector PlayerVelocity = GetVelocity();
	float TravelDirection = PlayerVelocity.X;

	if (TravelDirection < 0.0f)
	{
		SetActorRotation(FRotator(0.0, 180.0f, 0.0f));
	}
	else if (TravelDirection > 0.0f)
	{
		SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	}

} 

void AStarWitch::UpdateAnimation()
{
	Flip();
	UPaperFlipbook* anim = nullptr;

	if (StarWitchState == EActorState::StarWitchState_Idle)
	{
		anim = IdleAnim;
	}
	else if (StarWitchState == EActorState::StarWitchState_Walking)
	{
		anim = WalkingAnim;
	}
	else if (StarWitchState == EActorState::StarWitchState_CounterReady)
	{
		anim = CounterReadyAnim;
	}
	else if (StarWitchState == EActorState::StarWitchState_Attack_01)
	{
		anim = CastingAnim;
	}
	else if (StarWitchState == EActorState::StarWitchState_Attack_02)
	{
		anim = CastingAnim_02;
	}

	// Set Flipbook to anim
	FlipbookComponent->SetFlipbook(anim);
}

void AStarWitch::SetState(EActorState newState)
{
	if (StarWitchState != EActorState::StarWitchState_Dead)
		StarWitchState = newState;
}

void AStarWitch::StateIdle()
{
	float distance = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
	if (Player && distance <= 210.0f)
	{
		StarWitchState = EActorState::StarWitchState_Idle;
		UE_LOG(LogTemp, Log, TEXT("Close, Idle"));
	}
	else if (Player && distance <= 400.0f && distance > 210.0f)
	{
		StarWitchState = EActorState::StarWitchState_Walking;
		//UE_LOG(LogTemp, Log, TEXT("Far, Chase the player"));
	}
}

void AStarWitch::StateWalk(float DeltaTime)
{
	float distance = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
	if (Player && distance <= 200.0f)
	{
		StarWitchState = EActorState::StarWitchState_Idle;
		//UE_LOG(LogTemp, Log, TEXT("Close, Idle"));
	}
	else if (Player && distance <= 400.0f && distance > 200.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Far, Chase the player"));

		
		FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
		float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());

		// Move Location
		FVector CurrentLocation;
		float speed;
		CurrentLocation = this->GetActorLocation();
		speed = 100.0f;
		if (dotProduct >= 0)
		{
			CurrentLocation.X -= speed * DeltaTime;
		}
		else 
		{
			CurrentLocation.X += speed * DeltaTime;
		}
		SetActorLocation(CurrentLocation);

	}


	
}

void AStarWitch::StateCloseToTarget()
{
	if (Player && FVector::Distance(Player->GetActorLocation(), GetActorLocation()) <= 200.0f)
	{
		StarWitchState = EActorState::StarWitchState_Idle;
		UE_LOG(LogTemp, Log, TEXT("Close"));
	}
}

void AStarWitch::StateFarFromTarget()
{
	if (Player && FVector::Distance(Player->GetActorLocation(), GetActorLocation()) <= 400.0f)
	{
		StarWitchState = EActorState::StarWitchState_Walking;
		UE_LOG(LogTemp, Log, TEXT("Far"));
	}
}
void AStarWitch::StateMachine(float DeltaTime)
{
	switch (StarWitchState)
	{
	case EActorState::StarWitchState_Idle :
		StateIdle();
		break;
	case EActorState::StarWitchState_Walking :
		StateWalk(DeltaTime);
		break;
	}
	
}


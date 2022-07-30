// Fill out your copyright notice in the Description page of Project Settings.

#include "StarWitch.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)
// Sets default values
AStarWitch::AStarWitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipBook"));
	FlipbookComponent->GetAbsoluteRotationPropertyName();
	m_isRight = true;
	m_startFighting = true;
	m_isTeleporting = false;
}

// Called when the game starts or when spawned
void AStarWitch::BeginPlay()
{
	Super::BeginPlay();
	StarWitchState = EActorState::StarWitchState_Teleport;

	Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	// Call the function every 3 seconds, ensure the timer loops and delay first call for half a second.
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &AStarWitch::TimerFunction, 2.0f, true, 0.5f);
}

// Called every frame
void AStarWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());

	if (dotProduct < 0)
	{
		if (m_isRight)
			Flip();
	}
	else
	{
		if (!m_isRight)
			Flip();

	}

	StateMachine(DeltaTime);
	UpdateAnimation();
	
}
/*
void AStarWitch::TimerFunction()
{
	// Track the number of times we're calling the function
	CallTracker--;
	// If CallTracker is zero then print A andf Clear the Timer to stop it looping, Otherwise print B.
	CallTracker == 0 ? PrintString("Finished Looping"), GetWorldTimerManager().ClearTimer(TimerHandle) : PrintString("Timer Called");
	// Print the number of loops the tracker has remaining.
	PrintString(FString::Printf(TEXT("Calls Remaining: &d"), CallTracker));
}
*/
// Get Damage
void AStarWitch::GetDamage()
{
	if (health > 0)
		health--;

}

// Flip the sprites
void AStarWitch::Flip()
{
	FVector scale = this->GetActorScale();
	scale.X *= -1;
	SetActorScale3D(scale);
	m_isRight = !m_isRight;
} 

void AStarWitch::UpdateAnimation()
{
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
	else if (StarWitchState == EActorState::StarWitchState_Teleport)
	{
		anim = IdleAnim;
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
	if (Player && distance <= 300.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Close, Idle"));
	}
	else if (Player && distance > 300.0f)
	{
		SetState(EActorState::StarWitchState_Walking);
	}
}

void AStarWitch::StateWalk(float DeltaTime)
{
	float distance = FVector::Distance(GetActorLocation(), Player->GetActorLocation());
	if (Player && distance <= 200.0f)
	{
		//Teleport();
		SetState(EActorState::StarWitchState_Idle);
	}
	else if (Player && distance <= 1000.0f && distance > 300.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Far, Chase the player"));

		FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
		float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());

		// Move Location
		FVector CurrentLocation;
		float speed;
		CurrentLocation = this->GetActorLocation();
		speed = 100.0f;
		if (dotProduct < 0) // player is left of starwitch
			CurrentLocation.X -= speed * DeltaTime;
		else // player is right of starwitch
			CurrentLocation.X += speed * DeltaTime;

		SetActorLocation(CurrentLocation);
	}
	else if (Player && distance > 2000.0f)
	{
		SetState(EActorState::StarWitchState_Teleport);
	}
}

void AStarWitch::StateCloseToTarget()
{
}

void AStarWitch::StateFarFromTarget()
{
}

void AStarWitch::Teleport()
{
	UE_LOG(LogTemp, Log, TEXT("TeleportStart"));

	FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
	FVector playerLocation = Player->GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());
	FVector teleportLocationOfRight = FVector(playerLocation.X + 300.0f, playerLocation.Y, playerLocation.Z);
	FVector teleportLocationOfLeft = FVector(playerLocation.X - 300.0f, playerLocation.Y, playerLocation.Z);
	if (dotProduct < 0) // player is left of starwitch
		SetActorLocation(teleportLocationOfLeft);
	else // player is right of starwitch
		SetActorLocation(teleportLocationOfRight);

	TeleportCounter--;
	PrintString(FString::Printf(TEXT("Calls Remaining: %d"), TeleportCounter));
	//SetState(EActorState::StarWitchState_Idle);
	if (TeleportCounter == 0)
	{
		PrintString("Finished Looping");
		TeleportCounter = 3;
		m_isTeleporting = false;
		GetWorldTimerManager().ClearTimer(TeleportTimerHandle);
		SetState(EActorState::StarWitchState_Idle);

	}
}

void AStarWitch::StateTeleport()
{
	if (!m_isTeleporting)
	{
		m_isTeleporting = true;
		GetWorldTimerManager().SetTimer(TeleportTimerHandle, this, &AStarWitch::Teleport, 1.0f, true, 0.5f);
	}
	
}
void AStarWitch::ShootLazer()
{

}
void AStarWitch::ShootBall()
{

}
void AStarWitch::StateMachine(float DeltaTime)
{
	switch (StarWitchState)
	{
	case EActorState::StarWitchState_Idle :
		AStarWitch::StateIdle();
		break;
	case EActorState::StarWitchState_Walking :
		AStarWitch::StateWalk(DeltaTime);
		break;
	case EActorState::StarWitchState_Teleport:
		AStarWitch::StateTeleport();
		break;
	}
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "StarWitch.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "PaperFlipbookComponent.h"
#include "StarWitchTeleportEffects.h"
#include "StarWitchBall.h"
#include "StarWitchLaser.h"

#include <random>

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)
// Sets default values
AStarWitch::AStarWitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipBook"));
	FlipbookComponent->GetAbsoluteRotationPropertyName();
	health = 100;
	m_isRight = true;
	m_startFighting = true;
	m_isTeleporting = false;
	m_isCastingMagic01 = false;
	m_isPhaseOne = true;
	m_isPhaseTwo = false;
	m_isPhaseThree = false;
	m_isDead = false;
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

	// Flip 
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

	// Phase 
	if (health >= 70 && health <= 100)
	{
		m_isPhaseOne = true;
		m_isPhaseTwo = false;
		m_isPhaseThree = false;
	}
	else if (health >= 30 && health < 70)
	{
		m_isPhaseOne = false;
		m_isPhaseTwo = true;
		m_isPhaseThree = false;
	}
	else if (health > 0 && health < 30)
	{
		m_isPhaseOne = false;
		m_isPhaseTwo = false;
		m_isPhaseThree = true;
	}
	else if (health <= 0)
	{
		m_isPhaseThree = false;
		m_isDead = true;
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
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 3); // 0 ~ 3
	
	if (Player && distance <= 200.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("Close, Idle"));
		if (dis(gen) == 0)
		{
			SetState(EActorState::StarWitchState_Magic_01);
		}
		else if (dis(gen) == 1)
		{
			SetState(EActorState::StarWitchState_Magic_01);
		}
		else if (dis(gen) == 2)
		{
			SetState(EActorState::StarWitchState_Teleport);
		}
	}
	else if (Player && distance > 200.0f)
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
	else if (Player && distance > 1500.0f)
	{
		AStarWitch::Teleport();
	}
}

void AStarWitch::Teleport()
{
	UE_LOG(LogTemp, Log, TEXT("TeleportStart"));

	FVector playerDirection = Player->GetActorLocation() - GetActorLocation();
	FVector playerLocation = Player->GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), playerDirection.GetSafeNormal());
	FVector teleportLocationOfRight = FVector(playerLocation.X + 300.0f, GetActorLocation().Y, GetActorLocation().Z);
	FVector teleportLocationOfLeft = FVector(playerLocation.X - 300.0f, GetActorLocation().Y, GetActorLocation().Z);

	AStarWitchTeleportEffects* teleportEffect = nullptr;
	AStarWitchBall* ball = nullptr;
	AStarWitchLaser* laser = nullptr;

	//SetState(EActorState::StarWitchState_Idle);
	if (TeleportCounter == 0)
	{
		PrintString("Finished Looping");
		TeleportCounter = 3;
		m_isTeleporting = false;
		GetWorldTimerManager().ClearTimer(TeleportTimerHandle);
		SetState(EActorState::StarWitchState_Idle);
		AStarWitch::ShootLazer();
	}
	else
	{
		PrintString(FString::Printf(TEXT("Calls Remaining: %d"), TeleportCounter));
		if (!m_isRight) // player is left of starwitch
		{
			SetActorLocation(teleportLocationOfLeft);
			teleportEffect = GetWorld()->SpawnActor<AStarWitchTeleportEffects>(Effects_Teleport, GetActorLocation(), GetActorRotation(), spawnInfo);
			if (StarWitchState == EActorState::StarWitchState_Teleport)
			{
				AStarWitch::ShootBall(0.0f);
			}
		}
		else // player is right of starwitch
		{
			SetActorLocation(teleportLocationOfRight);
			teleportEffect = GetWorld()->SpawnActor<AStarWitchTeleportEffects>(Effects_Teleport, GetActorLocation(), GetActorRotation(), spawnInfo);
			if (StarWitchState == EActorState::StarWitchState_Teleport)
			{
				AStarWitch::ShootBall(180.0f);
			}

		}
		TeleportCounter--;
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
	AStarWitchLaser* laser = nullptr;

	if (!m_isRight)
		laser = GetWorld()->SpawnActor<AStarWitchLaser>(Projectile_Laser, GetActorLocation(), FRotator(0, 180.0f, 0), spawnInfo);
	else
		laser = GetWorld()->SpawnActor<AStarWitchLaser>(Projectile_Laser, GetActorLocation(), FRotator(0, 0, 0), spawnInfo);

}
void AStarWitch::ShootBall(float angle)
{
	AStarWitchBall* ball = nullptr;

	ball = GetWorld()->SpawnActor<AStarWitchBall>(Projectile_Ball, GetActorLocation(), FRotator(angle, 0, 0), spawnInfo);


}
void AStarWitch::Magic01()
{

	if (MagicCounter01 == 0)
	{
		MagicCounter01 = 3;
		m_isCastingMagic01 = false;
		GetWorldTimerManager().ClearTimer(MagicTimerHandle_0);
		SetState(EActorState::StarWitchState_Idle);
	}
	else if (MagicCounter01 % 2 == 0) // Â¦¼ö
	{
		if (m_isRight)
		{
			AStarWitch::ShootBall(0.0f);
			AStarWitch::ShootBall(15.0f);
			AStarWitch::ShootBall(30.0f);
			AStarWitch::ShootBall(45.0f);
		}
		else
		{
			AStarWitch::ShootBall(180.0f);
			AStarWitch::ShootBall(165.0f);
			AStarWitch::ShootBall(150.0f);
			AStarWitch::ShootBall(135.0f);
		}
		MagicCounter01--;

	}
	else if (MagicCounter01 % 2 == 1) // È¦¼ö
	{
		if (m_isRight)
		{
			AStarWitch::ShootBall(15.0f);
			AStarWitch::ShootBall(30.0f);
			AStarWitch::ShootBall(45.0f);
			AStarWitch::ShootBall(60.0f);
		}
		else
		{
			AStarWitch::ShootBall(165.0f);
			AStarWitch::ShootBall(150.0f);
			AStarWitch::ShootBall(135.0f);
			AStarWitch::ShootBall(120.0f);
		}
		MagicCounter01--;
	}
}

void AStarWitch::StateMagic01() 
{
	if (!m_isCastingMagic01)
	{
		m_isCastingMagic01 = true;
		GetWorldTimerManager().SetTimer(MagicTimerHandle_0, this, &AStarWitch::Magic01, 1.0f, true, 0.5f);
	}

}

void AStarWitch::Magic02()
{

}

void AStarWitch::StateMagic02()
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
	case EActorState::StarWitchState_Magic_01:
		AStarWitch::StateMagic01();
		break;
	case EActorState::StarWitchState_Magic_02:
		AStarWitch::StateMagic02();
		break;
	}
}


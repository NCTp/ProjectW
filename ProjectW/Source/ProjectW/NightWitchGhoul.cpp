// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchGhoul.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

#include "ProjectWCharacter.h"


ANightWitchGhoul::ANightWitchGhoul()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	isLookingRight = true;

	isAttacking = false;
	isNextAttackReady = true;

	attackTimer = 0.0f;
	attackDelay = 0.0f;
}

void ANightWitchGhoul::BeginPlay()
{	
	Super::BeginPlay();

	ActiveState = EGhoulState::IDLE;

	World = GetWorld();

	Player = Cast<AProjectWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ANightWitchGhoul::Flip()
{
	FVector scale = GetActorScale();
	scale.X *= -1;
	SetActorScale3D(scale);
	isLookingRight = !isLookingRight;
}

void ANightWitchGhoul::UpdateCharacter()
{
	FVector targetDirection = Player->GetActorLocation() - GetActorLocation();

	float dot = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());

	if (dot < 0.0f)
	{
		if (isLookingRight)
		{
			Flip();
		}
	}
	else
	{
		if (!isLookingRight)
		{
			Flip();
		}
	}

}


void ANightWitchGhoul::TickStateMachine()
{
	switch (ActiveState)
	{
	case EGhoulState::IDLE:
		StateIdle();
		break;

	case EGhoulState::CHASE:
		StateChase();
		break;

	case EGhoulState::ATTACK:
		StateAttack();
		break;

	case EGhoulState::DEAD:
		StateDead();
		break;

	default:
		break;
	}
}

void ANightWitchGhoul::SetState(EGhoulState newState)
{
	if (ActiveState != EGhoulState::DEAD)
	{
		ActiveState = newState;
	}
}

void ANightWitchGhoul::StateIdle()
{
	if (Player)
	{
		if (!isAttacking)
		{
			if (GetDistanceTo(Player) <= 10.0f)
			{
				SetState(EGhoulState::ATTACK);
			}
			else
			{
				SetState(EGhoulState::CHASE);
			}
		}		
	}
}

void ANightWitchGhoul::StateChase()
{
	FVector targetDirection = Player->GetActorLocation() - GetActorLocation();
	float dot = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());

	// Move Location
	FVector currentLocation = GetActorLocation();
	float speed = 200.0f;

	if (dot < 0) // player is left of Ghoul
	{
		currentLocation.X -= speed * World->DeltaTimeSeconds;
	}
	else // player is right of Ghoul
	{
		currentLocation.X += speed * World->DeltaTimeSeconds;
	}

	if (Player->GetActorLocation().Y > GetActorLocation().Y)
	{
		currentLocation.Y += speed * World->DeltaTimeSeconds;
	}
	else
	{
		currentLocation.Y -= speed * World->DeltaTimeSeconds;
	}

	SetActorLocation(currentLocation);

	SetState(EGhoulState::IDLE);
}

void ANightWitchGhoul::StateAttack()
{
	if (isNextAttackReady)
	{
		isNextAttackReady = false;
		isAttacking = true;

		UE_LOG(LogTemp, Log, TEXT("ATTACK"));

		// Attack
	}
	else
	{
		SetState(EGhoulState::IDLE);
	}
}

void ANightWitchGhoul::StateDead()
{
}

void ANightWitchGhoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateCharacter();

	TickStateMachine();

	if (isAttacking)
	{
		attackTimer += DeltaTime;
		if (attackTimer >= 2.0f)
		{
			isAttacking = false;
			attackTimer = 0.0f;
		}
	}

	if (!isNextAttackReady)
	{
		attackDelay += DeltaTime;
		if (attackDelay >= 1.0f)
		{
			isNextAttackReady = true;
			attackDelay = 0.0f;
		}
	}
}

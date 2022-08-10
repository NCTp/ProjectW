// Fill out your copyright notice in the Description page of Project Settings.

#include "NightWitch.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "NavigationSystem.h"
#include "Math/UnrealMathUtility.h"
#include "DrawDebugHelpers.h"

#include "NightWitchGhoul.h"
#include "NightWitchLaserPortal.h"
#include "ProjectWCharacter.h"

// Sets default values
ANightWitch::ANightWitch()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 200.0f;
	GetCharacterMovement()->MaxFlySpeed = 200.0f;


	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	isMoving = false;
	isAttacking = false;
	isStumbling = false;
	interruptable = false;
	lastStumbleIndex = 0;

	isNextAttackReady = false;
	isNextMoveReady = true;

	isLookingRight = true;

	isMoveEnd = false;

	attackDelay = 0.0f;
	moveDelay = 0.0f;

	spawnLaserCounter = 3;

	health = 100;
	hitCount = 5;
	phase = 1;
}

// Called when the game starts or when spawned
void ANightWitch::BeginPlay()
{
	Super::BeginPlay();

	m_targetLocation = GetActorLocation();

	ActiveState = EState::IDLE;

	Spell = ESpell::DEFAULT;

	World = GetWorld();

	Target = UGameplayStatics::GetPlayerPawn(World, 0);

	Player = Cast<AProjectWCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	AIController = Cast<AAIController>(GetController());
}

void ANightWitch::Flip()
{
	FVector scale = GetActorScale();
	scale.X *= -1;
	SetActorScale3D(scale);
	isLookingRight = !isLookingRight;
}

void ANightWitch::UpdateAnimation()
{
}

void ANightWitch::UpdateCharacter()
{
	FVector targetDirection = Target->GetActorLocation() - GetActorLocation();

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

void ANightWitch::TickStateMachine()
{
	switch (ActiveState)
	{
	case EState::IDLE:
		StateIdle();
		break;

	case EState::RUNAWAY:
		StateRunaway();
		break;

	case EState::TELEPORT:
		StateTeleport();
		break;

	case EState::ATTACK:
		StateAttack();
		break;

	case EState::STUMBLE:
		StateStumble();
		break;

	case EState::TAUNT:
		StateTaunt();
		break;

	case EState::DEAD:
		StateDead();
		break;

	default:
		break;
	}
}

void ANightWitch::SetState(EState newState)
{
	if (ActiveState != EState::DEAD)
	{
		ActiveState = newState;
	}
}

void ANightWitch::StateIdle()
{
	if (Target)
	{
		if (FMath::RandRange(0, 1) == 0)
		{
			if (!isMoving)
			{
				if (isNextMoveReady)
				{
					isNextMoveReady = false;

					if (FMath::RandRange(0, 1) == 0)
					{
						SetState(EState::RUNAWAY);
					}
					else
					{
						SetState(EState::TELEPORT);
					}
				}
				else
				{
					SetState(EState::IDLE);
				}
			}
		}
		else
		{
			SetState(EState::ATTACK);
		}
	}
}

void ANightWitch::StateRunaway()
{
	UE_LOG(LogTemp, Log, TEXT("RUNAWAY"));

	float distance = FVector::Distance(GetActorLocation(), Target->GetActorLocation());

	isMoving = true;

	// After arrive at target location, update target location
	if (CheckArriveAtTarget())
	{
		SetNewTargetLocation();

		SetState(EState::IDLE);
	}

	FVector targetDirection = m_targetLocation - GetActorLocation();
	float dot = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());

	// Move Location
	FVector currentLocation = GetActorLocation();
	float speed = 500.0f;

	if (dot < 0) // player is left of NightWitch
		currentLocation.X -= speed * World->DeltaTimeSeconds;
	else // player is right of NightWitch
		currentLocation.X += speed * World->DeltaTimeSeconds;

	SetActorLocation(currentLocation);
}

void ANightWitch::StateTeleport()
{
	UE_LOG(LogTemp, Log, TEXT("Teleport"));

	int const index = FMath::RandRange(0, 3);

	FVector const point = GetTeleportPoints()->GetTeleportPoint(index);
	FVector const globalPoint = GetTeleportPoints()->GetActorTransform().TransformPosition(point);

	SetActorLocation(globalPoint);

	isMoveEnd = true;

	SetState(EState::IDLE);
}

void ANightWitch::StateAttack()
{
	if (isNextAttackReady)
	{
		isNextAttackReady = false;
		isAttacking = true;

		SelectSpell();
	}
	else
	{
		SetState(EState::IDLE);
	}
}

void ANightWitch::StateStumble()
{

}

void ANightWitch::StateTaunt()
{

}

void ANightWitch::StateDead()
{

}

void ANightWitch::SelectSpell()
{
	switch (Spell)
	{
	case ESpell::DEFAULT:
		RandomSelect();
		break;

	case ESpell::CHAIN:
		SpellChain();
		SetSpell(ESpell::DEFAULT);
		break;

	case ESpell::LASER:
		SpellLaser();
		SetSpell(ESpell::DEFAULT);
		break;

	case ESpell::SUMMON_GHOUL:
		SpellSummonGhoul();
		SetSpell(ESpell::DEFAULT);
		break;

	case ESpell::SUMMON_JORMUNGAND:
		SpellSummonJormungand();
		SetSpell(ESpell::DEFAULT);
		break;

	case ESpell::HEXAGRAM:
		SpellHexagram();
		SetSpell(ESpell::DEFAULT);
		break;

	default:
		break;
	}
}

void ANightWitch::RandomSelect()
{
	int32 spellNum = 0;

	if (phase == 1)
	{
		spellNum = FMath::RandRange(1, 3);
	}
	else if (phase == 2)
	{
		spellNum = FMath::RandRange(1, 5);
	}

	if (spellNum == 1)
	{
		SetSpell(ESpell::CHAIN);
		// SetSpell(ESpell::LASER);
	}
	else if (spellNum == 2)
	{
		SetSpell(ESpell::LASER);
	}
	else if (spellNum == 3)
	{
		SetSpell(ESpell::SUMMON_GHOUL);
		// SetSpell(ESpell::LASER);
	}
	else if (spellNum == 4)
	{
		SetSpell(ESpell::SUMMON_JORMUNGAND);
	}
	else if (spellNum == 5)
	{
		SetSpell(ESpell::HEXAGRAM);
	}
}

void ANightWitch::SetSpell(ESpell newSpell)
{
	Spell = newSpell;
}

void ANightWitch::SpellChain()
{
	UE_LOG(LogTemp, Log, TEXT("SpellChain"));

	// Spell chain

	FVector origin = FVector::ZeroVector;
	FVector boxExtent = FVector::ZeroVector;
	float radius = 0.0f;

	UKismetSystemLibrary::GetComponentBounds(Player->GetCapsuleComponent(), origin, boxExtent, radius);
	DrawDebugSphere(World, origin, radius, 12, FColor(181, 0, 0), false, 2.0f, 0U, 2.0f);

	float randomAngle = FMath::RandRange(0.0f, 359.0f);

	FVector randomLocation = FVector(origin.X + (FMath::Sin(randomAngle) * (FMath::Cos(360.0f - randomAngle)) * (radius + 1000.0f)),
									 origin.Y + (FMath::Sin(randomAngle) * (FMath::Sin(360.0f - randomAngle)) * (radius + 1000.0f)),
									 UKismetMathLibrary::Abs(origin.Z + (FMath::Cos(randomAngle) * (radius + 1000.0f))));

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	World->SpawnActor<ANightWitchChainPortal>(Portal, randomLocation, FRotator(0.0f, 0.0f, 0.0f), spawnParams);

	isAttacking = false;
}

void ANightWitch::SpellLaser()
{
	UE_LOG(LogTemp, Log, TEXT("SpellLaser"));

	// Spell Laser
	
	/*
	for (int i = 0; i < 5; ++i)
	{
		randomAngle = FMath::RandRange(0.0f, 359.0f);

		randomLocation = FVector(origin.X + (FMath::Sin(randomAngle) * (FMath::Cos(360.0f - randomAngle)) * (radius + 300.0f)),
			origin.Y + (FMath::Sin(randomAngle) * (FMath::Sin(360.0f - randomAngle)) * (radius + 300.0f)),
			UKismetMathLibrary::Abs(origin.Z + (FMath::Cos(randomAngle) * (radius + 300.0f))));

		World->SpawnActor<ANightWitchLaserPortal>(LaserPortal, randomLocation, FRotator(0.0f, 0.0f, 0.0f), spawnParams);

	}
	*/

	float waitTime = 1.0f;
	GetWorldTimerManager().SetTimer(spellLaserTimeHandle, this, &ANightWitch::SpawnLaser, waitTime, true);


	isAttacking = false;
}

void ANightWitch::SpawnLaser()
{
	if(--spawnLaserCounter <= 0)
	{
		GetWorldTimerManager().ClearTimer(spellLaserTimeHandle);
		spawnLaserCounter = 3;
	}
	
	FVector origin = FVector::ZeroVector;
	FVector boxExtent = FVector::ZeroVector;
	FVector randomLocation = FVector::ZeroVector;
	float radius = 0.0f;
	float randomAngle = 0.0f;

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	UKismetSystemLibrary::GetComponentBounds(GetCapsuleComponent(), origin, boxExtent, radius);
	DrawDebugSphere(World, origin, radius, 12, FColor(0, 181, 0), false, 2.0f, 0U, 2.0f);
	randomAngle = FMath::RandRange(0.0f, 359.0f);

	randomLocation = FVector(origin.X + (FMath::Sin(randomAngle) * (FMath::Cos(360.0f - randomAngle)) * (radius + 300.0f)),
							 origin.Y + (FMath::Sin(randomAngle) * (FMath::Sin(360.0f - randomAngle)) * (radius + 300.0f)),
							 UKismetMathLibrary::Abs(origin.Z + (FMath::Cos(randomAngle) * (radius + 300.0f))));

	World->SpawnActor<ANightWitchLaserPortal>(LaserPortal, randomLocation, FRotator(0.0f, 0.0f, 0.0f), spawnParams);
}

void ANightWitch::SpellSummonGhoul()
{
	UE_LOG(LogTemp, Log, TEXT("SpellSummonGhoul"));

	// Spell Summon_Ghoul

	FVector myLocation = GetActorLocation();
	FVector origin = FVector::ZeroVector;
	FVector boxExtent = FVector::ZeroVector;
	FVector randomLocation = FVector::ZeroVector;
	float radius = 0.0f;
	float randomAngle = 0.0f;

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined;

	UKismetSystemLibrary::GetComponentBounds(GetCapsuleComponent(), origin, boxExtent, radius);
	DrawDebugSphere(World, origin, radius, 12, FColor(0, 0, 181), false, 2.0f, 0U, 2.0f);
	randomAngle = FMath::RandRange(0.0f, 359.0f);

	randomLocation = FVector(origin.X + (FMath::Sin(randomAngle) * (FMath::Cos(360.0f - randomAngle)) * (radius + 300.0f)),
							 origin.Y + (FMath::Sin(randomAngle) * (FMath::Sin(360.0f - randomAngle)) * (radius + 300.0f)),
							 myLocation.Z);

	World->SpawnActor<ANightWitchGhoul>(Ghoul, randomLocation, FRotator(0.0f, 0.0f, 0.0f), spawnParams);
	isAttacking = false;
}

void ANightWitch::SpellSummonJormungand()
{
	UE_LOG(LogTemp, Log, TEXT("SpellSummonJormungand"));

	// Spell Summon_Jormungand

	isAttacking = false;

}

void ANightWitch::SpellHexagram()
{
	UE_LOG(LogTemp, Log, TEXT("SpellHexagram"));

	// Spell Hexagram

	isAttacking = false;

}

bool ANightWitch::CheckArriveAtTarget()
{
	float fDistance = FVector::Distance(GetActorLocation(), m_targetLocation);

	if (fDistance <= 10.0f)
	{
		isMoving = false;
		isMoveEnd = true;

		return true;
	}
	return false;
}

void ANightWitch::SetNewTargetLocation()
{
	UE_LOG(LogTemp, Log, TEXT("Target Update"));

	FVector origin = GetActorLocation();
	FNavLocation loc;
	UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(World);

	// if (navSys->GetRandomPointInNavigableRadius(origin, 1500.0f, loc, nullptr))
	if (navSys->GetRandomReachablePointInRadius(origin, FMath::RandRange(1000.0f, 3000.0f), loc, nullptr))
	{
		m_targetLocation = FVector(loc.Location.X, origin.Y, origin.Z);
	}
}

void ANightWitch::MoveTimer(float DeltaTime)
{
	moveDelay += DeltaTime;

	if (moveDelay >= 3.0f)
	{
		moveDelay = 0.0f;
		isNextMoveReady = true;
		isMoveEnd = false;
	}
}

ANightWitchTeleportPoint* ANightWitch::GetTeleportPoints()
{
	return TeleportPoint;
}

// Called every frame
void ANightWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateCharacter();

	TickStateMachine();

	if (!isNextAttackReady)
	{
		attackDelay += DeltaTime;
		if (attackDelay >= 1.0f)
		{
			attackDelay = 0.0f;
			isNextAttackReady = true;
		}
	}

	if (isMoveEnd)
	{
		MoveTimer(DeltaTime);
	}

	/*
	if (!isNextMoveReady)
	{
		moveDelay += DeltaTime;
		if (moveDelay >= 3.0f)
		{
			moveDelay = 0.0f;
			isNextMoveReady = true;
		}
	}
	*/
}

// Called to bind functionality to input
void ANightWitch::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


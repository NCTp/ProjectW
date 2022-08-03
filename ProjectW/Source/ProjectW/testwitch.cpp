// Fill out your copyright notice in the Description page of Project Settings.


#include "testwitch.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "NavigationSystem.h"
#include "Math/UnrealMathUtility.h"


// Sets default values
Atestwitch::Atestwitch()
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

	attackDelay = 0.0f;
	moveDelay = 0.0f;

	health = 100;
	hitCount = 5;
	phase = 1;
}

// Called when the game starts or when spawned
void Atestwitch::BeginPlay()
{
	Super::BeginPlay();

	m_targetLocation = this->GetActorLocation();

	ActiveState = ETestState::IDLE;

	Spell = ESpell::DEFAULT;

	World = GetWorld();

	Target = UGameplayStatics::GetPlayerPawn(World, 0);

	AIController = Cast<AAIController>(GetController());
}

void Atestwitch::Flip()
{
	FVector scale = GetActorScale();
	scale.X *= -1;
	SetActorScale3D(scale);
	isLookingRight = !isLookingRight;
}

void Atestwitch::UpdateAnimation()
{
}

void Atestwitch::UpdateCharacter()
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

void Atestwitch::TickStateMachine()
{
	switch (ActiveState)
	{
	case ETestState::IDLE:
		StateIdle();
		break;

	case ETestState::RUNAWAY:
		StateRunaway();
		break;

	case ETestState::TELEPORT:
		StateTeleport();
		break;

	case ETestState::ATTACK:
		StateAttack();
		break;

	case ETestState::STUMBLE:
		StateStumble();
		break;

	case ETestState::TAUNT:
		StateTaunt();
		break;

	case ETestState::DEAD:
		StateDead();
		break;

	default:
		break;
	}
}

void Atestwitch::SetState(ETestState newState)
{
	if (ActiveState != ETestState::DEAD)
	{
		ActiveState = newState;
	}
}

void Atestwitch::StateIdle()
{
	if (Target)
	{
		if (FVector::Distance(Target->GetActorLocation(), GetActorLocation()) <= 1200.0f)
		{
			SetState(ETestState::RUNAWAY);
		}
	}
}

void Atestwitch::StateRunaway()
{
	float distance = FVector::Distance(this->GetActorLocation(), Target->GetActorLocation());

	if (distance <= 300.0f || hitCount == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("RUNAWAY"));

		// After arrive at target location, update target location
		if (CheckArriveAtTarget())
		{
			SetNewTargetLocation();
		}

		AIController->MoveToLocation(m_targetLocation);
	}
	else
	{
		SetState(ETestState::ATTACK);
	}
}

void Atestwitch::StateTeleport()
{

}

void Atestwitch::StateAttack()
{
	if (isNextAttackReady)
	{
		isNextAttackReady = false;
		isAttacking = true;

		SelectSpell();
	}
	else
	{
		SetState(ETestState::IDLE);
	}
}

void Atestwitch::StateStumble()
{

}

void Atestwitch::StateTaunt()
{

}

void Atestwitch::StateDead()
{
	
}

void Atestwitch::SelectSpell()
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

void Atestwitch::RandomSelect()
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
	}
	else if (spellNum == 2)
	{
		SetSpell(ESpell::LASER);
	}
	else if (spellNum == 3)
	{
		SetSpell(ESpell::SUMMON_GHOUL);
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

void Atestwitch::SetSpell(ESpell newSpell)
{
	Spell = newSpell;
}

void Atestwitch::SpellChain()
{
	UE_LOG(LogTemp, Log, TEXT("SpellChain"));

	// Spell chain

	isAttacking = false;
}

void Atestwitch::SpellLaser()
{
	UE_LOG(LogTemp, Log, TEXT("SpellLaser"));
	
	// Spell Laser

	isAttacking = false;

}

void Atestwitch::SpellSummonGhoul()
{
	UE_LOG(LogTemp, Log, TEXT("SpellSummonGhoul"));
	
	// Spell Summon_Ghoul

	isAttacking = false;

}

void Atestwitch::SpellSummonJormungand()
{
	UE_LOG(LogTemp, Log, TEXT("SpellSummonJormungand"));
	
	// Spell Summon_Jormungand

	isAttacking = false;

}

void Atestwitch::SpellHexagram()
{
	UE_LOG(LogTemp, Log, TEXT("SpellHexagram"));
	
	// Spell Hexagram

	isAttacking = false;

}

bool Atestwitch::CheckArriveAtTarget()
{
	float fDistance = FVector::Distance(this->GetActorLocation(), m_targetLocation);
	
	if (fDistance <= 10.0f)
	{
		return true;
	}
	return false;
}

void Atestwitch::SetNewTargetLocation()
{
	UE_LOG(LogTemp, Log, TEXT("Update"));

	FVector origin = this->GetActorLocation();
	FNavLocation loc;
	UNavigationSystemV1* navSys = UNavigationSystemV1::GetCurrent(World);

	// if (navSys->GetRandomPointInNavigableRadius(origin, 1500.0f, loc, nullptr))
	if (navSys->GetRandomReachablePointInRadius(origin, FMath::RandRange(1000.0f, 1500.0f), loc, nullptr))
	{
		m_targetLocation = FVector(loc.Location.X, origin.Y, loc.Location.Z);

		// UE_LOG(LogTemp, Log, TEXT("%s"), targetLocation.ToString());
	}
}

// Called every frame
void Atestwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateCharacter();

	TickStateMachine();

	if (!isNextAttackReady)
	{
		attackDelay += DeltaTime;
		if (attackDelay >= 5.0f)
		{
			attackDelay = 0.0f;
			isNextAttackReady = true;
		}
	}

	if (!isNextMoveReady)
	{
		moveDelay += DeltaTime;
		if (moveDelay >= 10.0f)
		{
			moveDelay = 0.0f;
			isNextMoveReady = true;
		}
	}
}

// Called to bind functionality to input
void Atestwitch::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


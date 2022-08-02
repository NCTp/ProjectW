// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitch.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PaperFlipbookComponent.h"
#include "Engine/World.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ANightWitch::ANightWitch()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Set the size of our collision capsule.
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));
	check(CapsuleCollision);
	RootComponent = CapsuleCollision;

	NightWitchFlipbook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Flipbook"));
	NightWitchFlipbook->SetupAttachment(RootComponent);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(RootComponent);

	Movement = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("Movement"));

	isMovingForward = false;
	isMovingBackward = false;
	isAttacking = false;
	isStumbling = false;
	interruptable = false;
	lastStumbleIndex = 0;
}

// Called when the game starts or when spawned
void ANightWitch::BeginPlay()
{
	Super::BeginPlay();
	
	ActiveState = EState::IDLE;

	Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

void ANightWitch::UpdateAnimation()
{
}

void ANightWitch::UpdateCharacter()
{
}

void ANightWitch::TickStateMachine()
{
	switch(ActiveState)
	{
	case EState::IDLE:
		StateIdle();
		break;

	case EState::CHASE:
		StateChase();
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
	if(ActiveState != EState::DEAD)
	{
		ActiveState = newState;
	}
}

void ANightWitch::StateIdle()
{
	if(Target && FVector::Distance(Target->GetActorLocation(), GetActorLocation()) <= 500.0f)
	{
		SetState(EState::CHASE);
	}
}

void ANightWitch::StateChase()
{
	float distance = FVector::Distance(GetActorLocation(), Target->GetActorLocation());

	if(distance <= 100.0f)
	{
		FVector targetDirection = Target->GetActorLocation() - GetActorLocation();

		float dot = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());

		if(dot > 0.95f)
		{
			Attack();
		}
	}
	else
	{
		AAIController* AIController = Cast<AAIController>(Controller);

		if(!AIController->IsFollowingAPath())
		{
			AIController->MoveToActor(Target);
		}

	}
}

void ANightWitch::StateTeleport()
{
}

void ANightWitch::StateAttack()
{
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

void ANightWitch::Attack()
{
}

// Called every frame
void ANightWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TickStateMachine();
}

// Called to bind functionality to input
void ANightWitch::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


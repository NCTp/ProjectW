// Fill out your copyright notice in the Description page of Project Settings.

#include <random>
#include <iostream>

#include "Enemy.h"
#include "PaperFlipbookComponent.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "AttackEffect.h"
#include "Projectiles.h"

AEnemy::AEnemy()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(150.0f);
	GetCapsuleComponent()->SetCapsuleRadius(50.0f);

	GetCharacterMovement()->GravityScale = 6.5f;
	GetCharacterMovement()->AirControl = 1.0f;
	GetCharacterMovement()->JumpZVelocity = 2500.f;
	//GetCharacterMovement()->GroundFriction = 1.0f;
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	GetCharacterMovement()->MaxFlySpeed = 1000.0f;
}
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	activeState = State::IDLE;
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AEnemy::OnOverlapBegin);
	//target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	isAttack = false;
	isGimmick = false;
	canRangeAttack = false;
	canAreaAttack = false;
	canShootProjectile = true;
	speed = 500.0f;
}

void AEnemy::Tick(float deltaTime)
{
	Super::Tick(deltaTime);

	TickStateMachine(deltaTime);
	UpdateAnimation();
	if (health <= 0)
		this->Destroy();
}

void AEnemy::TickStateMachine(float deltaTime)
{
	switch (activeState)
	{
	case State::IDLE:
		StateIdle();
		break;
	case State::CLOSE:
		StateClose();
		break;
	case State::FAR:
		StateFar();
		break;
	case State::MELEE_ATTACK_01:
		StateMeleeAttack01();
		break;
	case State::MELEE_ATTACK_02:
		StateMeleeAttack02(deltaTime);
		break;
	case State::RANGE_ATTACK_01:
		StateRangeAttack01();
		break;
	case State::RANGE_ATTACK_02:
		StateRangeAttack02();
		break;
	case State::AREA_ATTACK_01:
		StateAreaAttack01();
		break;
	case State::AREA_ATTACK_02:
		StateAreaAttack02();
		break;
	case State::GIMMICK:
		StateGimmick();
		break;
	case State::DEAD:
		StateDead();
		break;
	}

}
void AEnemy::SetState(State newState)
{
	if (activeState != State::DEAD)
		activeState = newState;
}
//Idle
void AEnemy::StateIdle()
{
	UE_LOG(LogTemp, Warning, TEXT("IDLE"));
	if (target && FVector::Distance(target->GetActorLocation(), GetActorLocation()) <= 1500.0f)
	{
		SetState(State::CLOSE);
	}
	else if (target && FVector::Distance(target->GetActorLocation(), GetActorLocation()) > 1500.0f)
	{
		SetState(State::FAR);
	}

}
//Close to player
void AEnemy::StateClose()
{
	UE_LOG(LogTemp, Warning, TEXT("CLOSE"));
	GetCharacterMovement()->MaxWalkSpeed = 500.0f;
	float distance = FVector::Distance(GetActorLocation(), target->GetActorLocation());
	FVector targetDirection = target->GetActorLocation() - GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());
	//AAIController* AIController = Cast<AAIController>(Controller);
	//AIController->MoveToActor(target);
	canRangeAttack = true;
	if (target && FVector::Distance(target->GetActorLocation(), GetActorLocation()) <= 700.0f)
	{
		int random = FMath::RandRange(0, 1);
		if (random == 0 && !isAttack)
		{
			isAttack = true;
			SetState(State::MELEE_ATTACK_01);
		}
		else if (random == 1 && !isAttack)
		{
			isAttack = true;
			SetState(State::MELEE_ATTACK_02);
		}
	}
	else 
	{
		AAIController* AIController = Cast<AAIController>(Controller);
		AIController->MoveToActor(target);
	}
	
}
//Far from player
void AEnemy::StateFar()
{
	UE_LOG(LogTemp, Warning, TEXT("FAR"));
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	float distance = FVector::Distance(GetActorLocation(), target->GetActorLocation());
	FVector targetDirection = target->GetActorLocation() - GetActorLocation();
	float dotProduct = FVector::DotProduct(GetActorForwardVector(), targetDirection.GetSafeNormal());

	//AAIController* AIController = Cast<AAIController>(Controller);
	//AIController->MoveToActor(target);

	if (target && FVector::Distance(target->GetActorLocation(), GetActorLocation()) <= 1500.0f)
	{
		SetState(State::CLOSE);
	}
	else
	{
		int random = FMath::RandRange(0, 1); 
		if (random == 0 && canRangeAttack) 
		{
			SetState(State::RANGE_ATTACK_01);
			//canRangeAttack = false;
		}
		else if (random == 1 && canRangeAttack)
		{
			SetState(State::RANGE_ATTACK_02);
			//canRangeAttack = false;
		}
		else
		{
			AAIController* AIController = Cast<AAIController>(Controller);
			AIController->MoveToActor(target);
		}
		
	}
}
//360 degree
void AEnemy::StateMeleeAttack01()
{
	
	UE_LOG(LogTemp, Warning, TEXT("MA01"));
	//SetState(State::IDLE);
	MeleeAttack01();
	
	
}
//backstep + teleport
void AEnemy::StateMeleeAttack02(float deltaTime)
{
	UE_LOG(LogTemp, Warning, TEXT("MA02"));
	MeleeAttack02(deltaTime);
}
//Blood Slash
void AEnemy::StateRangeAttack01()
{
	UE_LOG(LogTemp, Warning, TEXT("RA01"));
	//SetState(State::IDLE);
	RangeAttack01();

}
//Take down
void AEnemy::StateRangeAttack02()
{
	UE_LOG(LogTemp, Warning, TEXT("RA02"));
	//SetState(State::IDLE);
	RangeAttack02();
}
//Teleport -> Blood Columns
void AEnemy::StateAreaAttack01()
{
	UE_LOG(LogTemp, Warning, TEXT("AA01"));
	SetState(State::IDLE);
	AreaAttack01();
}
//Teleport -> Sweeping Floor
void AEnemy::StateAreaAttack02()
{
	UE_LOG(LogTemp, Warning, TEXT("AA02"));
	AreaAttack02();
}
//After teleport, outside of screen at this state, connected to SAA01 and SAA02
void AEnemy::StateTeleport()
{
	UE_LOG(LogTemp, Warning, TEXT("TP"));
	Teleport();
}
//Main Gimmick
void AEnemy::StateGimmick()
{
	UE_LOG(LogTemp, Warning, TEXT("GI"));
	Gimmick();
}
//helath <= 0
void AEnemy::StateDead()
{
	UE_LOG(LogTemp, Warning, TEXT("Dead"));
}
//health--
void AEnemy::TakeDamage()
{
	health--;
}

void AEnemy::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();
	int animValue = 0; //Idle
	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation = IdleAnimation;

	if (PlayerSpeedSqr > 0.0f)
		animValue = 1;
	else
		animValue = 0; // Idle

	if (isAttack == true)
		animValue = 2;
	if (isGimmick == true)
		animValue = 10;

	switch (animValue)
	{
	case 0:
		DesiredAnimation = IdleAnimation;
		break;
	case 1:
		DesiredAnimation = RunningAnimation;
		break;
	case 2:
		DesiredAnimation = AttackAnimation;
		//isAttack = false;


		break;
	default:
		DesiredAnimation = IdleAnimation;
	}


	if (GetSprite()->GetFlipbook() != DesiredAnimation)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void AEnemy::MeleeAttack01()
{
	canRangeAttack = true;
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 2.0f, false);
}

void AEnemy::MeleeAttack02(float deltaTime)
{
	currentLocation = this->GetActorLocation();
	currentTargetLocation = target->GetActorLocation();
	canRangeAttack = true;
	if (currentTargetLocation.X - currentLocation.X <= 0)
	{
		currentLocation.X += speed * deltaTime;
		SetActorLocation(currentLocation);
	}
	else
	{
		currentLocation.X -= speed * deltaTime;
		SetActorLocation(currentLocation);
	}
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 2.0f, false);
	
}

void AEnemy::RangeAttack01()
{
	spawnLocation = GetCapsuleComponent()->GetComponentTransform().GetTranslation();

	currentLocation = this->GetActorLocation();
	currentTargetLocation = target->GetActorLocation();

	if (canShootProjectile)
	{
		if (currentLocation.X - currentTargetLocation.X <= 0.0f)
		{
			spawnRotation = FRotator(0.0f, 0.0f, 180.0f);
			AProjectiles* p = nullptr;
			p = GetWorld()->SpawnActor<AProjectiles>(projectile, spawnLocation, spawnRotation, spawnInfo);
			canShootProjectile = false;
		}
		else if (currentLocation.X - currentTargetLocation.X > 0.0f)
		{
			spawnRotation = FRotator(0.0f, 0.0f, 0.0f);
			AProjectiles* p = nullptr;
			p = GetWorld()->SpawnActor<AProjectiles>(projectile, spawnLocation, spawnRotation, spawnInfo);
			canShootProjectile = false;
		}
	}

	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 3.0f, false);
	
	canRangeAttack = false;
}

void AEnemy::RangeAttack02()
{
	spawnLocation = GetCapsuleComponent()->GetComponentTransform().GetTranslation();

	currentLocation = this->GetActorLocation();
	currentTargetLocation = target->GetActorLocation();

	if (canShootProjectile)
	{
		if (currentLocation.X - currentTargetLocation.X <= 0.0f)
		{
			spawnRotation = FRotator(0.0f, 0.0f, 180.0f);
			AProjectiles* p = nullptr;
			p = GetWorld()->SpawnActor<AProjectiles>(projectile, spawnLocation, spawnRotation, spawnInfo);
			canShootProjectile = false;
		}
		else if (currentLocation.X - currentTargetLocation.X > 0.0f)
		{
			spawnRotation = FRotator(0.0f, 0.0f, 0.0f);
			AProjectiles* p = nullptr;
			p = GetWorld()->SpawnActor<AProjectiles>(projectile, spawnLocation, spawnRotation, spawnInfo);
			canShootProjectile = false;
		}
	}

	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 3.0f, false);
	canRangeAttack = false;
}

void AEnemy::AreaAttack01()
{
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 5.0f, false);
}

void AEnemy::AreaAttack02()
{
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 5.0f, false);
}

void AEnemy::Teleport()
{
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 2.0f, false);
}

void AEnemy::Gimmick()
{
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AEnemy::AttackEnd, 20.0f, false);
}

void AEnemy::AttackEnd()
{
	isAttack = false;
	canShootProjectile = true;
	SetState(State::IDLE);
}

void AEnemy::GimmickEnd()
{
	isGimmick = false;
	SetState(State::IDLE);
}

void AEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AAttackEffect* attackEffect = Cast<AAttackEffect>(OverlappedComp);

	if(attackEffect)
		UE_LOG(LogTemp, Warning, TEXT("Enemy Overlapped"));
}

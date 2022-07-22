// Fill out your copyright notice in the Description page of Project Settings.


#include "StarWitch.h"
#include "PaperFlipbookComponent.h"


// Sets default values
AStarWitch::AStarWitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PlayingAnim = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FlipBook"));

}

// Called when the game starts or when spawned
void AStarWitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStarWitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	UPaperFlipbook* anim = IdleAnim;

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
	PlayingAnim->SetFlipbook(anim);

}


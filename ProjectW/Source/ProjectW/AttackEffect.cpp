// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackEffect.h"
#include "Components/CapsuleComponent.h"
// Sets default values
AAttackEffect::AAttackEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

}

// Called when the game starts or when spawned
void AAttackEffect::BeginPlay()
{
	FTimerHandle timer;
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timer, this, &AAttackEffect::DestroyMyself, 0.5f, false);
	
	
}

// Called every frame
void AAttackEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AAttackEffect::DestroyMyself()
{
	this->Destroy();
}

void AAttackEffect::DoDamage(int damage)
{

}


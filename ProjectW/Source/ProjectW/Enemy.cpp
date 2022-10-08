// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)
// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_health = 3;
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);
	if (m_health <= 0)
	{
		PrintString("Dead");
		Destroy();
	}

}

void AEnemy::GetDamage(int Damage)
{
	m_health -= Damage;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%i"), m_health));
	//PrintString("GetDma");
}


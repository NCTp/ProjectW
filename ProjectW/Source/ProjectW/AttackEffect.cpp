// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackEffect.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Enemy.h"
#include "ProjectWCharacter.h"
// Sets default values
AAttackEffect::AAttackEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	attackCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("AttackCollision"));
	
}

// Called when the game starts or when spawned
void AAttackEffect::BeginPlay()
{
	FTimerHandle timer;
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(timer, this, &AAttackEffect::DestroyMyself, 0.5f, false);
	attackCollision->OnComponentBeginOverlap.AddDynamic(this, &AAttackEffect::OnOverlapBegin);
	
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

void AAttackEffect::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped"));
	AEnemy* enemy = Cast<AEnemy>(OtherActor);
	AProjectWCharacter* chara = Cast<AProjectWCharacter>(OtherActor);
	if (enemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("enemy->health"));
		enemy->health -= 1;
	}


}

void AAttackEffect::DoDamage(int damage)
{

}


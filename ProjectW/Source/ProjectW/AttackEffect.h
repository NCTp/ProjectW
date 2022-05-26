// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AttackEffect.generated.h"

class UBoxComponent;

UCLASS()
class PROJECTW_API AAttackEffect : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttackEffect();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SpawnEffects)
		UBoxComponent* attackCollision;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DoDamage(int damage);

	void DestroyMyself();

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperCharacter.h"
#include "Enemy.generated.h"

UCLASS()
class PROJECTW_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	UFUNCTION(BlueprintCallable)
	void GetDamage(int Damage);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere)
	int m_health;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

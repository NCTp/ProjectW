// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NightWitchGhoul.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGhoulState : uint8
{
	DEFAULT		UMETA(DisplayName = "Default"),
	IDLE		UMETA(DisplayName = "Idle"),
	CHASE		UMETA(DisplayName = "Chase"),
	ATTACK		UMETA(DisplayName = "Attack"),
	DEAD		UMETA(DisplayName = "Dead")
};

UCLASS()
class PROJECTW_API ANightWitchGhoul : public APaperCharacter
{
	GENERATED_BODY()

	ANightWitchGhoul();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Flip();

	void UpdateCharacter();

	void TickStateMachine();

	void SetState(EGhoulState newState);

	void StateIdle();

	void StateChase();

	void StateAttack();

	void StateDead();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "State")
	EGhoulState ActiveState;

	class AProjectWCharacter* Player;

	class UWorld* World;

	bool isLookingRight;
	bool isAttacking;
	bool isNextAttackReady;

	float attackTimer;
	float attackDelay;
};

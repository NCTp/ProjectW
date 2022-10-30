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

	void UpdateAnimation();

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

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	// The animation to play while chase(move)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ChaseAnimation;

	// The animation to play while attack
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackAnimation;

	// The animation to play while die
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* DeadAnimation;

	class ATDChar* Player;

	class UWorld* World;

	bool isLookingRight;
	bool isAttacking;
	bool isNextAttackReady;

	float attackTimer;
	float attackDelay;
};

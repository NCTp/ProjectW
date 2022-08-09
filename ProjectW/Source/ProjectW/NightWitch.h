// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "NightWitchTeleportPoint.h"
#include "NightWitchChainPortal.h"

#include "NightWitch.generated.h"

UENUM(BlueprintType)
enum class EState : uint8
{
	DEFAULT		UMETA(DisplayName = "Default"),
	IDLE		UMETA(DisplayName = "Idle"),
	RUNAWAY		UMETA(DisplayName = "Runaway"),
	TELEPORT	UMETA(DisplayName = "Teleport"),
	ATTACK		UMETA(DisplayName = "Attack"),
	STUMBLE		UMETA(DisplayName = "Stumble"),
	TAUNT		UMETA(DisplayName = "Tarunt"),
	DEAD		UMETA(DisplayName = "Dead")
};

UENUM(BlueprintType)
enum class ESpell : uint8
{
	DEFAULT				UMETA(DisplayName = "Default"),
	CHAIN				UMETA(DisplayName = "Chain"),
	LASER				UMETA(DisplayName = "Laser"),
	SUMMON_GHOUL		UMETA(DisplayName = "Summon"),
	SUMMON_JORMUNGAND	UMETA(DisplayName = "Summon"),
	HEXAGRAM			UMETA(DisplayName = "Hexagram")
};

UCLASS()
class PROJECTW_API ANightWitch : public APaperCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANightWitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, Category = "State")
	EState ActiveState;

	UPROPERTY(VisibleAnywhere, Category = "Spell")
	ESpell Spell;

	void Flip();

	void UpdateAnimation();

	void UpdateCharacter();

	void TickStateMachine();

	void SetState(EState newState);

	void StateIdle();

	void StateRunaway();

	void StateTeleport();

	void StateAttack();

	void StateStumble();

	void StateTaunt();

	void StateDead();

	void SelectSpell();

	void RandomSelect();

	void SetSpell(ESpell newSpell);

	void SpellChain();

	void SpellLaser();

	void SpawnLaser();

	void SpellSummonGhoul();

	void SpellSummonJormungand();

	void SpellHexagram();

	bool CheckArriveAtTarget();

	void SetNewTargetLocation();

	void MoveTimer(float DeltaTime);

	ANightWitchTeleportPoint* GetTeleportPoints();

	AActor* Target;

	UPROPERTY()
	class AAIController* AIController;

	class UWorld* World;

	class AProjectWCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal")
	TSubclassOf<ANightWitchChainPortal> Portal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal")
	TSubclassOf<AActor> LaserPortal;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	int health;
	int hitCount;
	int phase;

	int currentTeleportPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	ANightWitchTeleportPoint* TeleportPoint;

	int lastStumbleIndex;

	bool interruptable;

	bool isAttacking;
	bool isDamaging;
	bool isMoving;
	bool isNextAttackReady;
	bool isNextMoveReady;
	bool isTeleporting;
	bool isStumbling;
	bool isTatunting;
	bool isLookingRight;

	bool isMoveEnd;

	float attackDelay;
	float moveDelay;

	FTimerHandle spellLaserTimeHandle;
	int spawnLaserCounter;

	UPROPERTY(VisibleAnywhere, Category = "Target Location")
	FVector m_targetLocation;
};

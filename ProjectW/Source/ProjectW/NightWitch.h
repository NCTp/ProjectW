// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NightWitch.generated.h"

UENUM(BlueprintType)
enum class EState : uint8
{
	DEFAULT,		// Default
	IDLE,			// Idle
	CHASE,			// Chase(Close)
	TELEPORT,		// Teleport(Far)
	ATTACK,			// Attack
	STUMBLE,		// Stumble
	TAUNT,			// Taunt
	DEAD			// Dead
};

UCLASS()
class PROJECTW_API ANightWitch : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANightWitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Flipbook")
	class UPaperFlipbookComponent* NightWitchFlipbook;

	UPROPERTY(EditAnywhere, Category = "Capsule Collision")
	class UCapsuleComponent* CapsuleCollision;

	UPROPERTY(EditAnywhere, Category = "Direction Arrow")
	class UArrowComponent* Arrow;

	UPROPERTY(EditAnywhere, Category = "Movement")
	class UCharacterMovementComponent* Movement;

	UPROPERTY(VisibleAnywhere, Category = "State")
	EState ActiveState;

	void UpdateAnimation();

	void UpdateCharacter();

	void TickStateMachine();

	void SetState(EState newState);

	void StateIdle();

	void StateChase();

	void StateTeleport();

	void StateAttack();

	void StateStumble();

	void StateTaunt();

	void StateDead();

	void Attack();
	
	AActor* Target;

	int lastStumbleIndex;

	bool interruptable;

	bool isAttacking;
	bool isDamaging;
	bool isMovingForward;
	bool isMovingBackward;
	bool isNextAttackReady;
	bool isTeleporting;
	bool isStumbling;
	bool isTatunting;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

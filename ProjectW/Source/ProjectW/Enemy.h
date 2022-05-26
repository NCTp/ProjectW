// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
class UBoxComponent;
class AProjectiles;
UENUM(BlueprintType)
enum class State : uint8
{
	IDLE,
	CLOSE,
	FAR,
	MELEE_ATTACK_01,
	MELEE_ATTACK_02,
	RANGE_ATTACK_01,
	RANGE_ATTACK_02,
    AREA_ATTACK_01,
	AREA_ATTACK_02,
	TELEPORT,
	GIMMICK,
	DEAD
};

UCLASS()
class PROJECTW_API AEnemy : public APaperCharacter
{
	GENERATED_BODY()
	
public:
	AEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Finite State Machine")
		State activeState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
		float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
		class APawn* target;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* AttackAnimation;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectiles> projectile;

	virtual void BeginPlay() override;
	virtual void Tick(float deltaTime) override;

	void SetState(State newState);
	virtual void TickStateMachine(float deltaTime);
	virtual void StateIdle();
	virtual void StateClose();
	virtual void StateFar();
	virtual void StateMeleeAttack01();
	virtual void StateMeleeAttack02(float deltaTime);
	virtual void StateRangeAttack01();
	virtual void StateRangeAttack02();
	virtual void StateAreaAttack01();
	virtual void StateAreaAttack02();
	virtual void StateTeleport();
	virtual void StateGimmick();
	virtual void StateDead();
	virtual void TakeDamage();

	void UpdateAnimation();

	void MeleeAttack01();
	void MeleeAttack02(float deltaTime);
	void RangeAttack01();
	void RangeAttack02();
	void AreaAttack01();
	void AreaAttack02();
	void Teleport();
	void Gimmick();
	void AttackEnd();
	void GimmickEnd();


	bool isAttack;
	bool canRangeAttack;
	bool canAreaAttack;
	bool isGimmick;
	bool canShootProjectile;

public:
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, 
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



	FVector spawnLocation = FVector();
	FRotator spawnRotation = FRotator();
	FActorSpawnParameters spawnInfo = FActorSpawnParameters();

	FVector currentLocation;
	FVector currentTargetLocation;
	float speed;

};

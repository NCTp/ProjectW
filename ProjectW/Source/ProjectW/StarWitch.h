// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PaperCharacter.h"
#include "StarWitch.generated.h"

class AStarWitchBall;
class AStarWitchLaser;
class AStarWitchTeleportEffects;


UENUM()
enum class EActorState : uint8
{
	StarWitchState_Idle         UMETA(DisplayName = "Idle"),
	StarWitchState_Walking      UMETA(DisplayName = "Walking"),
	StarWitchState_Magic_01     UMETA(DisplayName = "Magic01"),
	StarWitchState_Magic_02     UMETA(DisplayName = "Magic02"),
	StarWitchState_Teleport     UMETA(DIsplayName = "Teleport"),
	StarWitchState_CounterReady UMETA(DisplayNmae = "CounterReady"),
	StarWitchState_Dead         UMETA(DisplayNmae = "Dead")
};

UCLASS()
class PROJECTW_API AStarWitch : public APawn
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* FlipbookComponent;
	
public:	
	// Sets default values for this actor's properties
	AStarWitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 TeleportCounter = 3;
	int32 MagicCounter01 = 4;
	int32 MagicCounter02 = 3;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = State)
	EActorState StarWitchState;

	////////// Animations ///////////
	// Idle Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* IdleAnim;
	// Walking Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* WalkingAnim;
	// Casting Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CastingAnim;
	// Casting when casting Shotgun Laser (Attack02)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CastingLaserAnim;
	// Counter Ready Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CounterReadyAnim;
	// Animation played when counter success
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CounterAnim;
	// Teleport Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* TeleportAnim;


	////////// States and Boolean Values ///////////
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isFarFromPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isCloseToPlayer;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isPhaseOne;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isPhaseTwo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isPhaseThree;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isDead;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_startFighting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isTeleporting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isCastingMagic01;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = State)
	bool m_isCastingMagic02;

	////////// Objects ///////////
	APawn* Player; // Player

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Projectile)
	TSubclassOf<AStarWitchLaser> Projectile_Laser;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Projectile)
	TSubclassOf<AStarWitchBall> Projectile_Ball;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effects)
	TSubclassOf<AStarWitchTeleportEffects> Effects_Teleport;

	// Timer Practice
	FTimerHandle TeleportTimerHandle;
	FTimerHandle MagicTimerHandle_1;
	FTimerHandle MagicTimerHandle_2;

	////////// Private Functions ///////////
	// Get Damage
	void GetDamage();
	
private:

	////////// Public Functions ///////////

	// Flip sprite following to moving direction
	void Flip();
	// Update Animations
	void UpdateAnimation();
	// Set States
	void SetState(EActorState newState);

	////////// Action Functions ///////////
	void Teleport();
	void ShootLazer();
	void ShootBall(float angle);
	void Magic01();
	void Magic02();

	////////// Functions called each states ///////////
	void StateIdle();
	void StateWalk(float DeltaTime);
	void StateTeleport();
	void StateMagic01();
	void StateMagic02();
	void StateMachine(float DeltaTime);

	////////// Private Variables ///////////
	int health;

	FActorSpawnParameters spawnInfo = FActorSpawnParameters();

	FORCEINLINE class UPaperFlipbookComponent* GetFlipbookComponent() const { return FlipbookComponent; }
};
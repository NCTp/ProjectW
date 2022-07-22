// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PaperCharacter.h"
#include "StarWitch.generated.h"

UENUM()
enum class EActorState : uint8
{
	StarWitchState_Idle         UMETA(DisplayName = "Idle"),
	StarWitchState_Walking      UMETA(DisplayName = "Walking"),
	StarWitchState_Attack_01    UMETA(DisplayName = "Attack_01"),
	StarWitchState_Attack_02    UMETA(DisplayName = "Attack_02"),
	StarWitchState_Attack_03    UMETA(DIsplayName = "Attack_03"),
	StarWitchState_CounterReady UMETA(DisplayNmae = "CounterReady"),
	StarWitchState_Dead         UMETA(DisplayNmae = "Dead")
};

UCLASS()
class PROJECTW_API AStarWitch : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Animation, meta = (AllowPrivateAccess = "true"))
	class UPaperFlipbookComponent* FlipbookComponent;
	
public:	
	// Sets default values for this actor's properties
	AStarWitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

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
	class UPaperFlipbook* CastingAnim_02;
	// Counter Ready Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CounterReadyAnim;
	// Animation played when counter success
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* CounterAnim;
	// Teleport Animation
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Animations)
	class UPaperFlipbook* TeleportAnim;

	////////// States ///////////
	
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

	APawn* Player;
private:
	// Get Damage
	void GetDamage();
	// Flip sprite following to moving direction
	void Flip();
	// Update Animations
	void UpdateAnimation();
	// Set States
	void SetState(EActorState newState);
	void StateIdle();
	void StateWalk();
	void StateMachine();
	int health;

	FORCEINLINE class UPaperFlipbookComponent* GetFlipbookComponent() const { return FlipbookComponent; }
};

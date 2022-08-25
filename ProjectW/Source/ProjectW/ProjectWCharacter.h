// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "ProjectWCharacter.generated.h"

class UTextRenderComponent;

UENUM()
enum class ECharacterState : uint8
{
	Default	UMETA(DisplayName = "Default"),
	Idle	UMETA(DisplayName = "Idle"),
	Run		UMETA(DisplayName = "Run"),
	Jump	UMETA(DisplayName = "Jump"),
	Fall	UMETA(DisplayName = "Fall"),
	Roll	UMETA(DisplayName = "Roll"),
	Attack	UMETA(DisplayName = "Attack")
};

/**
 * This class is the default character for ProjectW, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config=Game)
class AProjectWCharacter : public APaperCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UTextRenderComponent* TextComponent;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while jumping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* JumpingAnimation;

	// The animation to play while Falling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* FallingAnimation;

	// The animation to play while Rolling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RollingAnimation;

	// Attack Combo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackCombo01;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackCombo02;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackCombo03;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* AttackCombo04;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterState CharacterState = ECharacterState::Default;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	/** Called for side to side input */
	void MoveRight(float Value);

	void MoveUp(float Value);

	void Attack();

	void Roll();

	virtual void Jump() override;

	void ChangeWeapon();

	void UpdateCharacter();

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	AProjectWCharacter();

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> Projectile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzlePoint, meta = (AllowPrivateAccess = "true"))
		class UArrowComponent* MuzzlePoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MuzzlePoint)
		class USceneComponent* MuzzleLocation;

	class UWorld* World;

	FTransform SpawnTransform;

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	int m_uCombo;

	int health;
	
	float m_fComboTimer;

	bool m_bIsAttacking;

	bool m_bIsRolling;

	bool m_bCanComboAttack;

	bool m_bPlayAttackMotion;

	float m_fRollingTimer;

	// Current Weapon Type
	// 0 : Rifle, 1 : Shotgun
	int m_uCurrentWeapon;

};

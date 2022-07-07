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
	Fire	UMETA(DisplayName = "Fire")
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UTextRenderComponent* TextComponent;
	virtual void Tick(float DeltaSeconds) override;
protected:
	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleIdleAnimation;

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleRunningAnimation;

	// The animation to play while jumping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleJumpingAnimation;

	// The animation to play while Falling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleFallingAnimation;

	// The animation to play while Rolling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleRollingAnimation;

	// The animation to play while Firing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* RifleFiringAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunIdleAnimation;

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunRunningAnimation;

	// The animation to play while jumping
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunJumpingAnimation;

	// The animation to play while Falling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunFallingAnimation;

	// The animation to play while Rolling
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunRollingAnimation;

	// The animation to play while Firing
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* ShotgunFiringAnimation;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECharacterState CharacterState = ECharacterState::Default;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "IsFiring")
	bool m_bIsFiring;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "IsRolling")
	bool m_bIsRolling;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "IsRolling")
	float m_fRollingCount;

	// Current Weapon Type
	// 0 : Rifle, 1 : Shotgun
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category = "CurrentWeapon")
	int m_uCurrentWeapon;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	/** Called for side to side input */
	void MoveRight(float Value);

	void MoveUp(float Value);

	void Fire();

	void StopFiring();

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

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "PlayerMeleeProjectile.h"
#include "TDChar.generated.h"


UENUM()
enum class ETDCharStates : uint8
{
	TDCharState_Default UMETA(DisplayName = "TDCharState_Default"),
	TDCharState_Idle    UMETA(DisplayName = "TDCharState_Idle"),
	TDCharState_Run     UMETA(DisplayName = "TDCharState_Run"),
	TDCharState_Dash    UMETA(DisplayName = "TDCharState_Dash"),
	TDCharState_MeleeAttack UMETA(DisplayName = "TDCharState_MeleeAttack"),
	TDCharState_RangeAttack UMETA(DisplayName = "TDCharState_RangeAttack"),
	TDCharState_Dead    UMETA(DisplayName = "TDCharState_Dead")
};

UCLASS()
class PROJECTW_API ATDChar : public APaperCharacter
{

	GENERATED_BODY()

	ATDChar();
	
	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class APlayerController* PlayerController;

	/////////////////////Animations////////////////////

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Front_TDIdleAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Front_TDRunAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Side_TDIdleAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Side_TDRunAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Back_TDIdleAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Back_TDRunAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* TDDashStartAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* TDDashEndAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Front_TDMeleeAttackAnim_1;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Front_TDMeleeAttackAnim_2;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Back_TDMeleeAttackAnim_1;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Back_TDMeleeAttackAnim_2;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Side_TDMeleeAttackAnim_1;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Side_TDMeleeAttackAnim_2;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Front_TDRangeAttackAnim;

	UPROPERTY(EditAnywhere)
	class UPaperFlipbook* Back_TDRangeAttackAnim;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlayerMeleeProjectile> MeleeProjectile;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> DashEffect;

	FActorSpawnParameters TDCharSpawnInfo = FActorSpawnParameters();

	UPROPERTY(EditAnywhere)
	float m_HP;

	UPROPERTY(EditAnywhere)
	float m_MP;
	

	UPROPERTY(EditAnywhere)
	float m_Walkspeed;
	

	UFUNCTION(BlueprintCallable)
	void GetDamage();

	UFUNCTION(BlueprintCallable)
	float GetHP();

	UFUNCTION(BlueprintCallable)
	float GetMP();

	UFUNCTION(BlueprintCallable)
	void SetHP(float HP);

	UFUNCTION(BlueprintCallable)
	void SetMP(float MP);

protected:
	// Overrided basic functions
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void MoveRight(float Value);

	void MoveUp(float Value);

	void Dash();

	void MeleeAttack();

	void RangeAttack();

	
private:

	UPROPERTY(VisibleAnywhere)
	ETDCharStates TDCharState;
	// Update Flipbook Animations
	void UpdateAnimation();
	// Set ETDCharStates
	void SetState(ETDCharStates NewState);
	// Flip Sprites
	void Flip();

	// Saving Movement Value (Direction -> Left or Right)
	float RightValue;
	float UpValue;
	
	float m_MouseXValue;
	float m_MouseYValue;

	// boolean values for checking status
	bool m_bisCanMove;
	bool m_bisDefault;
	bool m_bisFront;
	bool m_bisSide;
	bool m_bisBack;
	bool m_bisRight;
	bool m_bisDashStart;
	bool m_bisDashEnd;
	bool m_bisAttacking;
	bool m_bisFirstAttack;
	bool m_bisLastAttack;
	bool m_bisAttackFront;
	bool m_bisAttackBack;
	bool m_bisAttackSide;

	

};

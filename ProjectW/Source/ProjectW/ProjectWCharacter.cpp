// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectWCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(SideScrollerCharacter, Log, All);

//////////////////////////////////////////////////////////////////////////
// AProjectWCharacter

AProjectWCharacter::AProjectWCharacter()
{
	// Use only Yaw from the controller and ignore the rest of the rotation.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Set the size of our collision capsule.
	GetCapsuleComponent()->SetCapsuleHalfHeight(96.0f);
	GetCapsuleComponent()->SetCapsuleRadius(40.0f);

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 500.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	

	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 2048.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 2.0f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.0f;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	GetCharacterMovement()->MaxFlySpeed = 600.0f;

	// Lock character motion onto the XZ plane, so the character can't move in or out of the screen
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->SetPlaneConstraintNormal(FVector(0.0f, -1.0f, 0.0f));

	// Behave like a traditional 2D platformer character, with a flat bottom instead of a curved capsule bottom
	// Note: This can cause a little floating when going up inclines; you can choose the tradeoff between better
	// behavior on the edge of a ledge versus inclines by setting this to true or false
	GetCharacterMovement()->bUseFlatBaseForFloorChecks = true;

    // 	TextComponent = CreateDefaultSubobject<UTextRenderComponent>(TEXT("IncarGear"));
    // 	TextComponent->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));
    // 	TextComponent->SetRelativeLocation(FVector(35.0f, 5.0f, 20.0f));
    // 	TextComponent->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
    // 	TextComponent->SetupAttachment(RootComponent);

	// Enable replication on the Sprite component so animations show up when networked
	GetSprite()->SetIsReplicated(true);
	bReplicates = true;

	m_bIsFiring = false;

	m_uCurrentWeapon = 0;
}

//////////////////////////////////////////////////////////////////////////
// Animation

void AProjectWCharacter::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	if (m_bIsFiring)
	{
		CharacterState = ECharacterState::Fire;
	}
	else
	{
		if (PlayerSpeedSqr <= 0.0f)
		{
			CharacterState = ECharacterState::Idle;
		}
		else
		{
			if (!GetCharacterMovement()->IsFalling())
			{
				if (m_bIsRolling)
				{
					CharacterState = ECharacterState::Roll;
				}
				else
				{
					CharacterState = ECharacterState::Run;
				}
			}
			else
			{
				if (m_bIsRolling)
				{
					CharacterState = ECharacterState::Roll;
				}
				else
				{
					if (PlayerVelocity.Z <= 0.0f)
					{
						CharacterState = ECharacterState::Fall;
					}
					else
					{
						CharacterState = ECharacterState::Jump;
					}
				}
			}
		}
	}

	UPaperFlipbook* DesiredAnimation = nullptr;
	if (m_uCurrentWeapon == 0)
	{
		if (CharacterState == ECharacterState::Idle)
		{
			DesiredAnimation = RifleIdleAnimation;
		}
		else if (CharacterState == ECharacterState::Run)
		{
			DesiredAnimation = RifleRunningAnimation;
		}
		else if (CharacterState == ECharacterState::Jump)
		{
			DesiredAnimation = RifleJumpingAnimation;
		}
		else if (CharacterState == ECharacterState::Fall)
		{
			DesiredAnimation = RifleFallingAnimation;
		}
		else if (CharacterState == ECharacterState::Roll)
		{
			DesiredAnimation = RifleRollingAnimation;
		}
		else if (CharacterState == ECharacterState::Fire)
		{
			DesiredAnimation = RifleFiringAnimation;
		}
	}
	else if (m_uCurrentWeapon == 1)
	{
		if (CharacterState == ECharacterState::Idle)
		{
			DesiredAnimation = ShotgunIdleAnimation;
		}
		else if (CharacterState == ECharacterState::Run)
		{
			DesiredAnimation = ShotgunRunningAnimation;
		}
		else if (CharacterState == ECharacterState::Jump)
		{
			DesiredAnimation = ShotgunJumpingAnimation;
		}
		else if (CharacterState == ECharacterState::Fall)
		{
			DesiredAnimation = ShotgunFallingAnimation;
		}
		else if (CharacterState == ECharacterState::Roll)
		{
			DesiredAnimation = ShotgunRollingAnimation;
		}
		else if (CharacterState == ECharacterState::Fire)
		{
			DesiredAnimation = ShotgunFiringAnimation;
		}
	}

	GetSprite()->SetFlipbook(DesiredAnimation);
}

void AProjectWCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateCharacter();

	if (m_bIsRolling)
	{
		m_fRollingCount += DeltaSeconds;
		if (m_fRollingCount > 0.8f)
		{
			m_bIsRolling = false;
			m_fRollingCount = 0.0f;
		}
	}
}


//////////////////////////////////////////////////////////////////////////
// Input

void AProjectWCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AProjectWCharacter::Fire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &AProjectWCharacter::StopFiring);

	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AProjectWCharacter::Roll);

	PlayerInputComponent->BindAction("ChangeWeapon", IE_Pressed, this, &AProjectWCharacter::ChangeWeapon);

	PlayerInputComponent->BindAxis("MoveRight", this, &AProjectWCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AProjectWCharacter::MoveUp);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjectWCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjectWCharacter::TouchStopped);
}

void AProjectWCharacter::MoveRight(float Value)
{
	/*UpdateChar();*/

	// Apply the input to the character motion
	if (CharacterState != ECharacterState::Roll)
	{
		AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
	}
}

void AProjectWCharacter::MoveUp(float Value)
{
	if (CharacterState != ECharacterState::Roll)
	{
		AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
	}
}

void AProjectWCharacter::Fire()
{
	if (!m_bIsRolling)
	{
		m_bIsFiring = true;
	}
}

void AProjectWCharacter::StopFiring()
{
	m_bIsFiring = false;
}

void AProjectWCharacter::Roll()
{
	if (CharacterState != ECharacterState::Idle && CharacterState != ECharacterState::Jump && CharacterState != ECharacterState::Fall)
	{
		if (!m_bIsRolling)
		{
			m_bIsRolling = true;

			const FVector fvPlayerVelocity = GetVelocity();

			if (!GetCharacterMovement()->IsFalling())
			{
				FVector fvLaunchVelocity = FVector(1.0f, 1.0f, 500.0f);
				
				if (fvPlayerVelocity.X > 0.0f)
				{
					if (fvPlayerVelocity.Y > 0.0f)
					{
						fvLaunchVelocity.X *= 500.0f;
						fvLaunchVelocity.Y *= 500.0f;
					}
					else if (fvPlayerVelocity.Y < 0.0f)
					{
						fvLaunchVelocity.X *= 500.0f;
						fvLaunchVelocity.Y *= -500.0f;
					}
					else
					{
						fvLaunchVelocity.X *= 1000.0f;
					}
				}
				else if (fvPlayerVelocity.X < 0.0f)
				{
					if (fvPlayerVelocity.Y > 0.0f)
					{
						fvLaunchVelocity.X *= -500.0f;
						fvLaunchVelocity.Y *= 500.0f;
					}
					else if (fvPlayerVelocity.Y < 0.0f)
					{
						fvLaunchVelocity.X *= -500.0f;
						fvLaunchVelocity.Y *= -500.0f;
					}
					else
					{
						fvLaunchVelocity.X *= -1000.0f;
					}
				}
				else
				{
					if (fvPlayerVelocity.Y > 0.0f)
					{
						fvLaunchVelocity.Y *= 1000.0f;
					}
					else if (fvPlayerVelocity.Y < 0.0f)
					{
						fvLaunchVelocity.Y *= -1000.0f;
					}
				}

				LaunchCharacter(fvLaunchVelocity, true, true);			
			}
		}
	}
}

void AProjectWCharacter::Jump()
{
	if (!m_bIsRolling)
	{
		ACharacter::Jump();
	}
}

void AProjectWCharacter::ChangeWeapon()
{
	m_uCurrentWeapon += 1;
	if (m_uCurrentWeapon == 2)
	{
		m_uCurrentWeapon = 0;
	}
}

void AProjectWCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Jump on any touch
	Jump();
}

void AProjectWCharacter::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// Cease jumping once touch stopped
	StopJumping();
}

void AProjectWCharacter::UpdateCharacter()
{
	// Update animation to match the motion
	UpdateAnimation();

	// Now setup the rotation of the controller based on the direction we are travelling
	const FVector PlayerVelocity = GetVelocity();	
	float TravelDirection = PlayerVelocity.X;
	// Set the rotation so that the character faces his direction of travel.
	if (Controller != nullptr)
	{
		if (TravelDirection < 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0, 180.0f, 0.0f));
		}
		else if (TravelDirection > 0.0f)
		{
			Controller->SetControlRotation(FRotator(0.0f, 0.0f, 0.0f));
		}
	}
}

// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectWCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"

#include "Projectile.h"

#include "ProjectWGameMode.h"

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
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Perspective;
	SideViewCameraComponent->OrthoWidth = 2048.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	MuzzlePoint = CreateDefaultSubobject<UArrowComponent>(TEXT("MuzzlePoint"));
	MuzzlePoint->SetupAttachment(RootComponent);

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

	m_bPlayAttackMotion = false;
	m_bIsAttacking = false;
	m_bCanComboAttack = false;
	m_uCurrentWeapon = 0;
	m_uCombo = 0;
	m_fComboTimer = 0.0f;
	health = 100.0f;
}

//////////////////////////////////////////////////////////////////////////
// Animation

void AProjectWCharacter::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();

	if (m_bPlayAttackMotion)
	{
		CharacterState = ECharacterState::Attack;
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

	// For First Weapon
	if (m_uCurrentWeapon == 0)
	{
		if (CharacterState == ECharacterState::Idle)
		{
			DesiredAnimation = IdleAnimation;
		}
		else if (CharacterState == ECharacterState::Run)
		{
			DesiredAnimation = RunningAnimation;
		}
		else if (CharacterState == ECharacterState::Jump)
		{
			DesiredAnimation = JumpingAnimation;
		}
		else if (CharacterState == ECharacterState::Fall)
		{
			DesiredAnimation = FallingAnimation;
		}
		else if (CharacterState == ECharacterState::Roll)
		{
			DesiredAnimation = RollingAnimation;
		}
		else if (CharacterState == ECharacterState::Attack)
		{
			if (m_uCombo == 0)
			{
				DesiredAnimation = AttackCombo01;
			}
			else if (m_uCombo == 1)
			{
				DesiredAnimation = AttackCombo02;
			}
			else if (m_uCombo == 2)
			{
				DesiredAnimation = AttackCombo03;
			}
			else if (m_uCombo == 3)
			{
				DesiredAnimation = AttackCombo04;
			}
		}
	}

	// For Second Weapon
	/*
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
		else if (CharacterState == ECharacterState::Attack)
		{
			if (m_uCombo == 0)
			{
				DesiredAnimation = AttackCombo01;
			}
			else if (m_uCombo == 1)
			{
				DesiredAnimation = AttackCombo02;
			}
			else if (m_uCombo == 2)
			{
				DesiredAnimation = AttackCombo03;
			}
			else if (m_uCombo == 3)
			{
				DesiredAnimation = AttackCombo04;
			}
		}
	}
	*/

	GetSprite()->SetFlipbook(DesiredAnimation);
}

void AProjectWCharacter::BeginPlay()
{
	Super::BeginPlay();

	World = GetWorld();
}

void AProjectWCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Update Character Animation, State, etc
	UpdateCharacter();

	// Roll
	// m_fRollingTimer (0.5) : Play Rolling Motion
	if (m_bIsRolling)
	{		
		m_fRollingTimer += DeltaSeconds;
		if (m_fRollingTimer > 0.5f)
		{
			m_bIsRolling = false;
			m_fRollingTimer = 0.0f;
		}
	}

	// Combo Attack
	// m_fComboTimer1 (0.5) : Play Current Attack Motion
	// m_fComboTimer2 (1.5) : Can Combo Attack
	if (m_bIsAttacking)
	{
		m_fComboTimer += DeltaSeconds;

		if (m_fComboTimer > 0.5f)
		{
			m_bPlayAttackMotion = false;
			m_bCanComboAttack = true;
		}
		if (m_fComboTimer > 1.5f)
		{
			m_bIsAttacking = false;
			m_bCanComboAttack = false;
			m_fComboTimer = 0.0f;
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

	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AProjectWCharacter::Attack);

	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &AProjectWCharacter::Roll);

	PlayerInputComponent->BindAction("ChangeWeapon", IE_Pressed, this, &AProjectWCharacter::ChangeWeapon);

	PlayerInputComponent->BindAxis("MoveRight", this, &AProjectWCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AProjectWCharacter::MoveUp);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjectWCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjectWCharacter::TouchStopped);
}

// Character Move
// Can't move while rolling or attacking 

void AProjectWCharacter::MoveRight(float Value)
{
	// Apply the input to the character motion
	if (Value != 0.0f)
	{
		if (CharacterState != ECharacterState::Roll && CharacterState != ECharacterState::Attack)
		{
			AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
		}
	}
}

void AProjectWCharacter::MoveUp(float Value)
{
	if (Value != 0.0f)
	{
		if (CharacterState != ECharacterState::Roll && CharacterState != ECharacterState::Attack)
		{
			AddMovementInput(FVector(0.0f, 1.0f, 0.0f), Value);
		}
	}
}

void AProjectWCharacter::Attack()
{
	if (!m_bPlayAttackMotion)
	{
		if (CharacterState != ECharacterState::Roll && CharacterState != ECharacterState::Jump && CharacterState != ECharacterState::Fall)
		{
			m_bIsAttacking = true;
			m_fComboTimer = 0;
			m_bPlayAttackMotion = true;

			if (m_bCanComboAttack)
			{
				m_uCombo++;
				if (m_uCombo > 3)
				{
					m_uCombo = 0;
				}
			}
			else
			{
				m_uCombo = 0;
			}

			// Move Location
			FVector currentLocation = GetActorLocation();
			FVector forward = GetActorForwardVector();

			if (m_uCombo == 1)
			{
				if (forward.X < 0) 
				{
					currentLocation.X -= 50.0f;
				}
				else
				{
					currentLocation.X += 50.0f;
				}

				SetActorLocation(currentLocation);
			}
			else if (m_uCombo == 2)
			{
				if (forward.X < 0) 
				{
					currentLocation.X += 30.0f;
				}
				else 
				{
					currentLocation.X -= 30.0f;
				}

				SetActorLocation(currentLocation);
			}

			/*
			SpawnTransform = MuzzlePoint->GetComponentTransform();

			FActorSpawnParameters actorSpawnParams;
			actorSpawnParams.SpawnCollisionHandlingOverride =
				ESpawnActorCollisionHandlingMethod::Undefined;

			World->SpawnActor<AProjectile>(Projectile, SpawnTransform, actorSpawnParams);
			*/
		}
	}
}

// Roll
// Only can roll while moving
// Comment part is for y axis rolling

void AProjectWCharacter::Roll()
{
	if (CharacterState != ECharacterState::Idle && CharacterState != ECharacterState::Jump && CharacterState != ECharacterState::Fall)
	{
		if (!m_bIsRolling)
		{
			m_bIsRolling = true;

			m_bPlayAttackMotion = false;
			m_bIsAttacking = false;
			m_bCanComboAttack = false;
			m_uCombo = 0;
			m_fComboTimer = 0.0f;


			const FVector fvPlayerVelocity = GetVelocity();

			if (!GetCharacterMovement()->IsFalling())
			{
				FVector fvLaunchVelocity = FVector(1.0f, 1.0f, 600.0f);
				
				if (Controller)
				{
					if (Controller->IsLocalPlayerController())
					{
						APlayerController* PlayerController = Cast<APlayerController>(Controller);
						if (PlayerController)
						{
							if (PlayerController->IsInputKeyDown(EKeys::D))
							{
								fvLaunchVelocity.X *= 1500.0f;

								/*
								if (PlayerController->IsInputKeyDown(EKeys::W))
								{

									fvLaunchVelocity.X *= 500.0f;
									fvLaunchVelocity.Y *= -250.0f;
								}
								else if (PlayerController->IsInputKeyDown(EKeys::S))
								{

									fvLaunchVelocity.X *= 500.0f;
									fvLaunchVelocity.Y *= 250.0f;
								}
								else
								{
									fvLaunchVelocity.X *= 1000.0f;

								}
								*/
							}
							else if (PlayerController->IsInputKeyDown(EKeys::A))
							{
								fvLaunchVelocity.X *= -1500.0f;

								/*
								if (PlayerController->IsInputKeyDown(EKeys::W))
								{

									fvLaunchVelocity.X *= -500.0f;
									fvLaunchVelocity.Y *= -250.0f;
								}
								else if (PlayerController->IsInputKeyDown(EKeys::S))
								{

									fvLaunchVelocity.X *= -500.0f;
									fvLaunchVelocity.Y *= 250.0f;
								}
								else
								{
									fvLaunchVelocity.X *= -1000.0f;
								}
								*/
							}
							/*
							else if (PlayerController->IsInputKeyDown(EKeys::W))
							{
								fvLaunchVelocity.Y *= -500.0f;
							}
							else if (PlayerController->IsInputKeyDown(EKeys::S))
							{
								fvLaunchVelocity.Y *= 500.0f;
							}
							*/
						}
					}
				}

				LaunchCharacter(fvLaunchVelocity, true, true);			
			}
		}
	}
}

void AProjectWCharacter::Jump()
{
	if (CharacterState != ECharacterState::Roll && CharacterState != ECharacterState::Attack)
	{
		ACharacter::Jump();
	}
}

void AProjectWCharacter::ChangeWeapon()
{
	m_uCurrentWeapon += 1;
	if (m_uCurrentWeapon > 1)
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

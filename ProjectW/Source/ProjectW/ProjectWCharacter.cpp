// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectWCharacter.h"
#include "PaperFlipbookComponent.h"
#include "Components/TextRenderComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraComponent.h"

#include "Projectiles.h"
#include "AttackEffect.h"

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
	CameraBoom->TargetArmLength = 1000.0f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->SetUsingAbsoluteRotation(true);
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	

	// Create an orthographic camera (no perspective) and attach it to the boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->ProjectionMode = ECameraProjectionMode::Orthographic;
	SideViewCameraComponent->OrthoWidth = 6000.0f;
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

	// Prevent all automatic rotation behavior on the camera, character, and camera component
	CameraBoom->SetUsingAbsoluteRotation(true);
	SideViewCameraComponent->bUsePawnControlRotation = false;
	SideViewCameraComponent->bAutoActivate = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	// Configure character movement
	GetCharacterMovement()->GravityScale = 6.5f;
	GetCharacterMovement()->AirControl = 1.0f;
	GetCharacterMovement()->JumpZVelocity = 2500.f;
	//GetCharacterMovement()->GroundFriction = 1.0f;
	GetCharacterMovement()->MaxWalkSpeed = 1000.0f;
	GetCharacterMovement()->MaxFlySpeed = 1000.0f;

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
	isAttack = false;
	isDamaged = false;
}



//////////////////////////////////////////////////////////////////////////
// Animation

void AProjectWCharacter::UpdateAnimation()
{
	const FVector PlayerVelocity = GetVelocity();
	const float PlayerSpeedSqr = PlayerVelocity.SizeSquared();
	int animValue = 0; //Idle
	// Are we moving or standing still?
	UPaperFlipbook* DesiredAnimation = IdleAnimation;

	if (PlayerSpeedSqr > 0.0f)
		animValue = 1;
	else
		animValue = 0; // Idle

	if (isAttack == true)
		animValue = 2;


	switch (animValue)
	{
	case 0:
		DesiredAnimation = IdleAnimation;
		break;
	case 1:
		DesiredAnimation = RunningAnimation;
		break;
	case 2:
		DesiredAnimation = AttackAnimation;
		//isAttack = false;
		
		
		break;
	default:
		DesiredAnimation = IdleAnimation;
	}


	if( GetSprite()->GetFlipbook() != DesiredAnimation 	)
	{
		GetSprite()->SetFlipbook(DesiredAnimation);
	}
}

void AProjectWCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AProjectWCharacter::OnOverlapBegin);

}


void AProjectWCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	UpdateCharacter();	
}


//////////////////////////////////////////////////////////////////////////
// Input

void AProjectWCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Note: the 'Jump' action and the 'MoveRight' axis are bound to actual keys/buttons/sticks in DefaultInput.ini (editable from Project Settings..Input)
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	if(isAttack == false)
		PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &AProjectWCharacter::Attack);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AProjectWCharacter::MoveRight);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjectWCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjectWCharacter::TouchStopped);
}

void AProjectWCharacter::MoveRight(float Value)
{
	/*UpdateChar();*/
	
	// Apply the input to the character motion
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), Value);
}

void AProjectWCharacter::Attack()
{
	FTimerHandle th_Attack;
	if (isAttack == false)
	{
		isAttack = true;
		//CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AProjectWCharacter::OnOverlapBegin);
		SpawnAttackEffects();
	}
	if (isAttack == true)
	{
		GetWorldTimerManager().SetTimer(th_Attack, this, &AProjectWCharacter::AttackEnd, 0.2f, false);
		UE_LOG(LogTemp, Warning, TEXT("Attack"));
	}

		
}

void AProjectWCharacter::AttackEnd()
{
	isAttack = false;
	
}

void AProjectWCharacter::DamagedEnd()
{
	isDamaged = false;

}

void AProjectWCharacter::SpawnAttackEffects()
{
	//spawnLocation = spawnBox->GetComponentTransform().GetTranslation();
	spawnLocation = GetCapsuleComponent()->GetComponentTransform().GetTranslation();
	spawnRotation = FRotator(45.0f, 0.0f, 0.0f);

	AAttackEffect* ae = nullptr;
	ae = GetWorld()->SpawnActor<AAttackEffect>(attackEffects, spawnLocation, spawnRotation, spawnInfo);

	
}


void AProjectWCharacter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FTimerHandle th_Attack;
	if (OtherActor != nullptr)
	{
		AProjectiles* projectile = Cast<AProjectiles>(OtherActor);

		if (projectile && !isDamaged)
		{
			isDamaged = true;
			UE_LOG(LogTemp, Warning, TEXT("Projectile"));
			health -= 0.1;
			GetWorldTimerManager().SetTimer(th_Attack, this, &AProjectWCharacter::DamagedEnd, 1.0f, false);
			
		}
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

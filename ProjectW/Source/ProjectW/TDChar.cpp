// Fill out your copyright notice in the Description page of Project Settings.


#include "TDChar.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectWGameMode.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)

ATDChar::ATDChar()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

}
void ATDChar::BeginPlay()
{
	Super::BeginPlay();
	TDCharState = ETDCharStates::TDCharState_Idle;

	m_bisDefault = true;
	m_bisFront = false;
	m_bisSide = false;
	m_bisBack = false;
	m_bisRight = true;
}

void ATDChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateAnimation();
}

void ATDChar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveRight", this, &ATDChar::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ATDChar::MoveUp);

}

void ATDChar::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
	if (Value > 0 && m_bisDefault)
	{
		SetState(ETDCharStates::TDCharState_Run);
		m_bisDefault = false;
		//m_bisFront = false;
		//m_bisBack = false;
		m_bisSide = true;
		if (!m_bisRight)
			Flip();
	}
	if (Value < 0 && m_bisDefault)
	{
		SetState(ETDCharStates::TDCharState_Run);
		m_bisDefault = false;
		//m_bisFront = false;
		//m_bisBack = false;
		m_bisSide = true;
		if (m_bisRight)
			Flip();
	}
	else if (Value == 0 && !m_bisFront && !m_bisBack)
	{
		SetState(ETDCharStates::TDCharState_Idle);
		m_bisDefault = true;
		m_bisSide = false;
	}
}

void ATDChar::MoveUp(float Value)
{
	if (Value > 0 && m_bisDefault && !m_bisFront)
	{
		SetState(ETDCharStates::TDCharState_Run);
		// Front °¡ True
		m_bisDefault = false;
		m_bisFront = true;
		m_bisBack = false;
		//m_bisSide = false;
		//PrintString(TEXT("Front"));
	}
	else if (Value < 0 && m_bisDefault && !m_bisBack)
	{
		SetState(ETDCharStates::TDCharState_Run);
		// Front °¡ False
		m_bisDefault = false;
		m_bisFront = false;
		m_bisBack = true;
		//m_bisSide = false;
		//PrintString(TEXT("Back"));
	}
	else if (Value == 0 && !m_bisSide)
	{
		SetState(ETDCharStates::TDCharState_Idle);
		
		m_bisDefault = true;
		m_bisFront = false;
		m_bisBack = false;

		//PrintString(TEXT("No Movement"));
	}
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void ATDChar::Dash()
{
}

void ATDChar::UpdateAnimation()
{
	UPaperFlipbook* anim = nullptr;

	switch (TDCharState)
	{
	case(ETDCharStates::TDCharState_Idle):
		if (m_bisFront || m_bisDefault)
			anim = Front_TDIdleAnim;
		else if (m_bisSide)
			anim = Side_TDIdleAnim;
		else if (m_bisBack)
			anim = Back_TDIdleAnim;
		break;
	case(ETDCharStates::TDCharState_Run):
		if (m_bisFront)
			anim = Front_TDRunAnim;
		else if (m_bisSide)
			anim = Side_TDRunAnim;
		else if (m_bisBack)
			anim = Back_TDRunAnim;
		break;
	}

	GetSprite()->SetFlipbook(anim);
}


void ATDChar::SetState(ETDCharStates NewState)
{
	if (TDCharState != ETDCharStates::TDCharState_Dead)
		TDCharState = NewState;
}

void ATDChar::Flip()
{
	FVector scale = GetSprite()->GetRelativeScale3D();
	scale.X *= -1;
	//SetActorScale3D(scale);
	GetSprite()->SetRelativeScale3D(scale);
	m_bisRight = !m_bisRight;
}

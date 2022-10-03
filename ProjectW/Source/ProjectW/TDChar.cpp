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



	// Privates Member variables
	RightValue = 0.0f;
	UpValue = 0.0f;
	m_bisCanMove = true;
	m_bisDefault = true;
	m_bisFront = false;
	m_bisSide = false;
	m_bisBack = false;
	m_bisRight = true;
	m_bisDashStart = false;
	m_bisDashEnd = false;
	m_bisAttacking = false;
	m_bisFirstAttack = false;
	m_bisLastAttack = false;

	
}

void ATDChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateAnimation();

	// Flip sprites
	if (RightValue > 0 && !m_bisRight && !m_bisAttacking)
		Flip();
	else if (RightValue < 0 && m_bisRight && !m_bisAttacking)
		Flip();


	if (m_bisDashStart && !m_bisDashEnd && !m_bisAttacking)
	{
		//PrintString(TEXT("Dashing"));
		FVector myVelocity = this->GetVelocity() * m_Walkspeed;
		FVector myPosition = this->GetActorLocation();
		this->SetActorLocation(myPosition + myVelocity * DeltaTime);
	}
	

}

void ATDChar::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAxis("MoveRight", this, &ATDChar::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ATDChar::MoveUp);
	PlayerInputComponent->BindAction("Roll", IE_Pressed, this, &ATDChar::Dash);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &ATDChar::MeleeAttack);

}
/*
* Right or Left input
* side값에 대한 정보와 sprite flip 여부를 결정함
*/
void ATDChar::MoveRight(float Value)
{
	RightValue = Value;
	
	if (m_bisCanMove && !m_bisAttacking)
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

		}
		else if (Value < 0 && m_bisDefault)
		{
			SetState(ETDCharStates::TDCharState_Run);
			m_bisDefault = false;
			//m_bisFront = false;
			//m_bisBack = false;
			m_bisSide = true;

		}
		else if (Value == 0 && !m_bisFront && !m_bisBack)
		{
			SetState(ETDCharStates::TDCharState_Idle);
			m_bisDefault = true;
			m_bisSide = false;
		}
	}
	
}
/*
* Front or back input
* front, back값에 대한 정보를 정함
*/
void ATDChar::MoveUp(float Value)
{
	UpValue = Value;
	if (m_bisCanMove && !m_bisAttacking)
	{
		SetState(ETDCharStates::TDCharState_Run);
		
		if (Value > 0 && m_bisDefault && !m_bisFront)
		{
			SetState(ETDCharStates::TDCharState_Run);
			// Front 가 True
			m_bisDefault = false;
			m_bisFront = true;
			m_bisBack = false;
			//m_bisSide = false;
			PrintString(TEXT("Front"));
		}
		else if (Value < 0 && m_bisDefault && !m_bisBack)
		{
			SetState(ETDCharStates::TDCharState_Run);
			// Front 가 False
			m_bisDefault = false;
			m_bisFront = false;
			m_bisBack = true;
			//m_bisSide = false;
			PrintString(TEXT("Back"));
		}
		
		if (Value == 0 && !m_bisSide)
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
	
}

/*
* Dash Function
* first checking dash is started or not
* change the states and do dash
*/
void ATDChar::Dash()
{
	if (!m_bisDashStart && !m_bisDashEnd && !m_bisAttacking && m_MP >= 30)
	{
		m_MP -= 30;
		m_bisDashStart = true;
		SetState(ETDCharStates::TDCharState_Dash);
		FTimerHandle DashWaitHandle;
		float WaitTime = 0.3f;
		GetWorld()->GetTimerManager().SetTimer(DashWaitHandle, FTimerDelegate::CreateLambda([&]()
			{
				m_bisCanMove = false;
				m_bisDashStart = false;
				m_bisDashEnd = true;
				//PrintString(TEXT("First Waiting"));
				FTimerHandle IdleWaitHandle;
				float WaitTime_2 = 0.2f;
				GetWorld()->GetTimerManager().SetTimer(IdleWaitHandle, FTimerDelegate::CreateLambda([&]()
					{
						SetState(ETDCharStates::TDCharState_Run);
						m_bisCanMove = true;
						m_bisDashStart = false;
						m_bisDashEnd = false;
						//PrintString("Second Waiting");

					}), WaitTime_2, false);
			}), WaitTime, false); 

	}

	
}
/*
*  Melee Attack Function
*/
void ATDChar::MeleeAttack()
{
	SetState(ETDCharStates::TDCharState_MeleeAttack);
	m_bisAttacking = true;
	if (!m_bisFirstAttack && !m_bisLastAttack)
	{
		
		m_bisFirstAttack = true;
		m_bisLastAttack = false;
		// 0.7초 후에 공격 초기화
		FTimerHandle AttackWaitHandle;
		float AttackWaitTime = 0.7f;
		GetWorld()->GetTimerManager().SetTimer(AttackWaitHandle, FTimerDelegate::CreateLambda([&]()
			{
				m_bisFirstAttack = false;
				m_bisLastAttack = false;
				m_bisAttacking = false;
				SetState(ETDCharStates::TDCharState_Run);
				PrintString(TEXT("Attack End1"));

			}), AttackWaitTime, false);
	}
	else if (m_bisFirstAttack && !m_bisLastAttack)
	{
		m_bisFirstAttack = false;
		m_bisLastAttack = true;

	}
}
void ATDChar::RangeAttack()
{

}
/*
*  Get Damage Function
*  Decrease Health when get attacked
*  We will call this function in blueprint editor.
*/
void ATDChar::GetDamage()
{
	m_HP--;
	PrintString(TEXT("health down"));
}

void ATDChar::UpdateAnimation()
{
	UPaperFlipbook* anim = nullptr;
	
	switch (TDCharState)
	{

	case (ETDCharStates::TDCharState_Idle):
		if (m_bisFront || m_bisDefault)
			anim = Front_TDIdleAnim;
		else if (m_bisSide)
			anim = Side_TDIdleAnim;
		else if (m_bisBack)
			anim = Back_TDIdleAnim;
		break;
	case (ETDCharStates::TDCharState_Run):
		if (m_bisFront)
			anim = Front_TDRunAnim;
		else if (m_bisSide)
			anim = Side_TDRunAnim;
		else if (m_bisBack)
			anim = Back_TDRunAnim;
		break;
	case (ETDCharStates::TDCharState_Dash):
		if (m_bisDashStart && !m_bisDashEnd)
			anim = TDDashStartAnim;
		else if (!m_bisDashStart && m_bisDashEnd)
			anim = TDDashEndAnim;
		break;
	case (ETDCharStates::TDCharState_MeleeAttack):
		if (m_bisFront || m_bisDefault)
		{
			if (m_bisFirstAttack && !m_bisLastAttack)
				anim = Front_TDMeleeAttackAnim_1;
			else if (!m_bisFirstAttack && m_bisLastAttack)
				anim = Front_TDMeleeAttackAnim_2;
			break;
		}
		else if (m_bisBack)
		{
			if (m_bisFirstAttack && !m_bisLastAttack)
				anim = Back_TDMeleeAttackAnim_1;
			else if (!m_bisFirstAttack && m_bisLastAttack)
				anim = Back_TDMeleeAttackAnim_2;
			break;
		}
		else if (m_bisSide)
		{
			if (m_bisFirstAttack && !m_bisLastAttack)
				anim = Back_TDMeleeAttackAnim_1;
			else if (!m_bisFirstAttack && m_bisLastAttack)
				anim = Back_TDMeleeAttackAnim_2;
			break;
		}
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

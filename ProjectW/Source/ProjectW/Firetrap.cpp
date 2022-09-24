// Fill out your copyright notice in the Description page of Project Settings.


#include "Firetrap.h"


#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::White, String)

// Sets default values
AFiretrap::AFiretrap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_pBoxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = m_pBoxCollider;

	//m_pBoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFiretrap::OnOverlapBegin);

	m_bisFireActivated = false;
}

// Called when the game starts or when spawned
void AFiretrap::BeginPlay()
{
	Super::BeginPlay();
	m_pBoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AFiretrap::OnOverlapBegin);
	// 불의 출현과 삭제를 3초마다 반복
	FTimerHandle WaitHandle;
	float WaitTime = 3; 
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			if (!m_bisFireActivated)
			{
				PrintString(TEXT("Enabled"));
				//BoxCollider->SetActive(false);
				m_bisFireActivated = !m_bisFireActivated;
			}
			else
			{
				PrintString(TEXT("Disabled"));
				//BoxCollider->SetActive(true);
				m_bisFireActivated = !m_bisFireActivated;
			}

		}), WaitTime, true); //반복도 여기서 추가 변수를 선언해 설정가능

	PrintString(TEXT("HI"));
	
}

void AFiretrap::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (m_bisFireActivated)
	{
		PrintString(TEXT("Overlapped, Fire!"));
	}
	else {
		PrintString(TEXT("Overlapped, No Fire!"));
	}

}

// Called every frame
void AFiretrap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


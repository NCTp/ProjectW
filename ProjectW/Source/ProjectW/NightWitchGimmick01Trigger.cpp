// Fill out your copyright notice in the Description page of Project Settings.


#include "NightWitchGimmick01Trigger.h"
#include "DrawDebugHelpers.h"
#include "Engine/BrushShape.h"
#include "Kismet/GameplayStatics.h"

#include "NightWitchGimmick01Manager.h"
#include "TDChar.h"

ANightWitchGimmick01Trigger::ANightWitchGimmick01Trigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ANightWitchGimmick01Trigger::OnOverlapBegin);
}



void ANightWitchGimmick01Trigger::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<ATDChar>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void ANightWitchGimmick01Trigger::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor)
	{
		if (OtherActor == Player)
		{
			GimmicManager->isActive = true;
			Destroy();
		}
	}
}

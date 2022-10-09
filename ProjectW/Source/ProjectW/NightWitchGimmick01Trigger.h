// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "NightWitchGimmick01Trigger.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTW_API ANightWitchGimmick01Trigger : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ANightWitchGimmick01Trigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class ANightWitchGimmick01Manager* GimmicManager;

	class ATDChar* Player;

private:
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
};

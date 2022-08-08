// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NightWitchTeleportPoint.generated.h"

UCLASS()
class PROJECTW_API ANightWitchTeleportPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightWitchTeleportPoint();

	FVector GetTeleportPoint(int const index) const;
	int PointNum() const;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (MakeEditWidget = "true", AllowPrivateAccess = "true"))
	TArray<FVector> TeleportPoints;
};

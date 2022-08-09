// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NightWitchLaserPortal.generated.h"

UCLASS()
class PROJECTW_API ANightWitchLaserPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightWitchLaserPortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void SpawnLaser();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Root")
	class USceneComponent* Root;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flipbook")
	class UPaperFlipbookComponent* Flipbook;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Laser")
	TSubclassOf<AActor> Laser;

	class ANightWitchLaser* LaserRef;

	class UWorld* World;

	class AProjectWCharacter* Player;

	FVector m_targetLocation;

	float timer;

	bool bLaserSpawned;
};

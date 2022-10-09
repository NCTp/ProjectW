// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NightWitchGimmick01Manager.generated.h"

UCLASS()
class PROJECTW_API ANightWitchGimmick01Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightWitchGimmick01Manager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ANWGimmick01EnemySpawnPoint* GetPortalPoints();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal")
	TSubclassOf<AActor> EnemySpawnPortal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal")
	TSubclassOf<AActor> LaserSpawnPortal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Portal")
	TSubclassOf<AActor> ChainSpawnPortal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class ANWGimmick01EnemySpawnPoint* EnemySpawnPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class ANWGimmick01LaserSpawnPoint* LaserSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class ANWGimmick01ChainSpawnPoint* ChainSpawnPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	bool isActive;
};

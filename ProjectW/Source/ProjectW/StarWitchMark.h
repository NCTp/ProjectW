// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StarWitchMark.generated.h"

class AStarWitchThunder;

UCLASS()
class PROJECTW_API AStarWitchMark : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarWitchMark();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Effects)
	TSubclassOf<AStarWitchThunder> Effects_Thunder;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	APawn* Player;

private:
	void DestroyMyself();
	void SpawnThunder();

	FActorSpawnParameters spawnInfo = FActorSpawnParameters();
};

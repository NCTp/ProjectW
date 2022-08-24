// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StarWitchRotatingVolt.generated.h"

UCLASS()
class PROJECTW_API AStarWitchRotatingVolt : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStarWitchRotatingVolt();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Movement)
		FVector Dimensions;

	UPROPERTY(EditAnywhere, Category = Movement)
		FVector AxisVector;

	UPROPERTY(EditAnywhere, Category = Movement)
		float multiplier;

	UPROPERTY(EditAnywhere, Category = Movement)
		float AngleAxis;



private:
	void DestroyMyself();
	void Rotate(float DeltaTime);
	void Shoot(float DeltaTime);
	void ChangeState();

	TArray<AActor*> starWitch;
	AActor* Player;
	FVector PlayerLocation;
	FVector PlayerDirection;

	bool m_isRotating;
	bool m_isShooting;
	bool m_isLockingOn;
};

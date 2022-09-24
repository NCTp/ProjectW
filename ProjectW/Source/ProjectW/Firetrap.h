// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Firetrap.generated.h"

UCLASS()
class PROJECTW_API AFiretrap : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	UBoxComponent* m_pBoxCollider;


	// 불 데이지를 입히기 위한 bool값
	UPROPERTY(EditAnywhere)
	bool m_bisFireActivated;


public:	
	// Sets default values for this actor's properties
	AFiretrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor, class UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

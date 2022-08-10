// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NightWitchChainPortal.generated.h"

UCLASS()
class PROJECTW_API ANightWitchChainPortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANightWitchChainPortal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flipbook")
	class UPaperFlipbookComponent* Flipbook;

	class UWorld* World;

	class AProjectWCharacter* Player;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chain")
	TSubclassOf<AActor> Chain;

	class ANightWitchChain* ChainRef;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chain Hook")
	TSubclassOf<AActor> ChainHook;

	class ANightWitchChainHook* ChainHookRef;

	FVector m_targetLocation;
};

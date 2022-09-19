#pragma once

#include "GameFramework/Actor.h"
#include "LevelStreamerActor.generated.h"

UCLASS()
class LEVELS_API ALevelStreamerActor : public AActor
{
    GENERATED_BODY()

public:
    // 이 액터 프로퍼티에 대한 기본값을 설정합니다.
    ALevelStreamerActor();

    // 매 프레임 호출됩니다.
    virtual void Tick(float DeltaSeconds) override;

protected:

    // 게임 시작 또는 스폰시 호출됩니다.
    virtual void BeginPlay() override;

    UFUNCTION()
        void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere)
        FName LevelToLoad;

private:
    // 레벨 스트리밍을 발동시킬 오버랩 볼륨입니다.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
        UBoxComponent* OverlapVolume;

};
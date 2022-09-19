#pragma once

#include "GameFramework/Actor.h"
#include "LevelStreamerActor.generated.h"

UCLASS()
class LEVELS_API ALevelStreamerActor : public AActor
{
    GENERATED_BODY()

public:
    // �� ���� ������Ƽ�� ���� �⺻���� �����մϴ�.
    ALevelStreamerActor();

    // �� ������ ȣ��˴ϴ�.
    virtual void Tick(float DeltaSeconds) override;

protected:

    // ���� ���� �Ǵ� ������ ȣ��˴ϴ�.
    virtual void BeginPlay() override;

    UFUNCTION()
        void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UPROPERTY(EditAnywhere)
        FName LevelToLoad;

private:
    // ���� ��Ʈ������ �ߵ���ų ������ �����Դϴ�.
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
        UBoxComponent* OverlapVolume;

};
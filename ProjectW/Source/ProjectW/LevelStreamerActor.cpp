#include "Levels.h"
#include "Kismet/GameplayStatics.h"
#include "LevelStreamerActor.h"


// 기본값을 설정합니다.
ALevelStreamerActor::ALevelStreamerActor()
{
    // 이 액터가 Tick() 을 매 프레임 호출하도록 설정합니다. 이 기능이 필요치 않은 경우 끄면 퍼포먼스가 향상됩니다.
    PrimaryActorTick.bCanEverTick = true;

    OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
    RootComponent = OverlapVolume;

    OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamerActor::OverlapBegins);
}
// 게임 시작 또는 스폰시 호출됩니다.
void ALevelStreamerActor::BeginPlay()
{
    Super::BeginPlay();

}

// 매 프레임 호출됩니다.
void ALevelStreamerActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void ALevelStreamerActor::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (OtherActor == MyCharacter && LevelToLoad != "")
    {
        FLatentActionInfo LatentInfo;
        UGameplayStatics::LoadStreamLevel(this, LevelToLoad, true, true, LatentInfo);
    }
}
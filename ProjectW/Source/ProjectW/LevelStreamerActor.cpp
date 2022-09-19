#include "Levels.h"
#include "Kismet/GameplayStatics.h"
#include "LevelStreamerActor.h"


// �⺻���� �����մϴ�.
ALevelStreamerActor::ALevelStreamerActor()
{
    // �� ���Ͱ� Tick() �� �� ������ ȣ���ϵ��� �����մϴ�. �� ����� �ʿ�ġ ���� ��� ���� �����ս��� ���˴ϴ�.
    PrimaryActorTick.bCanEverTick = true;

    OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
    RootComponent = OverlapVolume;

    OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamerActor::OverlapBegins);
}
// ���� ���� �Ǵ� ������ ȣ��˴ϴ�.
void ALevelStreamerActor::BeginPlay()
{
    Super::BeginPlay();

}

// �� ������ ȣ��˴ϴ�.
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
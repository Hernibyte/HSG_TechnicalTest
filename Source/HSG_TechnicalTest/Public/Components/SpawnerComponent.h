// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnerComponent.generated.h"


class ISpawnable;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HSG_TECHNICALTEST_API USpawnerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USpawnerComponent();

	virtual void BeginPlay() override;
	
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable)
	void TrySpawnActors();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SpawnAreaOffsetLocation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator SpawnAreaOffsetRotation;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector SpawnAreaScale;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bShowSpawnArea = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount_ActorsToSpawn = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeSpan = 0.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner", meta = (MustImplement = "/Scripts/HSG_TechnicalTest.Spawnable"))
	TSubclassOf<AActor> ActorToSpawn;
	
protected:
	FVector GetRandomPointInOrientedBox();
	
};

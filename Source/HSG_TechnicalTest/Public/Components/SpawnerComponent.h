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

	/**
	 * Execute the Spawn Actors implementation.
	 */
	UFUNCTION(BlueprintCallable)
	void TrySpawnActors();

	UFUNCTION(BlueprintCallable)
	void SetSpawnAreaLocation(FVector InSpawnAreaLocation) { SpawnAreaLocation = InSpawnAreaLocation; }
	
	UFUNCTION(BlueprintCallable)
	void SetSpawnAreaRotation(FRotator InSpawnAreaRotation) { SpawnAreaRotation = InSpawnAreaRotation; }
	
	UFUNCTION(BlueprintCallable)
	void SetSpawnAreaScale(FVector InSpawnAreaScale) { SpawnAreaScale = InSpawnAreaScale; }
	
	/**
	 * Amount of actors to spawn.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Amount_ActorsToSpawn = 0;

	/**
	 * Life span of spawned actors
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LifeSpan = 0.0f;

	/**
	 * If true, adjust if posible but always spawn.
	 * If false, adjust if posible but don't spawn if colliding.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bForceSpawnOnCollision = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawner", meta = (MustImplement = "/Scripts/HSG_TechnicalTest.Spawnable"))
	TSubclassOf<AActor> ActorToSpawn;
	
protected:
	/**
	 * 
	 * @return A Random Point on Spawn bounds.
	 */
	FVector GetRandomPointInOrientedBox();
	
	UPROPERTY()
	FVector SpawnAreaLocation;
	
	UPROPERTY()
	FRotator SpawnAreaRotation;
	
	UPROPERTY()
	FVector SpawnAreaScale;
	
};

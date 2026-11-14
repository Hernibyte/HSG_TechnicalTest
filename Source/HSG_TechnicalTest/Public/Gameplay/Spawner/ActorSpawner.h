// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "ActorSpawner.generated.h"

class UHSG_UserWidget;
class USpawnerComponent;
class UBoxComponent;

UCLASS()
class HSG_TECHNICALTEST_API AActorSpawner : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AActorSpawner();

	virtual void Tick(float DeltaTime) override;
	
	/**
	 * Execute the interaction.
	 * @param Interactor Actor requesting that interaction. 
	 */
	virtual void Interact_Implementation(AActor* Interactor) override;

	/**
	 * Call TrySpawnActors from SpawnerComponent.
	 * @param InAmount Set amount of actors to spawn.
	 * @param InLifeSpan Set life span of spawned actors.
	 */
	UFUNCTION(BlueprintCallable)
	void TrySpawnActors(int InAmount, float InLifeSpan);
	
protected:
	virtual void BeginPlay() override;

	/**
	 * Widget to request on interaction.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UHSG_UserWidget> WidgetClass;

	/**
	 * Spawner Component.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USpawnerComponent> C_Spawner;

	/**
	 * Box Component for set Spawner bounds and editor debugging.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UBoxComponent> C_Box;
	
};

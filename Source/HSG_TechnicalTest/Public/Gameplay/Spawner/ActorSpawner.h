// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "ActorSpawner.generated.h"

class USpawnerComponent;

UCLASS()
class HSG_TECHNICALTEST_API AActorSpawner : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AActorSpawner();

	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact(AActor* Interactor) override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USpawnerComponent> C_Spawner;
	
};

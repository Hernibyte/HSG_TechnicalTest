// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "ActorSpawner.generated.h"

class UHSG_UserWidget;
class USpawnerComponent;

UCLASS()
class HSG_TECHNICALTEST_API AActorSpawner : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AActorSpawner();

	virtual void Tick(float DeltaTime) override;
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	
	UFUNCTION(BlueprintCallable)
	void TrySpawnActors(int InAmount, float InLifeSpan);
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UHSG_UserWidget> WidgetClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USpawnerComponent> C_Spawner;
	
};

// HSG Technical Test


#include "Gameplay/Spawner/ActorSpawner.h"

#include "Gameplay/Systems/SpawnerComponent.h"


AActorSpawner::AActorSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	C_Spawner = CreateDefaultSubobject<USpawnerComponent>("C_Spawner");
}

void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorSpawner::Interact(AActor* Interactor)
{
	// TODO: Pop up the Widget here
}

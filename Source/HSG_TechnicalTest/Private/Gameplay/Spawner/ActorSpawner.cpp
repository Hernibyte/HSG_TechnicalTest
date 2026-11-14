// HSG Technical Test


#include "Gameplay/Spawner/ActorSpawner.h"

#include "Components/BoxComponent.h"
#include "Components/SpawnerComponent.h"
#include "Interfaces/WidgetRequester.h"

AActorSpawner::AActorSpawner()
{
	PrimaryActorTick.bCanEverTick = true;
	
	C_Spawner = CreateDefaultSubobject<USpawnerComponent>("Spawner Component");
	
	C_Box = CreateDefaultSubobject<UBoxComponent>("Box Component");
}

void AActorSpawner::BeginPlay()
{
	Super::BeginPlay();
}

void AActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorSpawner::Interact_Implementation(AActor* Interactor)
{
	IInteractable::Interact_Implementation(Interactor);
	
	// Search for WidgetRequester interface
	if (const APawn* Pawn = Cast<APawn>(Interactor))
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->GetController());
		if (PC && PC->GetClass()->ImplementsInterface(UWidgetRequester::StaticClass()))
		{
			IWidgetRequester::Execute_RequestOpenWidget(PC, WidgetClass, this);
		}
	}
}

void AActorSpawner::TrySpawnActors(int InAmount, float InLifeSpan)
{
	C_Spawner->Amount_ActorsToSpawn = InAmount;
	C_Spawner->LifeSpan = InLifeSpan;
	
	C_Spawner->SetSpawnAreaLocation(C_Box->GetComponentLocation());
	C_Spawner->SetSpawnAreaRotation(GetActorRotation());
	C_Spawner->SetSpawnAreaScale(C_Box->GetUnscaledBoxExtent());
	
	C_Spawner->TrySpawnActors();
}

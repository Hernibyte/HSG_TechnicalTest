// HSG Technical Test


#include "Components/SpawnerComponent.h"


USpawnerComponent::USpawnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void USpawnerComponent::BeginPlay()
{
	Super::BeginPlay();

}

void USpawnerComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	if (bShowSpawnArea)
	{
		DrawDebugBox(
			GetWorld(),
			GetOwner()->GetActorLocation() + SpawnAreaOffsetLocation,
			SpawnAreaScale,       // Extent
			(GetOwner()->GetActorRotation() + SpawnAreaOffsetRotation).Quaternion(), // Rotación
			FColor::Red,
			false,                           // Persistent
			-1.0f,                            // Duration
			0,
			1.5f                             // Grosor
		);
	}
}

void USpawnerComponent::TrySpawnActors()
{
	for (int i = 0; i < Amount_ActorsToSpawn; i++)
	{
		FVector SpawnLocation = GetRandomPointInOrientedBox();
		FActorSpawnParameters SpawnParameters;
		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParameters);
		NewActor->SetLifeSpan(LifeSpan);
	}
}

FVector USpawnerComponent::GetRandomPointInOrientedBox()
{
	// 1. Convertimos Scale a Extent (mitad del tamaño)
	const FVector Extent = SpawnAreaScale;

	// 2. Generamos un punto aleatorio en espacio local (AABB centrada en origen)
	const FVector RandomLocal(
		FMath::FRandRange(-Extent.X, Extent.X),
		FMath::FRandRange(-Extent.Y, Extent.Y),
		FMath::FRandRange(-Extent.Z, Extent.Z)
	);

	// 3. Aplicamos la rotación y luego la traslación
	return (GetOwner()->GetActorLocation() + SpawnAreaOffsetLocation) + (GetOwner()->GetActorRotation() + SpawnAreaOffsetRotation).RotateVector(RandomLocal);
}

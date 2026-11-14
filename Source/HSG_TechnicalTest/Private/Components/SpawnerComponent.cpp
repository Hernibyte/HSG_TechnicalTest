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
	
}

void USpawnerComponent::TrySpawnActors()
{
	for (int i = 0; i < Amount_ActorsToSpawn; i++)
	{
		FVector SpawnLocation = GetRandomPointInOrientedBox();
		
		// Ajustar los parametros de spawn principalmente para que se pueda tener la opcion de ajustar si puede 
		// y si no puede que lo genere de todas formas o que no lo genere dependiendo de bForceSpawnOnCollision
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = GetOwner();
		SpawnParameters.Instigator = GetOwner()->GetInstigator();
		SpawnParameters.SpawnCollisionHandlingOverride = bForceSpawnOnCollision ? ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn : ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		if (AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator, SpawnParameters))
		{
			NewActor->SetLifeSpan(LifeSpan);
		}
	}
}

FVector USpawnerComponent::GetRandomPointInOrientedBox()
{
	const FVector Extent = SpawnAreaScale;

	// 2. Generamos un punto aleatorio en espacio local (AABB centrada en origen)
	const FVector RandomLocal(
		FMath::FRandRange(-Extent.X, Extent.X),
		FMath::FRandRange(-Extent.Y, Extent.Y),
		FMath::FRandRange(-Extent.Z, Extent.Z)
	);

	// 3. Aplicamos la rotación y luego la traslación
	return SpawnAreaLocation + GetOwner()->GetActorRotation().RotateVector(RandomLocal);
}

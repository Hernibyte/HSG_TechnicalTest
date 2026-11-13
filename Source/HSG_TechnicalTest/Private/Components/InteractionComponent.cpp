// HSG Technical Test


#include "HSG_TechnicalTest/Public/Components/InteractionComponent.h"

#include "HSG_TechnicalTest/Public/Interfaces/Interactable.h"
#include "Kismet/KismetSystemLibrary.h"


UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInteractionComponent::TryInteract(const FVector& StartTraceLocation, const FVector& EndTraceLocation)
{
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	
	TArray<FHitResult> HitResults;
	
	const bool bHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(), 
		StartTraceLocation, 
		EndTraceLocation, 
		CheckSphereRadius, 
		UEngineTypes::ConvertToTraceType(ECC_Camera), 
		false, 
		ActorsToIgnore, 
		bDrawDebugTrace? EDrawDebugTrace::ForDuration : EDrawDebugTrace::None,
		HitResults,
		true
	);
	
	if (bHit)
	{
		for (const FHitResult& HitResult : HitResults)
		{
			if (HitResult.GetActor() && HitResult.GetActor()->Implements<UInteractable>())
			{
				Cast<IInteractable>(HitResult.GetActor())->Interact(GetOwner());
			}
		}
	}
}

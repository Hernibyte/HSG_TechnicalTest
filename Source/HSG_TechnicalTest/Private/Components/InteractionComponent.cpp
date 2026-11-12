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

void UInteractionComponent::TryInteract()
{
	const FVector Start = GetOwner()->GetActorLocation();
	const FVector End = GetOwner()->GetActorLocation();
	
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GetOwner());
	
	TArray<FHitResult> HitResults;
	
	const bool bHit = UKismetSystemLibrary::SphereTraceMulti(
		GetWorld(), 
		Start, 
		End, 
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

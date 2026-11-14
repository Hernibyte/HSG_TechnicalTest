// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class HSG_TECHNICALTEST_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionComponent();

	virtual void BeginPlay() override;

	/**
	 * Execute interact implementation.
	 * @param StartTraceLocation Start location of Sphere Trace.
	 * @param EndTraceLocation End location of Sphere Trace.
	 */
	void TryInteract(const FVector& StartTraceLocation, const FVector& EndTraceLocation);
	
protected:
	/**
	 * Radius of the Sphere Trace.
	 */
	UPROPERTY(EditAnywhere)
	float CheckSphereRadius = 10.f;

	/**
	 * If True, show the Sphere Debug Trace.
	 */
	UPROPERTY(EditAnywhere)
	bool bDrawDebugTrace = false;
	
};

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

	void TryInteract(const FVector& StartTraceLocation, const FVector& EndTraceLocation);
	
protected:
	UPROPERTY(EditAnywhere)
	float CheckSphereRadius = 10.f;
	
	UPROPERTY(EditAnywhere)
	bool bDrawDebugTrace = false;
	
};

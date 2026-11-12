// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HSG_TECHNICALTEST_API IInteractable
{
	GENERATED_BODY()

public:
	virtual void Interact(AActor* Interactor) = 0;
	
};

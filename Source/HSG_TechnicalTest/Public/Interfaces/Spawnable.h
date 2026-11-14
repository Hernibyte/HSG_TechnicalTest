// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Spawnable.generated.h"

UINTERFACE()
class USpawnable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HSG_TECHNICALTEST_API ISpawnable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool CanBeSpawned();
	
	
};

// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HSG_UserWidget.generated.h"

/**
 * 
 */
UCLASS()
class HSG_TECHNICALTEST_API UHSG_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetSourceActor(AActor* InSourceActor);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> SourceActor;
	
};

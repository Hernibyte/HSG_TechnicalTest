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
	
	void CloseWidget(const FInputModeDataBase& InputMode = FInputModeGameOnly(), bool ShowMouseCursor = false);
	
protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> SourceActor;
	
};

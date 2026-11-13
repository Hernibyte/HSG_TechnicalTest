// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WidgetRequester.generated.h"

class UHSG_UserWidget;

UINTERFACE()
class UWidgetRequester : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class HSG_TECHNICALTEST_API IWidgetRequester
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RequestOpenWidget(TSubclassOf<UHSG_UserWidget> WidgetClass, AActor* SourceActor);
	
};

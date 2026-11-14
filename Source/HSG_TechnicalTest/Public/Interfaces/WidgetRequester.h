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
	/**
	 * Receive a widget class to implement on player.
	 * @param WidgetClass Widget to be created.
	 * @param SourceActor Actor requesting that widget.
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void RequestOpenWidget(TSubclassOf<UHSG_UserWidget> WidgetClass, AActor* SourceActor);
	
};

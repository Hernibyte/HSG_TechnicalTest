// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "HSG_TechnicalTest/Public/Controllers/HSGBaseController.h"
#include "Interfaces/WidgetRequester.h"
#include "HSGPlayerController.generated.h"

class UHSG_UserWidget;

/**
 * 
 */
UCLASS()
class HSG_TECHNICALTEST_API AHSGPlayerController : public AHSGBaseController, public IWidgetRequester
{
	GENERATED_BODY()
	
public:
	virtual void RequestOpenWidget_Implementation(TSubclassOf<UHSG_UserWidget> WidgetClass, AActor* SourceActor) override;
	
};

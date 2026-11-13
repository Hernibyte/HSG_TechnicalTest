// HSG Technical Test


#include "HSG_TechnicalTest/Public/Controllers/Player/HSGPlayerController.h"

#include "UI/HSG_UserWidget.h"

void AHSGPlayerController::RequestOpenWidget_Implementation(TSubclassOf<UHSG_UserWidget> WidgetClass, AActor* SourceActor)
{
	IWidgetRequester::RequestOpenWidget_Implementation(WidgetClass, SourceActor);

	if (UHSG_UserWidget* Widget = Cast<UHSG_UserWidget>(CreateWidget(this, WidgetClass)))
	{
		Widget->AddToViewport();
		Widget->SetSourceActor(SourceActor);
		
		SetInputMode(FInputModeUIOnly());
		bShowMouseCursor = true;
	}
}

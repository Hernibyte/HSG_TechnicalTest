// HSG Technical Test


#include "UI/HSG_UserWidget.h"

void UHSG_UserWidget::SetSourceActor(AActor* InSourceActor)
{
	SourceActor = InSourceActor;
}

void UHSG_UserWidget::CloseWidget(const FInputModeDataBase& InputMode, bool ShowMouseCursor)
{
	GetOwningPlayer()->SetInputMode(FInputModeGameOnly());
	GetOwningPlayer()->SetShowMouseCursor(false);
	RemoveFromParent();
}

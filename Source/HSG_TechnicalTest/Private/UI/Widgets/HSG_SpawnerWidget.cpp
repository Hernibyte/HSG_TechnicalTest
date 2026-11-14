// HSG Technical Test


#include "UI/Widgets/HSG_SpawnerWidget.h"

#include "Components/Button.h"
#include "Components/SpinBox.h"
#include "Gameplay/Spawner/ActorSpawner.h"

void UHSG_SpawnerWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	ConfirmationButton->OnClicked.AddDynamic(this, &UHSG_SpawnerWidget::OnConfirmationButtonClicked);
	CancelButton->OnClicked.AddDynamic(this, &UHSG_SpawnerWidget::OnCancelButtonClicked);
}

void UHSG_SpawnerWidget::OnConfirmationButtonClicked()
{
	if (SourceActor)
	{
		if (auto* Spawner = Cast<AActorSpawner>(SourceActor))
		{
			Spawner->TrySpawnActors(Amount->Value, LifeSpan->Value);
		}
	}
	CloseWidget();
}

void UHSG_SpawnerWidget::OnCancelButtonClicked()
{
	CloseWidget();
}

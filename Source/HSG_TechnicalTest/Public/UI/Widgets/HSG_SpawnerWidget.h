// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "UI/HSG_UserWidget.h"
#include "HSG_SpawnerWidget.generated.h"

class UVerticalBox;
class UHorizontalBox;
class UButton;
class UTextBlock;
class USpinBox;

/**
 * 
 */
UCLASS()
class HSG_TECHNICALTEST_API UHSG_SpawnerWidget : public UHSG_UserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ConfirmationButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CancelButton;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> LifeSpanTextBlock;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> AmountTextBlock;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USpinBox> Amount;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USpinBox> LifeSpan;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> AmountCombo;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UHorizontalBox> LifeSpanCombo;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVerticalBox> VerticalCombo;
	
protected:
	UFUNCTION()
	void OnConfirmationButtonClicked();
	
	UFUNCTION()
	void OnCancelButtonClicked();
	
};

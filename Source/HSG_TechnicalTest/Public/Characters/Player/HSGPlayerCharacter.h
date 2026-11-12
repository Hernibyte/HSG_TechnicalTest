// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "HSG_TechnicalTest/Public/Characters/HSGBaseCharacter.h"
#include "HSGPlayerCharacter.generated.h"

class UInteractionComponent;
class UInputAction;
class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class HSG_TECHNICALTEST_API AHSGPlayerCharacter : public AHSGBaseCharacter
{
	GENERATED_BODY()

public:
	AHSGPlayerCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void PawnClientRestart() override;
	
protected:
	/**
	 * Input Action for movement.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> IA_Movement;
	
	/**
	 * Input Action for Camera movement.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> IA_Look;
	
	/**
	 * Input Action for Jump.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> IA_Jump;

	/**
	 * Input Action for Interact.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> IA_Interact;
	
	/**
	 * Default Input Mapping Context.
	 */
	UPROPERTY(EditAnywhere, Category="Input")
	TSoftObjectPtr<UInputMappingContext> IMC_Default;
	
	/**
	 * Default IMC Priority.
	 */
	UPROPERTY(EditAnywhere, Category="Input")
	int32 IMC_Default_Priority = 0;

	/**
	 * Spring Arm Component.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USpringArmComponent> C_SpringArm;

	/**
	 * Camera Component.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> C_Camera;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInteractionComponent> C_Interaction;
	
private:
	void PerformMovement(const FInputActionValue& Value);
	void PerformLook(const FInputActionValue& Value);
	void PerformStartJump();
	void PerformStopJumping();
	void PerformInteract();
	
};

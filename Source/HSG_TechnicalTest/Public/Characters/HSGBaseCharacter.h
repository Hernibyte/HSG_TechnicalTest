// HSG Technical Test

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HSGBaseCharacter.generated.h"


UCLASS()
class HSG_TECHNICALTEST_API AHSGBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AHSGBaseCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};

// HSG Technical Test


#include "HSG_TechnicalTest/Public/Characters/HSGBaseCharacter.h"


AHSGBaseCharacter::AHSGBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void AHSGBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHSGBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHSGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

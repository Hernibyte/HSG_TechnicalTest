// HSG Technical Test


#include "HSG_TechnicalTest/Public/Characters/Player/HSGPlayerCharacter.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "HSG_TechnicalTest/Public/Components/InteractionComponent.h"
#include "Kismet/KismetMathLibrary.h"


AHSGPlayerCharacter::AHSGPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -97.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));
	
	C_SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	C_Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	C_Interaction = CreateDefaultSubobject<UInteractionComponent>("Interactions");
	
	C_SpringArm->SetupAttachment(GetRootComponent());
	C_SpringArm->SetRelativeLocation(FVector(0.0f, 0.0f, 60.f));
	C_SpringArm->bUsePawnControlRotation = true;
	
	C_Camera->SetupAttachment(C_SpringArm);
	
	bUseControllerRotationYaw = false;
}

void AHSGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHSGPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHSGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EIC->BindAction(IA_Movement, ETriggerEvent::Triggered, this, &AHSGPlayerCharacter::PerformMovement);
		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AHSGPlayerCharacter::PerformLook);
		EIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &AHSGPlayerCharacter::PerformStartJump);
		EIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AHSGPlayerCharacter::PerformStopJumping);
		EIC->BindAction(IA_Interact, ETriggerEvent::Started, this, &AHSGPlayerCharacter::PerformInteract);
	}
}

void AHSGPlayerCharacter::PawnClientRestart()
{
	Super::PawnClientRestart();
	
	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			if (!IMC_Default.IsNull())
			{
				Subsystem->AddMappingContext(IMC_Default.LoadSynchronous(), IMC_Default_Priority);
			}
		}
	}
}

void AHSGPlayerCharacter::PerformMovement(const FInputActionValue& Value)
{
	const FVector2D MovementValue = Value.Get<FVector2D>();
	const FRotator FwdRotationValue = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	const FRotator RgtRotationValue = FRotator(0.f, GetControlRotation().Yaw, GetControlRotation().Roll);
	
	const FVector ForwardDirection = UKismetMathLibrary::GetForwardVector(FwdRotationValue);
	AddMovementInput(ForwardDirection, MovementValue.X);
	
	const FVector RightDirection = UKismetMathLibrary::GetRightVector(RgtRotationValue);
	AddMovementInput(RightDirection, MovementValue.Y);
}

void AHSGPlayerCharacter::PerformLook(const FInputActionValue& Value)
{
	const FVector2D LookValue = Value.Get<FVector2D>();
	
	AddControllerYawInput(LookValue.X);
	AddControllerPitchInput(-LookValue.Y);
}

void AHSGPlayerCharacter::PerformStartJump()
{
	Super::Jump();
}

void AHSGPlayerCharacter::PerformStopJumping()
{
	Super::StopJumping();
}

void AHSGPlayerCharacter::PerformInteract()
{
	const FVector Start = GetActorLocation();
	const FVector End = GetActorLocation();
	
	C_Interaction->TryInteract(Start, End);
}

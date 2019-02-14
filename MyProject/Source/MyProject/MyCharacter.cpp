#include "MyCharacter.h"
#include "Engine.h"
AMyCharacter::AMyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
	if(!InInputComponent)
	{
		return;
	}
	InInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	InInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	InInputComponent->BindAxis(TEXT("Turn"), this, &ACharacter::AddControllerYawInput);
	InInputComponent->BindAxis(TEXT("LookUp"), this, &ACharacter::AddControllerPitchInput);
	InInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyCharacter::StartJump);
	InInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyCharacter::StopJump);
	InInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AMyCharacter::Fire);
}
void AMyCharacter::MoveForward(float InValue)
{
	MoveCore(EAxis::X, InValue);
}
void AMyCharacter::MoveRight(float InValue)
{
	MoveCore(EAxis::Y, InValue);
}
void AMyCharacter::MoveCore(EAxis::Type InAxis, float InValue)
{
	if(Controller)
	{
		AddMovementInput(FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(InAxis), InValue);
	}
}
void AMyCharacter::StartJump()
{
	bPressedJump = true;
}
void AMyCharacter::StopJump()
{
	bPressedJump = false;
}

void AMyCharacter::Fire()
{
}

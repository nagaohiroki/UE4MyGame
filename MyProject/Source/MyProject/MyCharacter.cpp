#include "MyCharacter.h"
#include "Engine.h"
AMyCharacter::AMyCharacter()
{
}
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(!PlayerInputComponent)
	{
		return;
	}
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ACharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ACharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyCharacter::StartJump);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyCharacter::StopJump);
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

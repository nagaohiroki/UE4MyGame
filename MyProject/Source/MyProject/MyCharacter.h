#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"
UCLASS()
class MYPROJECT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	explicit AMyCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InInputComponent) override;
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveCore(EAxis::Type InAxis, float InValue);
	void StartJump();
	void StopJump();
};

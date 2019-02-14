#pragma once
#include "CoreMinimal.h"
#include "MySaveGame.h"
#include "GameFramework/Actor.h"
#include "MySaveEditor.generated.h"
UCLASS()
class MYPROJECT_API AMySaveEditor : public AActor
{
	GENERATED_BODY()
public:	
	explicit AMySaveEditor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	UPROPERTY(EditAnywhere, Category="Edit")
	FSavedata Savedata;
	UFUNCTION(CallInEditor)
	void Save();
	UFUNCTION(CallInEditor)
	void Load();
};

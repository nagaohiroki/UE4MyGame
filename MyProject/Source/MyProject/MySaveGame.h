#pragma once
#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

USTRUCT(BlueprintType)
struct FSavedata
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category="Edit")
	int32 Index = 0;
};

UCLASS(BlueprintType)
class MYPROJECT_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UMySaveGame();
	UPROPERTY(EditAnywhere, Category="Edit")
	FSavedata Savedata;
};

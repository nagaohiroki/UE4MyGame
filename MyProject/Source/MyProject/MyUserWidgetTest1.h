#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidgetTest1.generated.h"
class UMyUserWidgetTest;
UCLASS(BlueprintType)
class MYPROJECT_API UMyUserWidgetTest1 : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UMyUserWidgetTest* Test = nullptr;
};

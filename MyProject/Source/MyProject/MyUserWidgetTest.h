#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidgetTest.generated.h"
class UTextBlock;
class UMyUserWidget;
UCLASS(BlueprintType)
class MYPROJECT_API UMyUserWidgetTest : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};

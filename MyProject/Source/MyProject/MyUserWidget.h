#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"
class UTextBlock;
class UWidgetAnimation;
class UButton;
UCLASS()
class MYPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UMyUserWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* Text = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidgetAnim))
	UWidgetAnimation* Start = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* SaveButton = nullptr;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* LoadButton = nullptr;
	UFUNCTION()
	void Save();
	UFUNCTION()
	void Load();
};

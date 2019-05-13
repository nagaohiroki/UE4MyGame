#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"
class UTextBlock;
class UWidgetAnimation;
class UButton;
class UImage;
class UTexture2D;
UCLASS(BlueprintType)
class MYPROJECT_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UMyUserWidget(const FObjectInitializer& ObjectInitializer);
	virtual void NativeConstruct() override;
	UFUNCTION(BlueprintCallable)
	void ChangeImage();
protected:
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UTextBlock * Text = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidgetAnim))
	UWidgetAnimation * Start = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton * SaveButton = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidget))
	UButton * LoadButton = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidgetOptional))
	UButton * TestButton = nullptr;
	UPROPERTY(EditAnywhere, meta = (BindWidgetOptional))
	UImage * Image_0 = nullptr;
	UFUNCTION()
	void Save();
	UFUNCTION()
	void Load();
	UPROPERTY(EditAnywhere)
	TArray<TSoftObjectPtr<UTexture2D>> SoftTextures;
private:
	int32 Index = 0;
};

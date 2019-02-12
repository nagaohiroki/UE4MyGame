#include "MyUserWidget.h"
#include "UMG.h"
UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(Text)
	{
		Text->SetText(FText::FromString(TEXT("aaa")));
	}
	if(Start)
	{
		PlayAnimation(Start, 0.0f, 10);
	}
	if(Button_0)
	{
		Button_0->OnClicked.AddDynamic(this, &UMyUserWidget::MyClick);
	}
}

void UMyUserWidget::MyClick()
{
	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("ButtonClick"));
	}
}

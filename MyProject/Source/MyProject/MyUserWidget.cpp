#include "MyUserWidget.h"
#include "UMG.h"
#include "MySaveGame.h"
#include "Kismet/GameplayStatics.h"
UMyUserWidget::UMyUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if(Text)
	{
		Text->SetText(FText::FromString(TEXT("TestUMG")));
	}
	if(SaveButton)
	{
		SaveButton->OnClicked.AddDynamic(this, &UMyUserWidget::Save);
	}
	if(LoadButton)
	{
		LoadButton->OnClicked.AddDynamic(this, &UMyUserWidget::Load);
	}
	PlayAnimation(Start, 0.0f, 10);
}

void UMyUserWidget::Save()
{
	if(!GEngine)
	{
		return;
	}
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance->Savedata.Index = 100;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot"), 0);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Save"));
}
void UMyUserWidget::Load()
{
	if(!GEngine)
	{
		return;
	}
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot"), 0));
	if(!LoadGameInstance)
	{
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Load") + FString::FromInt(LoadGameInstance->Savedata.Index));
}

void UMyUserWidget::ChangeImage()
{
	if(!Image_0)
	{
		return;
	}
	Index = 1 - Index;
	if(!SoftTextures.IsValidIndex(Index))
	{
		return;
	}
	Image_0->SetBrushFromSoftTexture(SoftTextures[Index]);
}

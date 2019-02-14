#include "MySaveEditor.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"
AMySaveEditor::AMySaveEditor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{}
void AMySaveEditor::Save()
{
	if(!GEngine)
	{
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Save"));
	UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	SaveGameInstance->Savedata = Savedata;
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Slot"), 0);
}
void AMySaveEditor::Load()
{
	if(!GEngine)
	{
		return;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("Load"));
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("Slot"), 0));
	if(!LoadGameInstance)
	{
		return;
	}
	Savedata = LoadGameInstance->Savedata;
}


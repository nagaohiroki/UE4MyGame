#include "MyUserWidgetTest.h"
#include "Engine.h"

void UMyUserWidgetTest::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) 
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Red, TEXT("a"));
	}
}

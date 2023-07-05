
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidescreenPanel.generated.h"

class UCustomGameUserSettings;

// * Abstract = Requires a subclass to be used
UCLASS(Blueprintable, Abstract)
class SHOWCASE_API UWidescreenPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = "GameUserSettings")
	UCustomGameUserSettings* GetCustomGameUserSettings();

private:
	UCustomGameUserSettings* CachedSettings;

protected:
	UPROPERTY(meta = (BindWidget))
	class UWideScreenSizeBox* WidescreenRatioSizeBox;

	UFUNCTION()
	void OnSettingsChanged();
	void UpdateWidescreenRatioSizeBox();
};

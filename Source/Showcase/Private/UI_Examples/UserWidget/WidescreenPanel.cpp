
#include "UI_Examples/UserWidget/WidescreenPanel.h"

#include "UI_Examples/Settings/CustomGameUserSettings.h"
#include "UI_Examples/UserWidget/WideScreenSizeBox.h"
#include "Components/SizeBox.h"

void UWidescreenPanel::NativeConstruct()
{
	Super::NativeConstruct();

	UCustomGameUserSettings* GameSettings = GetCustomGameUserSettings();
	if (GameSettings)
	{
		// * Bind panel UI to settings delegate
		GameSettings->OnSettingsChangedDelegate.AddUniqueDynamic(this, &UWidescreenPanel::OnSettingsChanged);
		GameSettings->OnSettingsAppliedDelegate.AddUniqueDynamic(this, &UWidescreenPanel::OnSettingsChanged);
	}
	UpdateWidescreenRatioSizeBox();
}

void UWidescreenPanel::OnSettingsChanged()
{
	UpdateWidescreenRatioSizeBox();
}
void UWidescreenPanel::UpdateWidescreenRatioSizeBox()
{
	UCustomGameUserSettings* GameSettings = GetCustomGameUserSettings();
	if (GameSettings)
	{
		if (GameSettings->GetUIWidescreenClampEnabled())
		{
			const FVector2D Vec = GameSettings->GetUIWidescreenClampRatioVector();
			WidescreenRatioSizeBox->SetMaxAspectRatio((int)Vec.X / Vec.Y);
		}
		else
		{
			WidescreenRatioSizeBox->ClearMaxAspectRatio();
		}
	}
}

UCustomGameUserSettings* UWidescreenPanel::GetCustomGameUserSettings()
{
	if (CachedSettings) 
	{ 
		return CachedSettings; 
	}

	CachedSettings = Cast<UCustomGameUserSettings>(UGameUserSettings::GetGameUserSettings());

	return CachedSettings ? CachedSettings : nullptr;
}

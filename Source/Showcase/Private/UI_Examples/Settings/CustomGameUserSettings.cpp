
#include "UI_Examples/Settings/CustomGameUserSettings.h"

UCustomGameUserSettings::UCustomGameUserSettings()
{
	bUIWidescreenClampEnabled = false;
}

void UCustomGameUserSettings::ApplySettings(bool bCheckForCommandLineOverrides)
{
	Super::ApplySettings(bCheckForCommandLineOverrides);

	OnSettingsAppliedDelegate.Broadcast();
}

bool UCustomGameUserSettings::GetUIWidescreenClampEnabled() const
{
	return bUIWidescreenClampEnabled;
}
void UCustomGameUserSettings::SetUIWidescreenClampEnabled(const bool bEnabled)
{
	bUIWidescreenClampEnabled = bEnabled;
}

FVector2D UCustomGameUserSettings::GetUIWidescreenClampRatioVector() const
{
	return UIWidescreenClampRatioVector;
}
void UCustomGameUserSettings::SetUIWidescreenClampRatioVector(const FVector2D NewVector)
{
	UIWidescreenClampRatioVector = NewVector;
}

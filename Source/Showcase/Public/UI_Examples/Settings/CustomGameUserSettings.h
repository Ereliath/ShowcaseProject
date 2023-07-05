

#pragma once

#include "CoreMinimal.h"
#include "Math/IntVector.h"
#include "GameFramework/GameUserSettings.h"
#include "CustomGameUserSettings.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsChangedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSettingsAppliedDelegate);

/**
 * Same as regular Game User Settings but with more versatile control
 */
UCLASS(Blueprintable)
class SHOWCASE_API UCustomGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
	
public:
	UCustomGameUserSettings();

	virtual void ApplySettings(bool bCheckForCommandLineOverrides) override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegate") 
	FOnSettingsChangedDelegate OnSettingsChangedDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Delegate")
	FOnSettingsAppliedDelegate OnSettingsAppliedDelegate;

	/**
	* Add custom Aspect Ratio functions for fullscreen usage (Ultrawide settings)
	* UI should be constrained to middle of screen and aspect ratio chosen by the player.
	* 1. Widescreen-friendly Camera = Enabled/Disabled
	* 2. Constrain UI on Ultrawide  = Enabled/Disabled
	* 3. Ultrawide Constrain Ratio  = 16:9 (Available: 4:3 - 16:9 - 16:10 - 21:9 - 32:9)
	*/
	
	UFUNCTION(BlueprintCallable, Category = "Settings", meta = (DisplayName = "Get UI Widescreen Clamp Enabled"))
	bool GetUIWidescreenClampEnabled() const;

	UFUNCTION(BlueprintCallable, Category = "Settings", meta = (DisplayName = "Set UI Widescreen Clamp"))
	void SetUIWidescreenClampEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, Category = "Settings", meta = (DisplayName = "Get UI Widescreen Clamp Ratio Vector"))
	FVector2D GetUIWidescreenClampRatioVector() const;

	UFUNCTION(BlueprintCallable, Category = "Settings", meta = (DisplayName = "Set UI Widescreen Clamp Ratio Vector"))
	void SetUIWidescreenClampRatioVector(const FVector2D NewVector);

protected:
	// * Controls if Widescreen UI is clamped or not
	UPROPERTY(config)
	bool bUIWidescreenClampEnabled;

	// * Aspect Ratio
	UPROPERTY(config)
	FVector2D UIWidescreenClampRatioVector;
};

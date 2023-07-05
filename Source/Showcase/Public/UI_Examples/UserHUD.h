

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UserHUD.generated.h"

UENUM(BlueprintType)
enum class EHUDState : uint8
{
	HUD_Ingame,              // * For Status bars, Targeting Widgets w/m
	HUD_Menu,                // * For Ingame Menu, shows the option of Inventory/CharacterStatus/Settings(Volume,resolution etc)/ExitGame
	HUD_Inventory,           // * For Inventory Items, tooltip windows, comparison windows w/m
	HUD_CharacterStatus,     // * For Character Window(Shows EquipmentSlots & How character currently looks) & Current Stats of the Character
	HUD_Settings,            // * For Audio / Video / Keybind / etc.
	HUD_Death                // * For when player dies
};

UCLASS()
class SHOWCASE_API AUserHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUserHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// * Called when HUD is created to apply additional functionalities based on window type
	void OnHUDCreateEvents(EHUDState CurrentHUD);

	void IngameBeginEvents();
	void MenuBeginEvents();
	void InventoryBeginEvents();
	void CharacterStatusBeginEvents();
	void SettingsBeginEvents();
	void DeathBeginEvents();

	bool ChangeHUD(class UUserWidget* WidgetToShow, bool ShowMouseCursor, bool EnableClickEvents);

	void ApplyHUDChanges();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "HUD|Getter")
	FORCEINLINE UUserWidget* GetCurrentWidget() { return CurrentWidget; }

	UFUNCTION(BlueprintCallable, Category = "HUD|Getter")
	FORCEINLINE EHUDState GetHUDState() { return HUDState; }
	// Setter for HUD State
	UFUNCTION(BlueprintCallable, Category = "HUD|Setter")
	void SetHUDState(EHUDState NewState);

protected:

	//~UObject interface
	virtual void PreInitializeComponents() override;
	//~End of UObject interface

	//~AActor interface
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	//~End of AActor interface

	//~AHUD interface
	virtual void GetDebugActorList(TArray<AActor*>& InOutList) override;
	//~End of AHUD interface

private:
	UPROPERTY() EHUDState HUDState;

	// * Current Widget displayed on the screen
	UPROPERTY() class UUserWidget* CurrentWidget;

	// * We're pretending this is a MainWidget with a bunch of sub-widget classes for showcasing purposes.
	UPROPERTY() class UUserWidget* MainWidget;
};

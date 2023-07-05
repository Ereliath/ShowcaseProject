
#include "UI_Examples/UserHUD.h"

#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"

AUserHUD::AUserHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bStartWithTickEnabled = false;
}

void AUserHUD::PreInitializeComponents()
{
	Super::PreInitializeComponents();
}

void AUserHUD::BeginPlay()
{
	Super::BeginPlay();
}
void AUserHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AUserHUD::GetDebugActorList(TArray<AActor*>& InOutList)
{
	Super::GetDebugActorList(InOutList);
}


void AUserHUD::SetHUDState(EHUDState NewState)
{
	HUDState = NewState;
	ApplyHUDChanges();
}

void AUserHUD::ApplyHUDChanges()
{
	if (CurrentWidget)
	{
		// * Hide the previous HUD to apply new one 
		CurrentWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	switch (HUDState)
	{
	case EHUDState::HUD_Ingame: {
		ChangeHUD(MainWidget/*->IngameLayout*/, false, false);
		break; 
	}
	case EHUDState::HUD_Menu: {
		ChangeHUD(MainWidget/*->MenuLayout*/, true, false);
		break; 
	}
	case EHUDState::HUD_Inventory: {
		ChangeHUD(MainWidget/*->InventoryLayout*/, true, false);
		break; 
	}
	case EHUDState::HUD_CharacterStatus: {
		ChangeHUD(MainWidget/*->CharacterStatusLayout*/, true, false);
		break; 
	}
	case EHUDState::HUD_Settings: {
		ChangeHUD(MainWidget/*->SettingsLayout*/, true, false);
		break; 
	}
	default: break;
	}
}

bool AUserHUD::ChangeHUD(class UUserWidget* WidgetToShow, bool ShowMouseCursor, bool EnableClickEvents)
{
	// * @TODO- Use interfaces to simply repeating logic throughout HUD changing
	if (WidgetToShow)
	{
		// * Set mouse visibility and click events according to params
		GetOwningPlayerController()->bShowMouseCursor = ShowMouseCursor;
		GetOwningPlayerController()->bEnableClickEvents = EnableClickEvents;

		WidgetToShow->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

		CurrentWidget = WidgetToShow;

		// * Fire additional events
		OnHUDCreateEvents(HUDState); 

		return true;
	}
	return false;
}

void AUserHUD::OnHUDCreateEvents(EHUDState CurrentHUD)
{
	switch (CurrentHUD)
	{
	case EHUDState::HUD_Ingame: IngameBeginEvents(); break;
	case EHUDState::HUD_Menu: MenuBeginEvents(); break;
	case EHUDState::HUD_Inventory: InventoryBeginEvents(); break;
	case EHUDState::HUD_CharacterStatus: CharacterStatusBeginEvents(); break;
	case EHUDState::HUD_Settings: SettingsBeginEvents(); break;
	case EHUDState::HUD_Death: DeathBeginEvents(); break;
	default: break;
	}
}

void AUserHUD::IngameBeginEvents()
{
	/**
	 * Enable combat (Getting hit and such), 
	 * Reapply default time dilation,
	 * Unpause gameplay timers, (Paused when enter menu for optimization purposes)
	 * Zoom camera back to default third person/first person view
	 */
}
void AUserHUD::MenuBeginEvents()
{
}
void AUserHUD::InventoryBeginEvents()
{
}
void AUserHUD::CharacterStatusBeginEvents()
{
}
void AUserHUD::SettingsBeginEvents()
{
}
void AUserHUD::DeathBeginEvents()
{
}

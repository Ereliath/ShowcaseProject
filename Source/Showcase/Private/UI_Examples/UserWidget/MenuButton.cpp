
#include "UI_Examples/UserWidget/MenuButton.h"

#include "UI_Examples/UserHUD.h"

UMenuButton::UMenuButton(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UMenuButton::NativeConstruct()
{
	Super::NativeConstruct();

	HUDReference = Cast<AUserHUD>(GetOwningPlayer()->GetHUD());
	if (!HUDReference) return;

	MenuButton->OnClicked.AddDynamic(this, &UMenuButton::OnMenuButtonClicked);
}

void UMenuButton::OnMenuButtonClicked()
{
	// @TODO - Add this functionality to HUDInterface
	switch (ButtonType)
	{
	case EButtonType::Ingame: {
		HUDReference->SetHUDState(EHUDState::HUD_Ingame); 
		break; 
	}
	case EButtonType::Menu: {
		HUDReference->SetHUDState(EHUDState::HUD_Menu);
		break; 
	}
	case EButtonType::Inventory: {
		HUDReference->SetHUDState(EHUDState::HUD_Inventory);
		break; 
	}
	case EButtonType::CharacterStatus: {
		HUDReference->SetHUDState(EHUDState::HUD_CharacterStatus);
		break; 
	}
	case EButtonType::Settings: {
		HUDReference->SetHUDState(EHUDState::HUD_Settings);
		break; 
	}
	case EButtonType::ExitGame: {
		GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit"); 
		break; 
	}
	default: break;
	}
}


#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h" 
#include "Blueprint/UserWidget.h"
#include "MenuButton.generated.h"

UENUM()
enum class EButtonType : uint8
{
	Ingame,
	Menu,
	Inventory,
	CharacterStatus,
	Settings,
	ExitGame
};

/**
 * Example of an Menu Button that is suppose to take you to different screens
 */
UCLASS()
class SHOWCASE_API UMenuButton : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UMenuButton(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	// * HUD Reference
	UPROPERTY(BlueprintReadOnly, Category = "Variables")
	class AUserHUD* HUDReference;

	// * Text to be used on Menu Button
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	FText Name;

	// * Value set from blueprint, represent the new screen to navigate to
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Variables")
	EButtonType ButtonType;

	// * This is the button component added in Blueprint UMG window
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Variables")
	UButton* MenuButton = nullptr;

	UFUNCTION() void OnMenuButtonClicked();

};

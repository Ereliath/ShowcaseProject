
#include "DefaultGameMode.h"
#include "UI_Examples/UserHUD.h"

ADefaultGameMode::ADefaultGameMode()
{
	HUDClass = AUserHUD::StaticClass();
}

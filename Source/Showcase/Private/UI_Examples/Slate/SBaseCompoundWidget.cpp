
#include "UI_Examples/Slate/SBaseCompoundWidget.h"
#include "Engine/UserInterfaceSettings.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SBaseCompoundWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;

	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
		[SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
		];
}

float SBaseCompoundWidget::PointSizeToSlateUnits(float PointSize)
{
	constexpr float SlateFreeTypeHorizontalResolutionDPI = 96.0f;
	constexpr float FreeTypeNativeDPI = 72.0f;
	const float PixelSize = PointSize * (SlateFreeTypeHorizontalResolutionDPI / FreeTypeNativeDPI);
	return PixelSize;
}
float SBaseCompoundWidget::GetDPIScale() const
{
	const FVector2D& DrawSize = GetTickSpaceGeometry().ToPaintGeometry().GetLocalSize();
	const FIntPoint Size((int32)DrawSize.X, (int32)DrawSize.Y);

	return GetDefault<UUserInterfaceSettings>()->GetDPIScaleBasedOnSize(Size);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

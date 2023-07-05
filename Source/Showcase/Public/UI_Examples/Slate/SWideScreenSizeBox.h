
#pragma once

#include "CoreMinimal.h"
#include "Widgets/Layout/SBox.h"

/**
 * Custom SizeBox class to handle better widescreen support
 */
class SHOWCASE_API SWideScreenSizeBox : public SBox
{
	SLATE_BEGIN_ARGS(SWideScreenSizeBox) 
	{
		_Visibility = EVisibility::SelfHitTestInvisible;
	}

	SLATE_END_ARGS()

	SWideScreenSizeBox();

public:
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	// Begin SWidget interface
	void OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const override;
	// End SWidget interface
};

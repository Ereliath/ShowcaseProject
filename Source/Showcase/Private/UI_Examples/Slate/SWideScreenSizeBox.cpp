
#include "UI_Examples/Slate/SWideScreenSizeBox.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SWideScreenSizeBox::Construct(const FArguments& InArgs)
{
	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
		[SNew(SBox)
		// * Align content in our custom SizeBox to center instead of top left.
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Fill)
		];
}

SWideScreenSizeBox::SWideScreenSizeBox()
{
	SetCanTick(false);
	bCanSupportFocus = false;
}

void SWideScreenSizeBox::OnArrangeChildren(const FGeometry& AllottedGeometry, FArrangedChildren& ArrangedChildren) const
{
	/*
	// ...  

	if (NewHeight > MaxHeight)
	{
		float Scale = MaxHeight / NewHeight;
		NewWidth *= Scale;
		NewHeight *= Scale;
	}

	XAlignmentResult.Size = NewWidth;
	YAlignmentResult.Size = NewHeight;

	// CHANGE: Force contents to be center-aligned, not left-aligned
	XAlignmentResult.Offset = (MaxWidth - NewWidth) / 2.0f;
	YAlignmentResult.Offset = (MaxHeight - NewHeight) / 2.0f;
	// CHANGE

	bAlignChildren = false;

	// ...
	*/
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

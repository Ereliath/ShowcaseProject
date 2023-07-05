
#include "UI_Examples/UserWidget/WideScreenSizeBox.h"

#include "UI_Examples/Slate/SWideScreenSizeBox.h"
#include "Components/SizeBoxSlot.h"

UWideScreenSizeBox::UWideScreenSizeBox(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

TSharedRef<SWidget> UWideScreenSizeBox::RebuildWidget()
{
	// * Override with our custom Widescreen SizeBox slate class
	MySizeBox = SNew(SWideScreenSizeBox);

	if (GetChildrenCount() > 0)
	{
		Cast<USizeBoxSlot>(GetContentSlot())->BuildSlot(MySizeBox.ToSharedRef());
	}

	return MySizeBox.ToSharedRef();
}

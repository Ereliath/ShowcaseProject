
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SHOWCASE_API SBaseCompoundWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SBaseCompoundWidget)
	{
	}
	SLATE_END_ARGS()

	// * Constructs this widget with InArgs
	void Construct(const FArguments& InArgs);
};

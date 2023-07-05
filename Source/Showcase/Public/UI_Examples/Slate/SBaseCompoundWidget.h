
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class SHOWCASE_API SBaseCompoundWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SBaseCompoundWidget){}

	SLATE_ARGUMENT(TWeakObjectPtr<class AHUD>, OwnerHUD)

	SLATE_END_ARGS()

public:
	void Construct(const FArguments& InArgs);

public:
	static float PointSizeToSlateUnits(float PointSize);
protected:
	float GetDPIScale() const;

private:
	TWeakObjectPtr<class AHUD> OwnerHUD;
};

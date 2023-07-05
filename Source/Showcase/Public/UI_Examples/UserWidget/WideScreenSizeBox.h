

#pragma once

#include "CoreMinimal.h"
#include "Components/SizeBox.h"
#include "WideScreenSizeBox.generated.h"

/**
 * Custom USizeBox that inherits from custom SBox rather than the default one.
 */
UCLASS()
class SHOWCASE_API UWideScreenSizeBox : public USizeBox
{
	GENERATED_BODY()
	
public:
	UWideScreenSizeBox(const FObjectInitializer& ObjectInitializer);

protected:
	//~UWidget interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
	//~End of UWidget interface
};

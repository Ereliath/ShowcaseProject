
#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "CourseTimerWidget.generated.h"

// * Useful to show passed time to user interface, also handles translation
UCLASS()
class SHOWCASE_API UCourseTimerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UCourseTimerWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	//* Text block with the Time Passed value
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Component") 
	UTextBlock* TimeText = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Variables") 
	FText TranslatedTimeText;
	UPROPERTY(BlueprintReadOnly, Category = "Variables") 
	float CourseTimePassed;
	UPROPERTY(BlueprintReadOnly, Category = "Variables") 
	FTimerHandle TimePassedTH;

	// * Initializes the Widget, calls UI animation & starts the Time Counter
	UFUNCTION() 
	void StartStatisticsTimer();

	// * Keeps track of how long time has passed in the game & Updates UI element
	UFUNCTION() 
	void TimeCounter();

	// * Used to pause the Time Counter
	UFUNCTION(BlueprintCallable, Category = "Functions") 
	void TogglePause(const bool bPause);

	// * Calculates the time passed and returns the Text that should be used for UI representation
	UFUNCTION() 
	FText GetTimePassed();

	UFUNCTION() FText FormatInt(int64 Value);
	UFUNCTION() FText FormatFloat(float Value);

	// * Called when level is completed, stops timers among other things
	UFUNCTION(BlueprintCallable, Category = "Functions") 
	void OnLevelComplete();

	// * Called to start UI animations that are setup in blueprint from C++. (Index 0 = Forward, Index 1 = Reverse)
	UFUNCTION(BlueprintImplementableEvent, Category = "Events")
	void StartBPAnimation(int32 AnimationIndex);
};

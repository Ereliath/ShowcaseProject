
#include "UI_Examples/UserWidget/CourseTimerWidget.h"

#include "Internationalization/TextFormatter.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Public/TimerManager.h"

UCourseTimerWidget::UCourseTimerWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CourseTimePassed = 0.0f;
	TranslatedTimeText = FText(NSLOCTEXT("STTranslations", "Generic_Time", "Time:"));
}

void UCourseTimerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// @TODO- Bind to GameStart delegate from ManagerClass/PlayerController or GameInstance
	StartStatisticsTimer();

	// * If construct don't work, update TimeText
	if (TranslatedTimeText.IsEmpty()) { TranslatedTimeText = FText(NSLOCTEXT("STTranslations", "Generic_Time", "Time:")); }
}

void UCourseTimerWidget::StartStatisticsTimer()
{
	// * Start UI In Animation
	StartBPAnimation(1);

	// * Starts the Time Counter
	GetWorld()->GetTimerManager().SetTimer(TimePassedTH, this, &UCourseTimerWidget::TimeCounter, 0.01f, true);
}
void UCourseTimerWidget::TimeCounter()
{
	// * Increment Time Passed
	CourseTimePassed += 0.01f;

	// * Update UI with Time Passed
	TimeText->SetText(GetTimePassed());
}
void UCourseTimerWidget::TogglePause(const bool bPause)
{
	if (TimePassedTH.IsValid())
	{
		if (bPause)
		{
			GetWorld()->GetTimerManager().PauseTimer(TimePassedTH);
		}
		else
		{
			GetWorld()->GetTimerManager().UnPauseTimer(TimePassedTH);
		}
	}
}

FText UCourseTimerWidget::GetTimePassed()
{
	const int32 Hours = ((FMath::FloorToInt(CourseTimePassed) / 60) / 60);     // Hours as Int
	const int32 Minutes = ((FMath::FloorToInt(CourseTimePassed) / 60) % 60);  // Minutes as Int
	const int32 Seconds = (FMath::FloorToInt(CourseTimePassed) % 60);        // Seconds as Int
	const float MilliSeconds = FMath::Fractional(CourseTimePassed);         // Milliseconds as float

	// * Should show hours?
	if (Hours > 0)
	{
		const FString StringHours = FormatInt(Hours).ToString();
		const FString StringMinutes = FormatInt(Minutes).ToString();
		const FString StringSeconds = FormatInt(Seconds).ToString();

		// * Time: [Hour] : [Minute] : [Second]
		return FText::FromString(FString::Printf(TEXT("%s %s : %s : %s"), *TranslatedTimeText.ToString(), *StringHours, *StringMinutes, *StringSeconds));
	}
	else
	{
		const FString StringMinutes = FormatInt(Minutes).ToString();
		const FString StringSeconds = FormatInt(Seconds).ToString();
		const FString StringMillis = FormatFloat(MilliSeconds).ToString();

		// Time: [Minute] : [Second].[MilliSeconds]
		return FText::FromString(FString::Printf(TEXT("%s %s : %s%s"), *TranslatedTimeText.ToString(), *StringMinutes, *StringSeconds, *StringMillis));
	}
}
FText UCourseTimerWidget::FormatInt(int64 Value)
{
	FNumberFormattingOptions NumberFormatOptions;
	NumberFormatOptions.AlwaysSign = false;
	NumberFormatOptions.UseGrouping = true;
	NumberFormatOptions.MinimumIntegralDigits = 2;
	NumberFormatOptions.MaximumIntegralDigits = 2;

	return FText::AsNumber(Value, &NumberFormatOptions);
}
FText UCourseTimerWidget::FormatFloat(float Value)
{
	FNumberFormattingOptions NumberFormatOptions;
	NumberFormatOptions.AlwaysSign = false;
	NumberFormatOptions.UseGrouping = true;
	NumberFormatOptions.RoundingMode = ERoundingMode::HalfToEven;
	NumberFormatOptions.MinimumIntegralDigits = 0;
	NumberFormatOptions.MaximumIntegralDigits = 0;
	NumberFormatOptions.MinimumFractionalDigits = 1;
	NumberFormatOptions.MaximumFractionalDigits = 1;

	return FText::AsNumber(Value, &NumberFormatOptions);
}

void UCourseTimerWidget::OnLevelComplete()
{
	// * Clear and invalidate timer
	GetWorld()->GetTimerManager().ClearTimer(TimePassedTH);

	// * Start UI Out Animation
	StartBPAnimation(0);

	// * Final achieved time. Save/update scoreboard/ pass to other UIs
	//CourseTimePassed;
}

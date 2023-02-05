// Fill out your copyright notice in the Description page of Project Settings.


#include "Slates/SMainMenuWidget.h"
#include "SlateOptMacros.h"

#define LOCTEXT_NAMESPACE "MainMenu"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenuWidget::Construct(const FArguments& InArgs)
{

	const FMargin ContentPadding = FMargin(500.f, 300.f);

	const FText TitleText = LOCTEXT("GameTitle", "Mario");


	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FLinearColor(0.1f, 0.1f, 0.1f, 0.7f))
		]
		+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Home"))
					]
				+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("News"))
					]
				+ SVerticalBox::Slot()
					[
						SNew(STextBlock)
						.Text(FText::FromString("Contact"))
					]
				+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(FText::FromString("About"))
						.ButtonColorAndOpacity(this, &SMainMenuWidget::GetTextColor)
						.OnHovered(this, &SMainMenuWidget::OnTextHovered)
						.OnUnhovered(this, &SMainMenuWidget::OnTextUnhovered)
					]
				
			]
		];

}

void SMainMenuWidget::OnTextHovered()
{
	bTextBlockHovered = true;
}

void SMainMenuWidget::OnTextUnhovered()
{
	bTextBlockHovered = false;
}

FSlateColor SMainMenuWidget::GetTextColor() const
{
	if (bTextBlockHovered)
	{
		return FLinearColor(0.0f, 0.0f, 0.0f);
	}
	
	return FLinearColor(1.0f, 1.0f, 1.0f);
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "SlateExtras.h"


/**
 *
 */
class SMALLMEDIUMBIZSIM_API SMainMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuWidget)
	{}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, OwningHUD)

	SLATE_END_ARGS()

	bool bTextBlockHovered;

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMainMenuHUD> OwningHUD;

	void OnTextHovered();

	void OnTextUnhovered();

	FSlateColor GetTextColor() const;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};

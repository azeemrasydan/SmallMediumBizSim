// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/MainMenuPlayerController.h"
#include "Hud/MainMenuHUD.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"

AMainMenuPlayerController::AMainMenuPlayerController()
{

}

void AMainMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* Eic = Cast<UEnhancedInputComponent>(InputComponent);

	check(Eic);

	ControllerMappingContext = NewObject<UInputMappingContext>(this);

	OpenMenuAction = NewObject<UInputAction>(this);
	OpenMenuAction->ValueType = EInputActionValueType::Boolean;
	ControllerMappingContext->MapKey(OpenMenuAction, EKeys::W);

	Eic->BindAction(OpenMenuAction, ETriggerEvent::Triggered, this, &AMainMenuPlayerController::OpenMenu);

}

void AMainMenuPlayerController::OpenMenu()
{
	if (AMainMenuHUD* MainMenuHUD = Cast<AMainMenuHUD>(GetHUD()))
	{
		MainMenuHUD->ShowMenu();
	}
}
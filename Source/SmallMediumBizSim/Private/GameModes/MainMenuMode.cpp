// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModes/MainMenuMode.h"
#include "Controllers/MainMenuPlayerController.h"
#include "Hud/MainMenuHUD.h"

AMainMenuMode::AMainMenuMode()
{
	PlayerControllerClass = AMainMenuPlayerController::StaticClass();
	HUDClass = AMainMenuHUD::StaticClass();
}
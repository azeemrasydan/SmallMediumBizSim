// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SMALLMEDIUMBIZSIM_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	AMainMenuPlayerController();

	virtual void SetupInputComponent() override;

	UPROPERTY()
	class UInputMappingContext* ControllerMappingContext;

	UPROPERTY()
	class UInputAction* OpenMenuAction;

	void OpenMenu();
	
};

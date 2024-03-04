// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

ATank::ATank()
{
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	playerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");

	springArm->SetupAttachment(RootComponent);
	playerCamera->SetupAttachment(springArm);
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:

	ATank();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:

	APlayerController* playerControllerRef;

	FVector cursorPosition;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float movementSpeed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float turnSpeed;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float turretSpeed;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* springArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* playerCamera;

private:

	void Move(float inputValue);

	void Turn(float inputValue);

	FVector GetAndShowMouseLocation();
	
};

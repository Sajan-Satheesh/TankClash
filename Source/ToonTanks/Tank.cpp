// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

ATank::ATank()
{
	springArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	springArm->SetupAttachment(RootComponent);

	playerCamera = CreateDefaultSubobject<UCameraComponent>("PlayerCamera");
	playerCamera->SetupAttachment(springArm);

}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move"), this, &ATank::Move);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();

	cursorPosition = FVector::ZeroVector;

	playerControllerRef = Cast<APlayerController>(GetController());
}

void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	rotateTurret( GetAndShowMouseLocation(), turretSpeed);

	FRotator springTargetRotation = FRotator(springArm->GetComponentRotation().Pitch, TurretMesh->GetComponentRotation().Yaw, 0);
	float armSpeed = FVector::Dist(TurretMesh->GetComponentLocation(), cursorPosition)/1000.f;
	UE_LOG(LogTemp, Display, TEXT("arm Speed : %f"), armSpeed);

	springArm->SetWorldRotation(FMath::RInterpTo(
		springArm->GetComponentRotation(),
		springTargetRotation,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		armSpeed)
	);
}

void ATank::Move(float inputValue)
{
	AddActorLocalOffset(FVector::XAxisVector * inputValue * movementSpeed * UGameplayStatics::GetWorldDeltaSeconds(this),true);
}

void ATank::Turn(float inputValue)
{
	AddActorLocalRotation(FRotator(0, 1 *inputValue *turnSpeed * UGameplayStatics::GetWorldDeltaSeconds(this), 0), true);
}

FVector ATank::GetAndShowMouseLocation()
{
	bool hit = false;
	FHitResult outHitResult;
	if (playerControllerRef) {
		hit = playerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, outHitResult);
	}
	if (hit) {
		DrawDebugSphere(
			GetWorld(),
			outHitResult.ImpactPoint,
			20.f,
			6.f,
			FColor::Red);
		cursorPosition = outHitResult.ImpactPoint;
	}
	return cursorPosition;
}



// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	playerTank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	LookAtPlayerInRange();
}

FVector ATower::GetPlayerLocation()
{
	return playerTank->GetTargetLocation();
}

void ATower::LookAtPlayerInRange()
{
	if (FVector::Dist(GetActorLocation(), GetPlayerLocation()) < fireRange) {

		rotateTurret(GetPlayerLocation(), turretSpeed);
	}
}

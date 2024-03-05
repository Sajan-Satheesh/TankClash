// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));
	RootComponent = CollisionComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	BaseMesh->SetupAttachment(CollisionComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	BulletSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("BulletSpwanPoint"));
	BulletSpawnPoint->SetupAttachment(TurretMesh);
	
}

// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePawn::rotateTurret(FVector target, float rotationSpeed)
{
	FVector TargetLocation = target - TurretMesh->GetComponentLocation();
	FRotator TargetRotation = FRotator(0, TargetLocation.Rotation().Yaw, 0);
	TurretMesh->SetWorldRotation(FMath::RInterpTo(
		TurretMesh->GetComponentRotation(),
		TargetRotation,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		rotationSpeed)
	);

}



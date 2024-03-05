// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"


UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pointers", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pointers", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pointers", meta = (AllowPrivateAccess = "true"))
	USceneComponent* BulletSpawnPoint;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pointers", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;


protected:

	void rotateTurret(FVector, float);
};

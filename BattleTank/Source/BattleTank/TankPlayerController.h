// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair(); // possitions barrel and turret to hit location at crosshair

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = .5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;
	
public:
	void BeginPlay() override;

	void Tick(float DeltatTime) override;



};

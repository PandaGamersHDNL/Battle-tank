// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if(!Barrel){return;}
	
	auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	

	FVector OutLaunchVelocity;
	
	if
	(
		UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace
		)
	)
	{
 		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto ThisTank = GetOwner()->GetName();
 		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at: %s"),*ThisTank, *AimDirection.ToString());	

	};
 	

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();

	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString())

	auto DeltaRotator = AimAsRotator - BarrelRotation;

	Barrel->Elevate(5.0f)
}
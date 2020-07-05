// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("The tank %s is controlled by the PlayerController"), *(GetControlledTank()->GetName()));
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
};

void ATankPlayerController::AimTowardsCrosshair()
{
    if(!GetControlledTank()) {return;}

    FVector HitLocation; //out parameter
    if (GetSightRayHitLocation(HitLocation))
    {
        UE_LOG(LogTemp, Warning, TEXT("Location: %s"), *HitLocation.ToString());
    }


}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
    //Find crosshair position    
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

    //deproject the screen pos of crosshqir to a world dir
    FVector CameraWorldLocation, WorldDirection;
    if(DeprojectScreenPositionToWorld(ScreenLocation.X,ScreenLocation.Y, CameraWorldLocation, WorldDirection))
    {
        FHitResult OutHit;
        if(GetWorld()->LineTraceSingleByChannel
                        (
                            OutHit,
                            CameraWorldLocation,
                            CameraWorldLocation + WorldDirection * LineTraceRange,
                            ECollisionChannel::ECC_Visibility
                        )
          )
        {
            OutHitLocation = OutHit.Location;
            return true;
        }
    }
    return false; 
}

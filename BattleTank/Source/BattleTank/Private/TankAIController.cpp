// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();
    
}

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if(GetControlledTank())
    {

    GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (PlayerPawn)
    {
        return Cast<ATank>(PlayerPawn);
    }
    else
    {
        return nullptr;
    }
    
}
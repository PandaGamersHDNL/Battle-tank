// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    auto ControlledTank = GetControlledTank();
    auto PlayerTank = GetPlayerTank();

    UE_LOG(LogTemp, Warning, TEXT("AI controlls: %s and sees %s as player tank"), *(ControlledTank->GetName()), *(PlayerTank->GetName()));
     
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
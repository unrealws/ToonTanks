// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsTankInFireRange())
	{
		RotateTurret(Tank->GetActorLocation());
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(FireRateTimerHanle, this, &ATower::CheckFireCondition, FireRate, true);
}

void ATower::CheckFireCondition()
{
	if (IsTankInFireRange())
	{
		Fire();
	}
}

bool ATower::IsTankInFireRange()
{
	if (Tank && !Tank->IsHidden())
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		return (Distance <= FireRange);
	}
	return false;
}

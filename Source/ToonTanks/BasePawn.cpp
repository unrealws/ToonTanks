// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Projectile.h"
#include "DrawDebugHelpers.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(CapsuleComp);
	
	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TurretMesh Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);
	
	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);

}

void ABasePawn::HandleDestruction()
{
	//TODO: visual/sound effects
	if (ExplodeParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplodeParticle, this->GetActorLocation(), this->GetActorRotation());
	}

	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation(), 0.5f);
	}

	if(DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
}

void ABasePawn::RotateTurret(FVector LookAtTarget)
{
	if (TurretMesh)
	{
		FVector TurretLocation = TurretMesh->GetComponentLocation();

		//LookAtTarget.Z = TurretLocation.Z;

		FVector ToTarget = LookAtTarget - TurretLocation;
		FRotator LookAtRotation = ToTarget.Rotation();

		LookAtRotation.Pitch = LookAtRotation.Roll = 0.f;

		TurretMesh->SetWorldRotation(LookAtRotation);
	}
}

void ABasePawn::Fire()
{
	if (ProjectileSpawnPoint)
	{
		//DrawDebugSphere(GetWorld(), ProjectileSpawnPoint->GetComponentLocation(), 15.f, 12, FColor::Orange, false, 2.f);
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
		Projectile->SetOwner(this);
	}
}






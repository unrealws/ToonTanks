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

	void HandleDestruction();

	//UPROPERTY(VisibleAnyWhere, Category="MyComponents")
	//int32 VisibleAnywhereInt = 66;
	//UPROPERTY(VisibleInstanceOnly)
	//int32 VisibleInstanceOnlyInt = 88;
	//UPROPERTY(EditAnyWhere)
	//int32 EditAnywhereInt = 77;

	//UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	//FString MyName = TEXT("Bye UE4");
	//UPROPERTY(EditInstanceOnly)
	//FVector DefaultSpeed = FVector(1.2f, 99.0f, 38.0f);

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();


private:
	UPROPERTY(VisibleAnywhere, Category="MyComponents", meta=(AllowPrivateAccess = "true"), BlueprintReadOnly)
	class UCapsuleComponent *CapsuleComp;
	UPROPERTY(VisibleAnywhere, Category="MyComponents", meta=(AllowPrivateAccess = "true"), BlueprintReadWrite)
	UStaticMeshComponent *BaseMesh;
	UPROPERTY(VisibleAnywhere, Category="MyComponents", meta=(AllowPrivateAccess = "true"), BlueprintReadWrite)
	UStaticMeshComponent *TurretMesh;
	UPROPERTY(VisibleAnywhere, Category="MyComponents", meta=(AllowPrivateAccess = "true"), BlueprintReadWrite)
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* ExplodeParticle;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;

};

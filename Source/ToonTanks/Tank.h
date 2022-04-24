// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	APlayerController* GetTankPlayerController() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere, Category = "Tank Movement")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Tank Movement")
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, Category = "Tank Movement", meta = (AllowPrivateAccess ="true"), BlueprintReadWrite)
	float Speed = 100.f;
	void Move(float Value);

	UPROPERTY(EditAnywhere, Category = "Tank Movement")
	float TurnRate = 90.f;
	void Turn(float Value);

	APlayerController* PlayerController;

};

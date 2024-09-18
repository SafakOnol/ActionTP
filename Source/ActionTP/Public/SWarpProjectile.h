// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "SWarpProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONTP_API ASWarpProjectile : public ASProjectileBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float TeleportDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Teleport")
	float DetonateDelay;

	// Handle to cancel the timer if projectile already hit something
	FTimerHandle TimerHandle_DelayedDetonate;

	// Base class uses BlueprintNativeEvent, therefore it is required to use _Implementation
	virtual void Explode_Implementation() override;

	void TeleportInstigator();

	virtual void BeginPlay() override;

public:

	ASWarpProjectile();
	
};

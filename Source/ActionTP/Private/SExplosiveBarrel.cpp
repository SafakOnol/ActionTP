// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

#include "SCharacter.h"
#include "Field/FieldSystemObjects.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(RootComponent);
	
	// TODO: set Radial Vector explosion

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->SetupAttachment(StaticMeshComponent);
	RadialForceComponent->Radius = 1000.f;
	RadialForceComponent->ImpulseStrength = 500.f;
	RadialForceComponent->bImpulseVelChange = true;

}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


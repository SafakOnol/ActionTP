// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

#include "SCharacter.h"
#include "Field/FieldSystemObjects.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetSimulatePhysics(true);
	RootComponent = StaticMeshComponent;
	
	// TODO: set Radial Vector explosion

	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForceComponent->SetupAttachment(StaticMeshComponent);

	RadialForceComponent->SetAutoActivate(false); // When this is true, it applies a constant force via tick
	RadialForceComponent->Radius = 1000.f;
	RadialForceComponent->ImpulseStrength = 500.f; // We should drastically increase this if vImpulseVelChange is false
	RadialForceComponent->bImpulseVelChange = true;
	RadialForceComponent->AddCollisionChannelToAffect(ECC_WorldDynamic); // Optional, default constructor of component already adds 4 object types to affect, excluding world dynamic

}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();	
}

void ASExplosiveBarrel::PostInitializeComponents()
{
	// Parent function must be called!!!
	Super::PostInitializeComponents();

	// It's the best practice to call add dynamic here instead of on Begin Play, and it must not be called on Constructor!!!
	StaticMeshComponent->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
                                   UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComponent->FireImpulse();
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


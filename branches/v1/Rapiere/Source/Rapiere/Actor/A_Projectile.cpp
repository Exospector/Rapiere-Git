// Fill out your copyright notice in the Description page of Project Settings.

#include "Rapiere.h"
#include "A_Projectile.h"


// Sets default values
AA_Projectile::AA_Projectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Temp Object creation, to do in Editor
	SM_ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshTower(TEXT("StaticMesh'/Game/Geometries/Meshes/BeamTurret.BeamTurret'"));
	if (StaticMeshTower.Object) {
		SM_ProjectileMesh->SetStaticMesh(StaticMeshTower.Object);
	}
	
	// To remove, Test Without any sphere component, look if movement component OK
	//Setup Mesh of projectile from editor
	if(SM_ProjectileMesh!=NULL){
		RootComponent=SM_ProjectileMesh;
		
		// Use a ProjectileMovementComponent to govern this projectile's movement
		ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
		ProjectileMovement->UpdatedComponent = RootComponent;
		ProjectileMovement->InitialSpeed = 10000.f;
		ProjectileMovement->MaxSpeed = 10000.f;
		ProjectileMovement->bRotationFollowsVelocity = true;
		ProjectileMovement->bShouldBounce = true;
	}

	// Die after X seconds by default
	InitialLifeSpan = 10.f;
}

// Called when the game starts or when spawned
void AA_Projectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AA_Projectile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}


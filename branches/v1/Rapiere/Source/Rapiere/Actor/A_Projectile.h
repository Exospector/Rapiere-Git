// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "A_Projectile.generated.h"

UCLASS()
class RAPIERE_API AA_Projectile : public AActor
{
	GENERATED_BODY()
protected:
	/**Represent the Mesh of the projectile, has to be defined in blueprint*/
	UPROPERTY(Editanywhere, Category = "Projectile") 
	UStaticMeshComponent* SM_ProjectileMesh;
		
	/**Temporary PhysicComponent of the projectile, to define precisely later*/	
	UPROPERTY(Editanywhere, category = "projectile")
	USphereComponent* SC_sphere;
		
	/**Use to move the projectile*/	
	UPROPERTY(Visibleanywhere, category = "projectile")
	UProjectileMovementComponent* ProjectileMovement;
	
	/**The current damage of the projectile*/
	UPROPERTY(Editanywhere, Category = "Projectile")
	float damage;

	/**The type of the projectile (Laser, balistic etc...)*/
	UPROPERTY(VisibleAnywhere, Category = "Projectile")
	FString Type;
public:	
	// Sets default values for this actor's properties
	AA_Projectile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};

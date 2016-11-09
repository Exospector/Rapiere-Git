// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/PrimitiveComponent.h"
#include "../Source/Rapiere/Actor/A_Projectile.h"
#include "PC_PlayerWeapon.generated.h"
 
/**
 * 
 */
UCLASS()
class RAPIERE_API UPC_PlayerWeapon : public UPrimitiveComponent
{
	GENERATED_BODY()
protected:
	
	/**Represent the mesh of the Player Weapon*/
	UPROPERTY(EditAnywhere, Category = Weapon)
	UStaticMeshComponent* UM_WeaponMesh;
	
	/**Represent the Projectile fire by the weapon, determining the damage and effect of the weapon*/
	UPROPERTY(Editanywhere, Category = Weapon)
	AA_Projectile* Projectile;
	//to add propriété animation? etc
	

	UPROPERTY(Editanywhere, category = Weapon)
	FTimerDynamicDelegate DelegateTime;

public:
	UPROPERTY(Editanywhere, category = Weapon)
		FTimerHandle HandleTime;
	UFUNCTION()
	void DelayFire(bool isfiring, float delay);
	UFUNCTION()
	/**Launch fire animation and spawn a projectile*/
	void Fire();
	UPC_PlayerWeapon();
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	
	
};

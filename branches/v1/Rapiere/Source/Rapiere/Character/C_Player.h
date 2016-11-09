// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "../Source/Rapiere/PrimitiveComponent/PC_PlayerWeapon.h"
#include "C_Player.generated.h"

UCLASS()
class RAPIERE_API AC_Player : public ACharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category=Gameplay)
	UAnimMontage* FireAnimation;
	bool HasFire = false;

	// Sets default values for this character's properties
	AC_Player();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void StopJump();

	void StartJump();
protected:
	/**Represent the player's weapon and it's component*/
	UPROPERTY(EditAnywhere, Category = Weapon)
	UPC_PlayerWeapon* PC_Weapon;

	/**Set if the character is firing*/
	UPROPERTY(VisibleAnywhere, Category = AC_Player)
	bool BisFire = false;

	/**Main camera of the character*/
	UPROPERTY(EditAnywhere, Category = camera)
	UCameraComponent* FirstPersonCamera;


	/***/
	UPROPERTY(VisibleAnywhere, Category = camera)
	float BaseTurnRate;

	/***/
	UPROPERTY(VisibleAnywhere, Category = camera)
	float BaseLookupRate;


	/**Function called OnLeftClick Pressed to set BisFire to true*/
	void StartFire();

	/**Function called OnLeftClick Released to set BisFire to false*/
	void StopFire();

	/**Function called for zs axis*/
	void MoveForward(float value);

	/**Function called for qd axis*/
	void MoveLeftRight(float value);

	/***/
	void TurnAtRate(float Rate);
	/***/
	void LookUpAtRate(float Rate);
};

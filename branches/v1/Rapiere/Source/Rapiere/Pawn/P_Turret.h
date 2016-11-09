// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "P_Turret.generated.h"

UCLASS()
class RAPIERE_API AP_Turret : public APawn
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere,category="turret")
	AActor* charac;

public:
	// Sets default values for this pawn's properties
	AP_Turret();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};

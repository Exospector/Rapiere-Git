// Fill out your copyright notice in the Description page of Project Settings.

#include "Rapiere.h"
#include "P_Turret.h"


// Sets default values
AP_Turret::AP_Turret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP_Turret::BeginPlay()
{
	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
		charac = *ActorItr;

	}
	Super::BeginPlay();
	
}

// Called every frame
void AP_Turret::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AP_Turret::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


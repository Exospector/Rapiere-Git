// Fill out your copyright notice in the Description page of Project Settings.

#include "Rapiere.h"
#include "Timer.h"

UTimer::UTimer(){
	PrimaryComponentTick.bCanEverTick = false;

}
void UTimer::InitComponent(UWorld *& world, FTimerHandle & Handler)
{
	bWantsBeginPlay = true;
	World = world;
	SampleTimerHandle = Handler;
}
UTimer::~UTimer()
{
}


// Called when the game starts
void UTimer::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UTimer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

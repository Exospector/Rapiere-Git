// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Timer.generated.h"

/**
*
*/
UCLASS()
class RAPIERE_API UTimer : public UActorComponent
{
	GENERATED_BODY()
public:
	UTimer();
	void InitComponent(UWorld* & world, FTimerHandle & Handler);
	template<class T1>
	void SetTimer(float value,T1* Object, typename FTimerDelegate::TUObjectMethodDelegate< T1 >::FMethodPtr InTimerMethod, bool loop = true);
	~UTimer();
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPROPERTY(VisibleAnywhere, category = Timer)
		bool bTimerExpired;
protected:

	
	/**Object handling the timer*/
	UPROPERTY(VisibleAnywhere, category = Timer)
		FTimerHandle SampleTimerHandle;
	/**The world passed by the Actor (mainly by GetWorld() )*/
	UPROPERTY(VisibleAnywhere, category = Timer)
		UWorld* World;
	/**Check if the timer has expired (true if expire*/
	

};

template<class T1>
inline void UTimer::SetTimer(float value, T1 * Object, typename FTimerDelegate::TUObjectMethodDelegate<T1>::FMethodPtr InTimerMethod, bool loop)
{
	if (World)
	{
		// If the timer has expired or does not exist, start it    
		World->GetTimerManager().ClearTimer(SampleTimerHandle);
		World->GetTimerManager().SetTimer(SampleTimerHandle, Object, InTimerMethod, value);
		bTimerExpired = false;
	}
}

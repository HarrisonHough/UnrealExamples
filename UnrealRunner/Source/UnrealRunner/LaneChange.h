// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LaneChange.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALRUNNER_API ULaneChange : public UActorComponent
{
	GENERATED_BODY()

private:
	int Lane;
	int TargetLane;
	
	
public:	
	// Sets default values for this component's properties
	ULaneChange();

public:
	
	UFUNCTION(BlueprintCallable)
	void Change(const int Direction);
	
	UFUNCTION(BlueprintCallable)
	void MoveActor(AActor* TargetActor, const float Progress);
	
	UFUNCTION(BlueprintCallable)
	void Finished();
	
	UPROPERTY(BlueprintReadWrite, Category=LaneChange)
	TArray<float> LaneY;
		
};

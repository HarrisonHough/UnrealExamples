// Fill out your copyright notice in the Description page of Project Settings.

#include "LaneChange.h"

// Sets default values for this component's properties
ULaneChange::ULaneChange()
{
	PrimaryComponentTick.bCanEverTick = false;
	LaneYArray = {
		-325.0f,
		0.0f,
		323.0f
	};
}

void ULaneChange::Change(const int Direction)
{
	TargetLane = FMath::Clamp(Lane + Direction, 0, 2);
}

void ULaneChange::MoveActor(AActor* TargetActor, const float Progress)
{
	const FVector Location = TargetActor->GetRootComponent()->GetComponentLocation();
	const float StartPositionY = LaneYArray[Lane];
	const float TargetPositionY = LaneYArray[TargetLane];
	const float NewPositionY = FMath::Lerp(StartPositionY, TargetPositionY,Progress);
	TargetActor->SetActorLocation(FVector (Location.X,NewPositionY,Location.Z));
}

void ULaneChange::Finished()
{
	Lane = TargetLane;
}


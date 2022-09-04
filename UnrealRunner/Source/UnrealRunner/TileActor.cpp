// Fill out your copyright notice in the Description page of Project Settings.


#include "TileActor.h"

#include "Components/BoxComponent.h"

// Sets default values
ATileActor::ATileActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = SceneRoot;
	ExitCollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	ExitCollisionMesh->SetupAttachment(SceneRoot);
	ExitCollisionMesh->SetRelativeLocation(FVector(1000,0,500));
	ExitCollisionMesh->SetBoxExtent(FVector(32,500,1000));
	ExitCollisionMesh->SetCollisionResponseToAllChannels(ECR_Overlap);
	ExitCollisionMesh->SetGenerateOverlapEvents(true);
	SpawnPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(SceneRoot);
	SpawnPoint->SetRelativeLocation(FVector(1000,0,500));
	Lane0 = CreateDefaultSubobject<UArrowComponent>(TEXT("Lane 0"));
	Lane0->SetupAttachment(SceneRoot);
	Lane0->SetRelativeLocation(FVector(0,-325.0,0));
	Lane1 = CreateDefaultSubobject<UArrowComponent>(TEXT("Lane 1"));
	Lane1->SetupAttachment(SceneRoot);
	Lane1->SetRelativeLocation(FVector(0,0,0));
	Lane2 = CreateDefaultSubobject<UArrowComponent>(TEXT("Lane 2"));
	Lane2->SetupAttachment(SceneRoot);
	Lane2->SetRelativeLocation(FVector(0,323.0,0));
}

FTransform ATileActor::GetSpawnTransform() const
{
	return SpawnPoint->GetComponentTransform();
}

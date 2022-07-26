// Fill out your copyright notice in the Description page of Project Settings.


#include "TileSpawner.h"
#include "TileActor.h"

void ATileSpawner::SpawnRandomTile()
{
	if(TileArray.Num() < 1) return;
	SpawnTile(TileArray[FMath::RandRange(0, TileArray.Num())]);
}

ATileActor* ATileSpawner::GetLastTile() const
{
	return LastTileSpawned;
}

void ATileSpawner::SpawnTile(const ATileActor* TileActor)
{
	if(LastTileSpawned == nullptr)
	{
		const FVector Position = FVector(0,0,0);
		const FRotator Rotation = FRotator(0,0,0);
		LastTileSpawned = GetWorld()->SpawnActor<ATileActor>(TileActor->GetClass(), Position, Rotation);
		return;
	}
	LastTileSpawned = GetWorld()->SpawnActor<ATileActor>(TileActor->GetClass(), LastTileSpawned->GetActorTransform());
}

void ATileSpawner::SpawnTiles(const int NumberToSpawn)
{
	if(NumberToSpawn < 1) return;
	for(int i = 0; i < NumberToSpawn; i++)
	{
		SpawnRandomTile();
	}
}
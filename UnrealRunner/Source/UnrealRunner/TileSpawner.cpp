// Fill out your copyright notice in the Description page of Project Settings.


#include "TileSpawner.h"
#include "TileActor.h"

void ATileSpawner::SpawnRandomTile()
{
	if(TileBlueprintArray.Num() < 1) return;
	
	SpawnTile(TileBlueprintArray[FMath::RandRange(0, TileBlueprintArray.Num()-1)]);
}

ATileActor* ATileSpawner::GetLastTile() const
{
	return LastTileSpawned;
}

void ATileSpawner::OnTileExit(const ATileActor* TileActor)
{
	UE_LOG(LogTemp, Warning, TEXT("SPAWNING RANDOM TILE") );
	SpawnRandomTile();
}

void ATileSpawner::SpawnTile(const TSubclassOf <ATileActor> TileActor)
{
	if(LastTileSpawned == nullptr)
	{
		const FVector Position = FVector(0,0,0);
		const FRotator Rotation = FRotator(0,0,0);
		LastTileSpawned = GetWorld()->SpawnActor<ATileActor>(TileActor, Position, Rotation);
		LastTileSpawned->OnExitTile.AddDynamic(this, &ATileSpawner::OnTileExit);
		return;
	}
	LastTileSpawned = GetWorld()->SpawnActor<ATileActor>(TileActor, LastTileSpawned->GetSpawnTransform());
	LastTileSpawned->OnExitTile.AddDynamic(this, &ATileSpawner::OnTileExit);
}

void ATileSpawner::SpawnTiles(const int NumberToSpawn)
{
	if(NumberToSpawn < 1) return;
	for(int i = 0; i < NumberToSpawn; i++)
	{
		SpawnRandomTile();
	}
}
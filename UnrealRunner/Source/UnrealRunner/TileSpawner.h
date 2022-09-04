// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SpawnerBase.h"
#include "TileSpawner.generated.h"

/**
 * 
 */
UCLASS()
class UNREALRUNNER_API ATileSpawner final : public ASpawnerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Tile Spawner")
	void SpawnTiles(const int NumberToSpawn);
	UFUNCTION(BlueprintCallable, Category="Tile Spawner")
	void SpawnTile(const TSubclassOf<class ATileActor> TileActor);
	UFUNCTION(BlueprintCallable, Category="Tile Spawner")
	void SpawnRandomTile();
	UFUNCTION(BlueprintCallable, Category="Tile Spawner")
	ATileActor* GetLastTile() const;
	
	UPROPERTY(EditDefaultsOnly, Category="Tile Spawner")
	TArray<TSubclassOf<ATileActor>> TileBlueprintArray;

	UFUNCTION(BlueprintCallable)
	void OnTileExit(const ATileActor* TileActor);

private:
	ATileActor* LastTileSpawned;
	 
};

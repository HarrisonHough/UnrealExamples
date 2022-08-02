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
	UFUNCTION(BlueprintCallable, Category=TileSpawner)
	void SpawnTiles(const int NumberToSpawn);
	UFUNCTION(BlueprintCallable, Category=TileSpawner)
	void SpawnTile(const class ATileActor* TileActor);
	UFUNCTION(BlueprintCallable, Category=TileSpawner)
	void SpawnRandomTile();
	UFUNCTION(BlueprintCallable, Category=TileSpawner)
	ATileActor* GetLastTile() const;
	
	UPROPERTY(EditDefaultsOnly, Category=TileSpawner)
	TArray<ATileActor*> TileBlueprintArray;
private:
	ATileActor* LastTileSpawned;
};

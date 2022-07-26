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
	void SpawnTiles(const int NumberToSpawn);
	void SpawnTile(const class ATileActor* TileActor);
	void SpawnRandomTile();
	ATileActor* GetLastTile() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=TileSpawner)
	TArray<ATileActor*> TileArray;
private:
	ATileActor* LastTileSpawned;
};

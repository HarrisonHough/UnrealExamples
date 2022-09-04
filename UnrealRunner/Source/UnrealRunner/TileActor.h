// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/Actor.h"
#include "TileActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnExitTile, const class ATileActor*, TileActor);

UCLASS()
class UNREALRUNNER_API ATileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileActor();
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile,  meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* ExitCollisionMesh;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile,  meta = (AllowPrivateAccess = "true"))
	USceneComponent* SceneRoot;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* SpawnPoint;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Lane0;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Lane1;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly, Category = Tile, meta = (AllowPrivateAccess = "true"))
	UArrowComponent* Lane2;

	UFUNCTION(BlueprintCallable)
	FTransform GetSpawnTransform() const;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite)
	FOnExitTile OnExitTile;
	
};

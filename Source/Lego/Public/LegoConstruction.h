// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LegoConstruction.generated.h"

UCLASS()
class LEGO_API ALegoConstruction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALegoConstruction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartConstruction();
	void StopConstruction();
	void MovePiece(int Index, float DeltaTime);

private:
	UPROPERTY(EditAnywhere)
	TArray<AStaticMeshActor*> LegoPieces;  // Liste des pièces Lego

	UPROPERTY(EditAnywhere)
	TArray<FVector> StartPositions;  // Positions de départ

	UPROPERTY(EditAnywhere)
	TArray<FVector> EndPositions;  // Positions finales

	UPROPERTY(EditAnywhere)
	float MoveDuration = 1.0f;  // Temps de transition

	float ConstructionProgress;
	bool bIsConstructing;
};

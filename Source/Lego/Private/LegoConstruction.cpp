// Fill out your copyright notice in the Description page of Project Settings.


#include "LegoConstruction.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"


// Sets default values
ALegoConstruction::ALegoConstruction()
{
	PrimaryActorTick.bCanEverTick = true;
	bIsConstructing = false;
	ConstructionProgress = 0.0f;
}

// Called when the game starts or when spawned
void ALegoConstruction::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("Nombre de pièces LEGO dans l'array: %d"), LegoPieces.Num());

    for (int32 i = 0; i < LegoPieces.Num(); i++)
    {
        if (LegoPieces[i])
        {
            UE_LOG(LogTemp, Warning, TEXT("Pièce %d trouvée: %s"), i, *LegoPieces[i]->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Error, TEXT("Pièce %d est NULL !"), i);
        }
    }
}

// Called every frame
void ALegoConstruction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (bIsConstructing)
    {
        bool bAllPiecesArrived = true;

        for (int32 i = 0; i < LegoPieces.Num(); i++)
        {
            if (LegoPieces[i])
            {
                FVector CurrentPosition = LegoPieces[i]->GetActorLocation();
                FVector TargetPosition = EndPositions[i];

                // Déplacement progressif
                FVector NewPosition = FMath::VInterpTo(CurrentPosition, TargetPosition, DeltaTime, 2.0f);
                LegoPieces[i]->SetActorLocation(NewPosition);

                // Vérifie si la pièce a atteint sa destination
                if (!CurrentPosition.Equals(TargetPosition, 1.0f))
                {
                    bAllPiecesArrived = false;
                }
            }
        }

        // Arrête la construction quand toutes les pièces sont en place
        if (bAllPiecesArrived)
        {
            UE_LOG(LogTemp, Warning, TEXT("Construction terminée !"));
            bIsConstructing = false;
        }
    }
}

void ALegoConstruction::StartConstruction()
{
    if (!bIsConstructing)
    {
        bIsConstructing = true;
        UE_LOG(LogTemp, Warning, TEXT("Construction commencée !"));

        for (int32 i = 0; i < LegoPieces.Num(); i++)
        {
            if (LegoPieces[i])
            {
                UStaticMeshComponent* MeshComp = LegoPieces[i]->GetStaticMeshComponent();
                if (MeshComp)
                {
                    MeshComp->SetMobility(EComponentMobility::Movable);
                    UE_LOG(LogTemp, Warning, TEXT("Pièce LEGO %d mise en 'Movable': %s"), i, *LegoPieces[i]->GetName());
                }
            }
        }
    }
    ConstructionProgress = 0.0f;
}

void ALegoConstruction::StopConstruction()
{
    bIsConstructing = false;
}

void ALegoConstruction::MovePiece(int Index, float DeltaTime)
{
    if (!LegoPieces[Index]) return;

    FVector StartPos = StartPositions[Index];
    FVector EndPos = EndPositions[Index];

    FVector NewPosition = FMath::Lerp(StartPos, EndPos, ConstructionProgress);
    //LegoPieces[Index]->SetActorLocation(NewPosition);
}


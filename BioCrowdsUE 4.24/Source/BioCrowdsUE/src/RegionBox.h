// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RegionBox.generated.h"

UCLASS()
class BIOCROWDSUE_API ARegionBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARegionBox();
    UStaticMeshComponent* MyPtr;

    //Region(FBox box, double percent, int numAgents, TArray<FString> activities);
    
    FBox box;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    float percent = 0;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=SetUp)
    int numAgents = 0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    TArray<FString> activities;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SetUp)
        TArray<FString> Flags;


    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "src/Agent.h"

#include "Follower.h"

#include "Leader.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EForm : uint8 {
    EF_CLUMP UMETA(DisplayName="Clump"),
    EF_CLUMPLINE UMETA(DisplayName="ClumpLine"),
    EF_LINE UMETA(DisplayName="Line"),
    EF_RANDLINE UMETA(DisplayName="RandLine"),
    EF_WIDELINE UMETA(DisplayName="WideLine")
};

UCLASS()
class BIOCROWDSUE_API ALeader : public AAgent
{
	GENERATED_BODY()
    
public:
   // ALeader();

    TArray<AFollower*> followers;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Followers)
    int numFollowers = 1;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Followers)
    EForm formation;
 
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    TArray<FVector> points;

    //FormationEnum formation = FormationEnum::WHAT;

};

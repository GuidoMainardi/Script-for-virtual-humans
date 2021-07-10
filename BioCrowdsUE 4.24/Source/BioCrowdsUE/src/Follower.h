// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "src/Agent.h"
#include "Follower.generated.h"

/**
 * 
 */
UCLASS()
class BIOCROWDSUE_API AFollower : public AAgent
{
	GENERATED_BODY()
    
    public:
    AAgent* parent;
    float offsetBack;
    float offsetRight;

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Scenario.h"
#include "Cubo.h"
#include "BehaviourCommand.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoController.generated.h"

UCLASS()
class NEWDEMO_API ADemoController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADemoController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	ACubo* SpawnedActorRef;
	Scenario scene;
	float tempo;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<ACubo> ActorToSpawn;
};

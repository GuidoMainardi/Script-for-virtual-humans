// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "sampler.h"
#include <map>
#include "kdtree.h"
#include "Agent.h"
#include "AIController.h"
#include "region.hpp"
#include "RegionBox.h"
#include "Leader.h"
#include "Follower.h"
#include "Blueprint/UserWidget.h"
#include "Navmesh/RecastNavMesh.h"
#include <BioCrowdsUE\src\Scenario.h>
#include "BehaviourCommand.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrowdController.generated.h"

UCLASS()
class BIOCROWDSUE_API ACrowdController : public AActor {
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACrowdController();

    //Biocrowds
    void CreateSamples();
    void BuildKDT();
    void update(TArray<AAgent*> finished);
    void reassignMarkers(TArray<AAgent*> finished);
    float f(FVector x, FVector y);

    Sampler sampler;
    KDTree kdt;
    TArray<AAgent*> agents;
    TArray<ALeader*> leaders;
    TArray<AFollower*> CreateFollowers(AAgent* lead, FVector loc, int numFollow, ARecastNavMesh* navMesh, FNavLocation g, int depth);

    //Main script functions
    void Run_MainScriptCommand(ScriptCommand command);
    void Run_SimpleOperation(ScriptCommand command, AAgent* agent);
    void Run_OperationRUN(ScriptCommand command, AAgent* agent);
    void Run_OperationSTOP(ScriptCommand command, AAgent* agent);
    void Run_OperationLOOP(ScriptCommand command, AAgent* agent);
    //Behaviour Script functions
    void Run_AgentBehaviour(AAgent* agent, float DeltaTime);
    void Run_EndScript(AAgent* agent);
    void Run_BehaviourOperation(AAgent* agent);
    void Run_OpCodeGo(AAgent* agent, FString Destiny);
    void Run_OpCodePlay(AAgent* agent, FString animation);
    void Run_EndAction(AAgent* agent, float DeltaTime);
    // random location function
    int get_LocationIndex(FString regionName);
    // condition events
    void EventHandler();
    int NewPositions(AAgent* agent, FString Destiny);
    TMap<FString, TArray<ScriptCommand>> conditionsEvents;


    //TArray<FBox> quads;
    //TArray<int> qNumAgents;

    //heap of regions always choose minimum?
    //TArray<Region*> regs;
    TArray<ARegionBox*> regsVacant;
    TArray<ARegionBox*> regsFull;
    TMap<FString, int> Locais;
    Scenario scene;
    float time;
    //TArray<AAIController*> aic; //faster than getting controller each time? make sure matches up

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    int numSamples = 100000;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    int numAgents = 10; // set numAgents

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    int agentV = 100;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=SetUp)
    int agentR = 175;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Behavior)
    int duration = 200;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Widget)
    TSubclassOf<UUserWidget> WidgetBPRef;

    /*UFUNCTION()
    void OnSelected(AActor* TouchedActor, FKey ButtonPressed);*/

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};

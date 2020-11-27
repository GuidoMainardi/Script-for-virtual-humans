// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "bmarker.h"
#include "MarkerVis.h"
#include "Region.hpp"
#include "RegionBox.h"

#include "Components/TextRenderComponent.h"
#include "Engine/TextRenderActor.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"


#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Agent.generated.h"

class BMarker;

UCLASS()
class BIOCROWDSUE_API AAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
    AAgent();
    //AAgent(FVector goal, float maxV, float radius, TArray<BMarker*> markers);
    
    class USkeletalMeshComponent* MySkeleton;
    
    //Biocrowds
    void init(FVector goal, float maxV, float radius, float duration, TSubclassOf<UUserWidget> wbpr);
    FVector finalGoal;
    FVector goal;
    FVector currTarget;
    float maxV;
    float radius; //use GetSimpleCollisionRadius()?
    TArray<BMarker*> markers;
    TArray<FVector> path;
    TArray<AMarkerVis*> mVis;
    
    //Behavior
    ATextRenderActor* text;
    FString activity;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Behavior)
    int ticks = 0;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Behavior)
    int duration = 200;
    
    TSubclassOf<UUserWidget> WidgetBPRef;
    
    UPROPERTY(meta = (AgentMenu))
    class UButton* ShowGoal;
    
    UUserWidget* Menu;
    
    //Visuals
    bool showGoal;
    bool showMarkers;
    
    //Region* reg;
    ARegionBox* reg;

    UFUNCTION()
    void OnSelected(AActor* TouchedActor, FKey ButtonPressed);
    
    UFUNCTION()
    void toggleGoal() {
        showGoal = !showGoal;
    }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
   // void Menu(AActor* TouchedActor, FKey ButtonPressed);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

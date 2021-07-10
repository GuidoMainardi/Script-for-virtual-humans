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
    TMap<FString, UAnimSequence*> Animations;
    TMap<FString, UAnimBlueprint*> DefaultAnims;
    TMap<FString, USkeletalMesh*> Models;
    TMap<FString, UPhysicsAsset*> Physics;

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
    // Scripts
    bool inAction = false;
    FString nowPlaying = "";
    int pc = 0;
    bool hasSomethingToPlay = false;
    //animation
    UAnimSequence* Anim;
    bool inAnim = false;
    float animtime = 0.f;
    FString AnimName = "";
    UAnimBlueprint* Animdefault;
    //models
    USkeletalMesh* MeshObj;
    FString modelName = "Default";
    //Region* reg;
    ARegionBox* reg;
    //profile
    FString profile_Name;
    // loop
    bool inLoop = false;
    // location control
    FString CurrentLocation;
    // models and  animations
    void MyModels();
    void MyAnim();
    void MyPhysics();
    void MyDefaultAnimations();
    // motion
    float waiting_time = 0;

    UFUNCTION()
    void OnSelected(AActor* TouchedActor, FKey ButtonPressed);

    UFUNCTION()
    void toggleGoal() {
        showGoal = !showGoal;
    }

    void playAnimation(FString AnimName) {
        this->AnimName = AnimName;
        //UE_LOG(LogTemp, Warning, TEXT("Playing: %s"), *AnimName);
        GetMesh()->PlayAnimation(Animations[AnimName], false);
    }

    void setNewModel(FString modelName) {

        USkeletalMesh* TempMeshRef = Models[modelName];
        UPhysicsAsset* TempPhysRef = Physics[modelName];

        MeshObj = TempMeshRef;

        MySkeleton = GetMesh();
        MySkeleton->SetSkeletalMesh(TempMeshRef, false);
        MySkeleton->SetPhysicsAsset(TempPhysRef, false);

        MySkeleton->SetAnimInstanceClass(DefaultAnims[modelName]->GeneratedClass);

        MySkeleton->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));
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

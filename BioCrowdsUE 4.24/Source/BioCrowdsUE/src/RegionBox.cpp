// Fill out your copyright notice in the Description page of Project Settings.

#include "RegionBox.h"

// Sets default values
ARegionBox::ARegionBox() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
    
    MyPtr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
    
    UStaticMesh* Asset = MeshRef.Object;
    
    MyPtr->SetWorldScale3D(FVector(1, 1, 1));
    MyPtr->SetStaticMesh(Asset);
    SetActorEnableCollision(false);
    MyPtr->SetCanEverAffectNavigation(false);
    bIsEditorOnlyActor = true;
    SetActorHiddenInGame(true);
    Flags.Add("Place");
}

// Called when the game starts or when spawned
void ARegionBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARegionBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


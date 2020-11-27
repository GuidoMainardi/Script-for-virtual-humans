// Fill out your copyright notice in the Description page of Project Settings.
#include "MarkerVis.h"

// Sets default values
AMarkerVis::AMarkerVis()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;
    
    //Setting sphere as static mesh
    MyPtr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
    ConstructorHelpers::FObjectFinder<UStaticMesh>MeshRef(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));

    UStaticMesh* Asset = MeshRef.Object;
    
    MyPtr->SetWorldScale3D(FVector(0.02, 0.02, 0.02));
    MyPtr->SetStaticMesh(Asset);

}

// Called when the game starts or when spawned
void AMarkerVis::BeginPlay() {
	Super::BeginPlay();
}

// Called every frame
void AMarkerVis::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}


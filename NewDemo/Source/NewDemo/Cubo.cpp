// Fill out your copyright notice in the Description page of Project Settings.


#include "Cubo.h"
#include <math.h>
// Sets default values
ACubo::ACubo()
{

	// Create root
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	// Create Static Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BaseMeshAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	if (BaseMeshAsset.Object)
	{
		Mesh->SetStaticMesh(BaseMeshAsset.Object);
	}
	//CubeMesh = PCIP.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("CubeMesh"));
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	goal = this->GetActorLocation();

}

void ACubo::MoveTo(float DeltaTime) {

	FVector Location = this->GetActorLocation();
	FVector dir = GetActorForwardVector();
	dir.Set(goal.X - Location.X, goal.Y - Location.Y, goal.Z - Location.Z);
	dir.Normalize(1.0f);
	Location += dir * Speed * DeltaTime;
	this->SetActorLocation(Location);
}
// Called every frame
void ACubo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveTo(DeltaTime);

}


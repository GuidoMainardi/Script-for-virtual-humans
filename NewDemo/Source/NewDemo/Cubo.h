// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cubo.generated.h"

UCLASS()
class NEWDEMO_API ACubo : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACubo();
protected:
	//UPROPERTY(Category = Meshes, VisibleAnywhere)
		//TSubobjectPtr<UStaticMeshComponent> CubeMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
		class UStaticMeshComponent* Mesh;

private:
	void MoveTo(float DeltaTime);
	float Speed = 150.0f;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector goal;

};

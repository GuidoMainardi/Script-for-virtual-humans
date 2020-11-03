// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoController.h"

// Sets default values
ADemoController::ADemoController()
{
	scene = Scenario();
	tempo = 0.0f;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADemoController::BeginPlay()
{
	Super::BeginPlay();
	FVector Location(0.0f, 0.0f, 20.0f);
	FRotator Rotation(0.0f, 1.0f, 0.0f);
	FActorSpawnParameters SpawnParams;
	SpawnedActorRef = GetWorld()->SpawnActor<ACubo>(ActorToSpawn, Location, Rotation, SpawnParams);
	scene.load();
}

// Called every frame
void ADemoController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	tempo += DeltaTime;
	for (auto c : scene.text) {
		if (c.getTime() == int(tempo)) {
			if (c.getOperation() == Operation::RUN) {
				for (BehaviourCommand inst : scene.Scripts.find(c.getBehaviour())->second.text) {
					if (inst.getOpcode() == Opcode::GO) {
						auto local = inst.getPlace();
						FVector vaipara(local.getX(), local.getY(), local.getZ());
						SpawnedActorRef->goal = vaipara;
					}
				}
			}
			//if (c.getOperation() == Operation::STOP) {}
		}
		if (tempo > 10) { tempo = 0; }
	}
}


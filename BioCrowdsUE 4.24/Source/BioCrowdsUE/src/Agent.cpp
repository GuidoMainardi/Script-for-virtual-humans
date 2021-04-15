// Fill out your copyright notice in the Description page of Project Settings.

#include "Agent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"


// Can't use constructors when calling spawn actor
AAgent::AAgent()
{
    PrimaryActorTick.bCanEverTick = true;
    
	ConstructorHelpers::FObjectFinder<USkeletalMesh>MeshRef(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
    
	ConstructorHelpers::FObjectFinder<UAnimBlueprint>AnimRef(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));
    
	ConstructorHelpers::FObjectFinder<UPhysicsAsset>PhysRef(TEXT("PhysicsAsset'/Game/Mannequin/Character/Mesh/SK_Mannequin_PhysicsAsset.SK_Mannequin_PhysicsAsset'"));
    Animdefault = AnimRef.Object;


    ConstructorHelpers::FObjectFinder<UAnimSequence>AnimSequence(TEXT("AnimSequence'/Game/Mannequin/Animations/Dance.Dance'"));
    Animations.Add(TEXT("Dance"), AnimSequence.Object);
    
    
    USkeletalMesh* MeshObj = MeshRef.Object;
    
    MySkeleton = GetMesh();
    MySkeleton->SetSkeletalMesh(MeshRef.Object);
    MySkeleton->SetPhysicsAsset(PhysRef.Object);
    
    MySkeleton->SetAnimInstanceClass(AnimRef.Object->GeneratedClass);
    
    MySkeleton->SetRelativeLocationAndRotation(FVector(0, 0, -90), FRotator(0, -90, 0));

    //three orientation variables
    bUseControllerRotationYaw = false;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->bUseControllerDesiredRotation = false;
    
    GetCapsuleComponent()->SetCollisionProfileName("OverlapOnlyPawn");
    showGoal = true;
    showMarkers = true;

    

}

void AAgent::OnSelected(AActor* TouchedActor, FKey ButtonPressed) {
    GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Cyan, FString("EEEEEEEEEEEEEEEEE"));
    //showGoal = !showGoal;
    //showMarkers = !showMarkers;
    Menu = CreateWidget<UUserWidget>(GetWorld(), WidgetBPRef);
    Menu->AddToViewport();
    //ShowGoal->OnClicked.AddDynamic(this, &AAgent::toggleGoal);
}


//won't be used
/*AAgent::AAgent(FVector goal, float maxV, float radius, TArray<BMarker*> markers) : goal(goal), maxV(maxV), radius(radius), markers(markers)
{}*/

//use to set up parameters instead
void AAgent::init(FVector g, float v, float r, float d, TSubclassOf<UUserWidget> w) {
    goal = g;
    maxV = v;
    radius = r;
    duration = d;
    WidgetBPRef = w;
}

// Called when the game starts or when spawned
void AAgent::BeginPlay()
{
	Super::BeginPlay();
    OnClicked.AddUniqueDynamic(this, &AAgent::OnSelected);
	
}

// Called every frame
void AAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


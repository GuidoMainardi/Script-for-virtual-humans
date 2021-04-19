// Fill out your copyright notice in the Description page of Project Settings.

#include "Agent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

void AAgent::MyModels(){
    ConstructorHelpers::FObjectFinder<USkeletalMesh>MacerenaMeshRef(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/Macarena_Dance.Macarena_Dance'"));
    Models.Add(TEXT("Macarena"), MacerenaMeshRef.Object);
    ConstructorHelpers::FObjectFinder<USkeletalMesh>DefaultMeshRef(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
    Models.Add(TEXT("Default"), DefaultMeshRef.Object);
}
void AAgent::MyPhysics() {
    ConstructorHelpers::FObjectFinder<UPhysicsAsset>MacarenaPhysRef(TEXT("PhysicsAsset'/Game/Mannequin/Character/Mesh/Macarena_Dance_PhysicsAsset.Macarena_Dance_PhysicsAsset'"));
    Physics.Add(TEXT("Macarena"), MacarenaPhysRef.Object);
    ConstructorHelpers::FObjectFinder<UPhysicsAsset>DefaultPhysRef(TEXT("PhysicsAsset'/Game/Mannequin/Character/Mesh/SK_Mannequin_PhysicsAsset.SK_Mannequin_PhysicsAsset'"));
    Physics.Add(TEXT("Default"), DefaultPhysRef.Object);
}
void AAgent::MyDefaultAnimations() {
    ConstructorHelpers::FObjectFinder<UAnimBlueprint>MacarenaDefaultAnimRef(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP_Macarena.ThirdPerson_AnimBP_Macarena'"));
    DefaultAnims.Add(TEXT("Macarena"), MacarenaDefaultAnimRef.Object);
    ConstructorHelpers::FObjectFinder<UAnimBlueprint>DefaultAnimRef(TEXT("AnimBlueprint'/Game/Mannequin/Animations/ThirdPerson_AnimBP.ThirdPerson_AnimBP'"));
    DefaultAnims.Add(TEXT("Default"), DefaultAnimRef.Object);
}
void AAgent::MyAnim() {
    ConstructorHelpers::FObjectFinder<UAnimSequence>DefaultMeshDanceAnim(TEXT("AnimSequence'/Game/Mannequin/Animations/Dance.Dance'"));
    Animations.Add(TEXT("Dance"), DefaultMeshDanceAnim.Object);
    ConstructorHelpers::FObjectFinder<UAnimSequence>MacarenaMeshDanceAnim(TEXT("AnimSequence'/Game/Mannequin/Animations/Macarena_Dance_Anim.Macarena_Dance_Anim'"));
    Animations.Add(TEXT("MacarenaDance"), MacarenaMeshDanceAnim.Object);
}
// Can't use constructors when calling spawn actor
AAgent::AAgent()
{
    PrimaryActorTick.bCanEverTick = true;

    MyAnim();
    MyModels();
    MyPhysics();
    MyDefaultAnimations();
    setNewModel("Default");

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


// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimFinder.h"

AnimFinder::AnimFinder(FString Animation)
{
    FString path = "AnimSequence'/Game/Mannequin/Animations/" + Animation + "." + Animation + "'";
    static ConstructorHelpers::FObjectFinder<UAnimSequence> anim(*path);
    this->Anim = anim.Object;
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "Senario.h"


bool USenario::LoadTxt(FString FileNameA, FString& SaveTextA)
{
    UE_LOG(LogTemp, Warning, TEXT("%s"), *FPaths::GameSourceDir());
    return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameSourceDir() + "NewDemo\\" + FileNameA));
}

bool USenario::SaveTxt(FString SaveTextB, FString FileNameB)
{
    return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameSourceDir() + "NewDemo\\" + FileNameB));
}
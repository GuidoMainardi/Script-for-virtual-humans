// Fill out your copyright notice in the Description page of Project Settings.


#include "FIleReader.h"

bool UFIleReader::LoadTxt(FString FileNameA, FString& SaveTextA)
{
    //UE_LOG(LogTemp, Warning, TEXT("%s"), *FPaths::GameSourceDir());
    return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::GameSourceDir() + "..\\Scripts\\" + FileNameA));
}

bool UFIleReader::SaveTxt(FString SaveTextB, FString FileNameB)
{
    return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::GameSourceDir() + "..\\Scripts\\" + FileNameB));
}
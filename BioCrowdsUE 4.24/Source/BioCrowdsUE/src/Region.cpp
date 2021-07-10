//
//  Region.cpp
//  BioCrowdsUE_Index
//
//  Created by Kristin Chow on 9/26/19.
//  Copyright © 2019 Epic Games, Inc. All rights reserved.
//

#include "Region.hpp"

Region::Region() : box(FBox()), percent(.25), numAgents(0), activities(TArray<FString>())
{}

Region::Region(FBox box, double percent, int numAgents, TArray<FString> activities) : box(box), percent(percent), numAgents(numAgents), activities(activities)
{}

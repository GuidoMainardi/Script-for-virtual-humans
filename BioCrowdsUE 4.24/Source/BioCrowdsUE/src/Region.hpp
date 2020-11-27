//
//  Region.hpp
//  BioCrowdsUE_Index
//
//  Created by Kristin Chow on 9/26/19.
//  Copyright © 2019 Epic Games, Inc. All rights reserved.
//

#ifndef Region_hpp
#define Region_hpp

#include <stdio.h>

class Region {
public:
    Region();
    Region(FBox box, double percent, int numAgents, TArray<FString> activities);

    FBox box;
    double percent;
    int numAgents;
    TArray<FString> activities;
};

#endif /* Region_hpp */

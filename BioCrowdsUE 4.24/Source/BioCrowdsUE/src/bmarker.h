#pragma once

#include "Agent.h"

class AAgent;

class BMarker {
public:
    FVector pos;
    FVector col;
    AAgent* agent;

    BMarker();
    BMarker(FVector pos, FVector col);
    ~BMarker() {}
};


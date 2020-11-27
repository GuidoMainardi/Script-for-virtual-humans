#include "bmarker.h"

BMarker::BMarker() : BMarker(FVector(0.f), FVector(1.f))
{}

BMarker::BMarker(FVector pos, FVector col) : pos(pos), col(col), agent(nullptr)
{}

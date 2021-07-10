#pragma once
#include "pcg32.h"

class Sampler {
public:
    Sampler();

    void generateSamples(int& numSamples, TArray<TArray<FVector>> Verts);

    unsigned int getNumSamples();
    
    TArray<FVector>& peekSamples();
    TArray<FVector> &peekSampleColors();

    static float rejectionSampleDisk();


    TArray<FVector> samples; // Every 3 floats is a point
    TArray<FVector> sampleColors; // Every 3 floats is a point's color
};

// PDF of disc is 1/PI because area of disc is PI*r^2, and r = 1.

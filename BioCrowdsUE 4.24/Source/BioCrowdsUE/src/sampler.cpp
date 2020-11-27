#include "sampler.h"

Sampler::Sampler()
{}

//gets triangle indices
TArray<int> vertsToTri(int verts) {
    TArray<int> tri;
    for (int i = 2; i < verts; i++) {
        tri.Push(0);
        tri.Push(i-1);
        tri.Push(i);
    }
    return tri;
}

//gets polygon area
float polyArea(TArray<int> idx, TArray<FVector> verts) {
    float area = 0.f;
    for (int i = 0; i < idx.Num(); i+=3) {
        //triangle verts
        FVector a = verts[idx[i]];
        FVector b = verts[idx[i + 1]];
        FVector c = verts[idx[i + 2]];
        float s = 0.5f * FVector::CrossProduct(a - b, c - b).Size();
        area += s;
    }
    return area;
}

void Sampler::generateSamples(int& numSamples, TArray<TArray<FVector>> verts) {    
    pcg32 rng;
    
    float totalArea = 0;
    
    //triangulate each polygon and get total area
    for (TArray<FVector> poly : verts) {
        TArray<int> idx = vertsToTri(poly.Num());
        float area = polyArea(vertsToTri(poly.Num()), poly);
        totalArea += area;
    }
    
    for (TArray<FVector> poly : verts) {
        TArray<int> idx = vertsToTri(poly.Num());
        
        for (int i = 0; i < idx.Num(); i+=3) {
            //triangle verts
            FVector a = poly[idx[i]];
            FVector b = poly[idx[i + 1]];
            FVector c = poly[idx[i + 2]];
            
            float triarea = 0.5f * FVector::CrossProduct(a - b, c - b).Size();
            float weight = triarea / totalArea;
            float numSamp = weight * numSamples;
            
            FVector ab = b - a;
            FVector ac = c - a;
            
            for (int j = 0; j < numSamp; j++) {
                float r = rng.nextFloat();
                float s = rng.nextFloat();
                
                if (r + s >= 1) {
                    float diff = r + s - 1;
                    r -= diff;
                    s -= diff;
                }
                
                FVector rand = a + r * ab + s * ac;
                samples.Push(rand);
                sampleColors.Push(FVector(1.f));
            }
        }
    }
}

unsigned int Sampler::getNumSamples() {
    return this->samples.Num();
}

TArray<FVector> &Sampler::peekSamples() {
    return this->samples;
}

TArray<FVector>& Sampler::peekSampleColors() {
    return this->sampleColors;
}

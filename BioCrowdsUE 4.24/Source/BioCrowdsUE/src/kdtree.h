#pragma once
#include "bmarker.h"

class KDNode {
public:
    KDNode();
    ~KDNode();

    KDNode* leftChild;
    KDNode* rightChild;
    unsigned int axis; // Which axis split this node represents
    FVector minCorner, maxCorner; // The world-space bounds of this node
    TArray<BMarker*> particles; // A collection of pointers to the particles contained in this node.
};

class KDTree {
public:
    KDTree();
    ~KDTree();
    void build(const TArray<FVector*> &points);
    KDNode* buildNode(TArray<BMarker*> sorted, int depth);
    KDNode* buildKdTree(const TArray<BMarker*> &points, int depth);
    void clear();

    TArray<BMarker*> particlesInSphere(FVector c, float r); // Returns all the points contained within a sphere with center c and radius r
    void searchKdTree(TArray<BMarker*>* p, KDNode* v, FVector c, float r);

    KDNode* root;
    FVector minCorner, maxCorner; // For visualization purposes
};


#include "kdtree.h"

KDNode::KDNode()
    : leftChild(nullptr), rightChild(nullptr), axis(0), minCorner(), maxCorner(), particles()
{}

KDNode::~KDNode()
{
    delete leftChild;
    delete rightChild;
}

KDTree::KDTree()
    : root(nullptr)
{}

KDTree::~KDTree()
{
    delete root;
}

// Comparator functions to sort FVectors along the cardinal axes
bool xSort(BMarker* a, BMarker* b) { return a->pos.X < b->pos.X; }
bool ySort(BMarker* a, BMarker* b) { return a->pos.Y < b->pos.Y; }
bool zSort(BMarker* a, BMarker* b) { return a->pos.Z < b->pos.Z; }


void KDTree::build(const TArray<FVector*> &points) {
    TArray<BMarker*> marks;
    for (FVector* p : points) {
        FVector np = *p;
        BMarker* m = new BMarker(np, FVector(1.f));
        marks.Add(m);
    }

    //sort points by x
    TArray<BMarker*> xSorted = marks;
    Algo::Sort(xSorted, xSort);
    
    //set up root and find min and max corners
    root = buildKdTree(marks, 0);
    minCorner = root->minCorner;
    maxCorner = root->maxCorner;
}

KDNode* KDTree::buildNode(TArray<BMarker*> sorted, int depth) {
    //build left and right halfs split by the median
    TArray<BMarker*> lHalf;
    TArray<BMarker*> rHalf;
    for (int i = 0.f; i < sorted.Num() / 2.f; i++) {
        lHalf.Add(sorted[i]);
    }
    for (int i = sorted.Num() / 2.f; i < sorted.Num(); i++) {
        rHalf.Add(sorted[i]);
    }

    KDNode* node = new KDNode();

    //find min and max corners
    float minX = INFINITY;
    float maxX = -INFINITY;
    float minY = INFINITY;
    float maxY = -INFINITY;
    float minZ = INFINITY;
    float maxZ = -INFINITY;
    for (int i = 0; i < sorted.Num(); i++) {
        if (sorted[i]->pos.X < minX) { minX = sorted[i]->pos.X; }
        if (sorted[i]->pos.X > maxX) { maxX = sorted[i]->pos.X; }
        if (sorted[i]->pos.Y < minY) { minY = sorted[i]->pos.Y; }
        if (sorted[i]->pos.Y > maxY) { maxY = sorted[i]->pos.Y; }
        if (sorted[i]->pos.Z < minZ) { minZ = sorted[i]->pos.Z; }
        if (sorted[i]->pos.Z > maxZ) { maxZ = sorted[i]->pos.Z; }
    }
    node->minCorner = FVector(minX, minY, minZ);
    node->maxCorner = FVector(maxX, maxY, maxZ);
    node->axis = depth % 3;
    node->leftChild = buildKdTree(lHalf, depth + 1);
    node->rightChild = buildKdTree(rHalf, depth + 1);
    return node;
}

KDNode* KDTree::buildKdTree(const TArray<BMarker*> &points, int depth) {
    if (points.Num() == 1) {
        KDNode* leaf = new KDNode();
        leaf->particles.Add(points[0]);
        leaf->leftChild = nullptr;
        leaf->rightChild = nullptr;
        leaf->minCorner = FVector(points[0]->pos.X, points[0]->pos.Y, points[0]->pos.Z);
        leaf->maxCorner = FVector(points[0]->pos.X, points[0]->pos.Y, points[0]->pos.Z);
        return leaf;
    } else if (points.Num() == 0) {
        return nullptr;
    } else if (depth % 3 == 0) {
        //xsort the array
        TArray<BMarker*> xSorted = points;
        Algo::Sort(xSorted, xSort);
        return buildNode(xSorted, depth);
    } else if (depth % 3 == 1) {
        //ysort the array
        TArray<BMarker*> ySorted = points;
        Algo::Sort(ySorted, ySort);
        return buildNode(ySorted, depth);
    } else {
        //zsort the array
        TArray<BMarker*> zSorted = points;
        Algo::Sort(zSorted, zSort);
        return buildNode(zSorted, depth);
    }
}

TArray<BMarker*> KDTree::particlesInSphere(FVector c, float r)
{
    TArray<BMarker*> p;
    searchKdTree(&p, root, c, r);
    return p;
}

//additional helper functions for search

//checks if a sphere contains a point
bool pInSphere(FVector c, FVector p, float r) {
    if (FVector::Distance(c, p) < r) {
        return true;
    } else {
        return false;
    }
}

//checks if a sphere contains a point
bool pInSphereMark(FVector c, BMarker* p, float r) {
    if (FVector::Distance(c, p->pos) < r) {
        return true;
    } else {
        return false;
    }
}

//checks if a box intersects a sphere
bool intersectsSphere(FVector minC, FVector maxC, FVector c, float r) {
    //find closest point to sphere
    float x = FMath::Max(minC.X, FMath::Min(c.X, maxC.X));
    float y = FMath::Max(minC.Y, FMath::Min(c.Y, maxC.Y));
    float z = FMath::Max(minC.Z, FMath::Min(c.Z, maxC.Z));

    float distance = FMath::Sqrt((x - c.X) * (x - c.X) +
                               (y - c.Y) * (y - c.Y) +
                               (z - c.Z) * (z - c.Z));

    //also check if sphere is inside box
    return (distance < r || (c.X < maxC.X && c.X > minC.X &&
                             c.Y < maxC.Y && c.Y > minC.Y &&
                             c.Z < maxC.Z && c.Z > minC.Z));
}

//recursively iterates down from a node to get all the particles in the leaves
void getPoints(TArray<BMarker*>* pts, KDNode* n) {
    //if found leaf
    if (n->leftChild == nullptr && n->rightChild == nullptr) {
        pts->Add(n->particles[0]);
        return;
    }
    if (n->leftChild != nullptr) {
        getPoints(pts, n->leftChild);
    }
    if (n->rightChild != nullptr) {
        getPoints(pts, n->rightChild);
    }
}

//check if all points of a box are in the sphere
bool fullyContained(FVector min, FVector max, FVector c, float r) {
    FVector p1 = FVector(min.X, min.Y, max.Z);
    FVector p2 = FVector(min.X, max.Y, min.Z);
    FVector p3 = FVector(max.X, min.Y, min.Z);
    FVector p4 = FVector(max.X, max.Y, min.Z);
    FVector p5 = FVector(max.X, min.Y, max.Z);
    FVector p6 = FVector(min.X, max.Y, max.Z);
    return (pInSphere(c, min, r) && pInSphere(c, max, r) && pInSphere(c, p1, r)
            && pInSphere(c, p2, r) && pInSphere(c, p3, r) && pInSphere(c, p4, r)
            && pInSphere(c, p5, r) && pInSphere(c, p6, r));
}

void KDTree::searchKdTree(TArray<BMarker*>* p, KDNode* v, FVector c, float r) {
    //if node is a leaf
    if (v->leftChild == nullptr && v->rightChild == nullptr) {
        //check if point is in sphere
        if (pInSphereMark(c, v->particles[0], r)) {
            p->Add(v->particles[0]);
        }
    } else {
        KDNode* lt = v->leftChild;
        KDNode* rt = v->rightChild;
        if (lt != nullptr) {
            //if left region is fully contained in the radius else if intersects
            if (fullyContained(lt->minCorner, lt->maxCorner, c, r)) {
                //get the points in the left region
                getPoints(p, lt);
            } else if (intersectsSphere(lt->minCorner, lt->maxCorner, c, r)) {
                //search the left region
                searchKdTree(p, lt, c, r);
            }
        }
        if (rt != nullptr) {
            //if right region is fully contained in the radius else if intersects
            if (fullyContained(rt->minCorner, rt->maxCorner, c, r)) {
                //get the points in the right region
                getPoints(p, rt);
            } else if (intersectsSphere(rt->minCorner, rt->maxCorner, c, r)) {
                //search the right region
                searchKdTree(p, rt, c, r);
            }
        }
    }
}

void KDTree::clear()
{
    delete root;
    root = nullptr;
}



#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_ACCELERATOR_BVH__
#define __RENDERMOON_ACCELERATOR_BVH__

#include <core/aggregate.h>

class BBox;
class Vec3;
struct BVHPrimitiveInfo;
struct BVHBuildNode;
struct LinearBVHNode;

using namespace std;

class BVHAccel : public Aggregate
{
public:
    BVHAccel(const vector<Reference<Primitive> > &p, uint32_t maxPrims = 1, const std::string &sm = "sah");

    //implementation primitive
    virtual BBox WorldBound() const;
    virtual bool GetIntersection(const Ray &ray, Intersection& isect) const;
    virtual bool IsIntersected(const Ray &ray) const;


    bool CanIntersect() const { return true; }
    ~BVHAccel();
private:
    // BVHAccel Private Methods
    BVHBuildNode *recursiveBuild(MemoryArena &buildArena, std::vector<BVHPrimitiveInfo> &buildData, uint32_t start, uint32_t end, uint32_t *totalNodes, vector<Reference<Primitive> > &orderedPrims);
    uint32_t flattenBVHTree(BVHBuildNode *node, uint32_t *offset);

    // BVHAccel Private Data
    uint32_t maxPrimsInNode;
    enum SplitMethod { SPLIT_MIDDLE, SPLIT_EQUAL_COUNTS, SPLIT_SAH };
    SplitMethod splitMethod;
    vector<Reference<Primitive> > primitives;
    LinearBVHNode *nodes;
};

#endif

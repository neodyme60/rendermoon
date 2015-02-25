#include <rendermoon.h>
/*
#include "texture.h"
#include "shape.h"
*/

/*
// Texture Method Definitions
UVMapping2D::UVMapping2D(float ssu, float ssv, float ddu, float ddv) : su(ssu), sv(ssv), du(ddu), dv(ddv)
{
}

void UVMapping2D::Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const
{
    *s = su * dg.u + du;
    *t = sv * dg.v + dv;
    // Compute texture differentials for 2D identity mapping
    *dsdx = su * dg.dudx;
    *dtdx = sv * dg.dvdx;
    *dsdy = su * dg.dudy;
    *dtdy = sv * dg.dvdy;
}


void SphericalMapping2D::Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const
{
    sphere(dg.p, s, t);
    // Compute texture coordinate differentials for sphere $(u,v)$ mapping
    float sx, tx, sy, ty;
    const float delta = .1f;
    sphere(dg.p + delta * dg.dpdx, &sx, &tx);
    *dsdx = (sx - *s) / delta;
    *dtdx = (tx - *t) / delta;
    if (*dtdx > .5) *dtdx = 1.f - *dtdx;
    else if (*dtdx < -.5f) *dtdx = -(*dtdx + 1);
    sphere(dg.p + delta * dg.dpdy, &sy, &ty);
    *dsdy = (sy - *s) / delta;
    *dtdy = (ty - *t) / delta;
    if (*dtdy > .5) *dtdy = 1.f - *dtdy;
    else if (*dtdy < -.5f) *dtdy = -(*dtdy + 1);
}


void SphericalMapping2D::sphere(const Point &p, float *s, float *t) const
{
    Vector vec = Normalize(WorldToTexture(p) - Point(0,0,0));
    float theta = SphericalTheta(vec);
    float phi = SphericalPhi(vec);
    *s = theta * INV_PI;
    *t = phi * INV_TWOPI;
}


void PlanarMapping2D::Map(const DifferentialGeometry &dg, float *s, float *t, float *dsdx, float *dtdx, float *dsdy, float *dtdy) const
{
    Vector vec = dg.p - Point(0,0,0);
    *s = ds + Dot(vec, vs);
    *t = dt + Dot(vec, vt);
    *dsdx = Dot(dg.dpdx, vs);
    *dtdx = Dot(dg.dpdx, vt);
    *dsdy = Dot(dg.dpdy, vs);
    *dtdy = Dot(dg.dpdy, vt);
}


*/
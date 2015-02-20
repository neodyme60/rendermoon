#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_MONTECARLO__
#define __RENDERMOON_CORE_MONTECARLO__

Vec3 UniformSampleSphere(float u1, float u2);
float UniformSpherePdf();

Vec3 UniformSampleHemisphere(float u1, float u2);
float UniformHemispherePdf();


float UniformConePdf(float cosThetaMax);
Vec3 UniformSampleCone(float u1, float u2, float costhetamax);
Vec3 UniformSampleCone(float u1, float u2, float costhetamax, const Vec3 &x, const Vec3 &y, const Vec3 &z);

inline float BalanceHeuristic(int nf, float fPdf, int ng, float gPdf) {
    return (nf * fPdf) / (nf * fPdf + ng * gPdf);
}


inline float PowerHeuristic(int nf, float fPdf, int ng, float gPdf) {
    float f = nf * fPdf, g = ng * gPdf;
    return (f*f) / (f*f + g*g);
}




#endif

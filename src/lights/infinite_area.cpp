#include <rendermoon.h>



InfiniteAreaLight::InfiniteAreaLight(const Transform &l2w, const Spectrum &intensity) : Light(l2w) {

}

float InfiniteAreaLight::Pdf(const Point &p, const Vec3 &wi) const {
    return 0;
}

Spectrum InfiniteAreaLight::Sample_L(const Point &p, float pEpsilon, float time, Vec3 *wi, float *pdf, VisibilityTester &visibility) const {
    return Spectrum();
}

Spectrum InfiniteAreaLight::Sample_L(const Scene *scene, float u1, float u2, float time, Ray *ray, Normal *Ns, float *pdf) const {
    return Spectrum();
}

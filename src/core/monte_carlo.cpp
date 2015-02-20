#include <rendermoon.h>

// Monte Carlo Function Definitions
void RejectionSampleDisk(float *x, float *y, float u1, float u2) {
    float sx, sy;
    do {
        sx = 1.f - 2.f * u1;
        sy = 1.f - 2.f * u2;
    } while (sx*sx + sy*sy > 1.f);
    *x = sx;
    *y = sy;
}


Vec3 UniformSampleHemisphere(float u1, float u2) {
    float z = u1;
    float r = sqrtf(max(0.f, 1.f - z*z));
    float phi = 2 * M_PI * u2;
    float x = r * cosf(phi);
    float y = r * sinf(phi);
    return Vec3(x, y, z);
}


float UniformHemispherePdf() {
    return INV_TWOPI;
}


Vec3 UniformSampleSphere(float u1, float u2) {
    float z = 1.f - 2.f * u1;
    float r = sqrtf(max(0.f, 1.f - z*z));
    float phi = 2.f * M_PI * u2;
    float x = r * cosf(phi);
    float y = r * sinf(phi);
    return Vec3(x, y, z);
}


float UniformSpherePdf() {
    return 1.f / (4.f * M_PI);
}


void UniformSampleDisk(float u1, float u2, float *x, float *y) {
    float r = sqrtf(u1);
    float theta = 2.0f * M_PI * u2;
    *x = r * cosf(theta);
    *y = r * sinf(theta);
}


void ConcentricSampleDisk(float u1, float u2, float *dx, float *dy) {
    float r, theta;
    // Map uniform random numbers to $[-1,1]^2$
    float sx = 2 * u1 - 1;
    float sy = 2 * u2 - 1;

    // Map square to $(r,\theta)$

    // Handle degeneracy at the origin
    if (sx == 0.0 && sy == 0.0) {
        *dx = 0.0;
        *dy = 0.0;
        return;
    }
    if (sx >= -sy) {
        if (sx > sy) {
            // Handle first region of disk
            r = sx;
            if (sy > 0.0) theta = sy/r;
            else          theta = 8.0f + sy/r;
        }
        else {
            // Handle second region of disk
            r = sy;
            theta = 2.0f - sx/r;
        }
    }
    else {
        if (sx <= sy) {
            // Handle third region of disk
            r = -sx;
            theta = 4.0f - sy/r;
        }
        else {
            // Handle fourth region of disk
            r = -sy;
            theta = 6.0f + sx/r;
        }
    }
    theta *= M_PI / 4.f;
    *dx = r * cosf(theta);
    *dy = r * sinf(theta);
}


void UniformSampleTriangle(float u1, float u2, float *u, float *v)
{
    float su1 = sqrtf(u1);
    *u = 1.f - su1;
    *v = u2 * su1;
}


float UniformConePdf(float cosThetaMax)
{
    return 1.0f / (2.0f * M_PI * (1.0f - cosThetaMax));
}


Vec3 UniformSampleCone(float u1, float u2, float costhetamax)
{
    float costheta = (1.0f - u1) + u1 * costhetamax;
    float sintheta = sqrtf(1.0f - costheta*costheta);
    float phi = u2 * 2.0f * M_PI;
    return Vec3(cosf(phi) * sintheta, sinf(phi) * sintheta, costheta);
}


Vec3 UniformSampleCone(float u1, float u2, float costhetamax, const Vec3 &x, const Vec3 &y, const Vec3 &z)
{
    float costheta = Lerp(u1, costhetamax, 1.0f);
    float sintheta = sqrtf(1.0f - costheta*costheta);
    float phi = u2 * 2.0f * M_PI;
    return cosf(phi) * sintheta * x + sinf(phi) * sintheta * y + costheta * z;
}


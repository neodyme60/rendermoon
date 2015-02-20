#include <rendermoon.h>

GlossyReflection::GlossyReflection(const Spectrum& ray, float n) :  m_Reflectance(ray), m_exponent(n)
{
}

Spectrum GlossyReflection::f(const Vec3& wo, const Vec3& wi) const
{
    Vec3 wc = Vec3(-wo.x, -wo.y, wo.z); //perfect specular reflected
	float alpha = max(Dot(Normalize(wi), Normalize(wc)), 0.0f);
	float coef = (m_exponent + 2) * INV_TWOPI * powf(alpha, m_exponent);
	Spectrum f = m_Reflectance * coef;
    return f;
}

Spectrum GlossyReflection::Sample_f(const Vec3& wo, Vec3& wi, float u1, float u2, float *pdf) const
{
    Vec3 wc = Vec3(-wo.x, -wo.y, wo.z); //perfect specular reflected
    Vec3 wcX, wcY;
    CoordinateSystem(wc, &wcX, &wcY);
    float theta = acos(pow(1.0f-u1, 1.0f/(m_exponent+1.0f)));
    float phi = 2.0f * M_PI * u2;

    wi = cosf(phi) * sin(theta) * wcX + sinf(phi) * sin(theta) * wcY + cos(theta) * wc;

	float alpha = max(Dot(Normalize(wi), Normalize(wc)), 0.0f);

	*pdf = (m_exponent+1) * INV_TWOPI *  powf(alpha, m_exponent);
	return f(wo, wi);
}

float GlossyReflection::Pdf(const Vec3& wo, const Vec3& wi) const
{
    Vec3 wc = Vec3(-wo.x, -wo.y, wo.z); //perfect specular reflected
	float alpha = max(Dot(Normalize(wi), Normalize(wc)), 0.0f);
    return (m_exponent+1) * INV_TWOPI *  powf(alpha, m_exponent);
}

GlossyReflection::~GlossyReflection()
{

}

#ifndef __RENDERMOON_CORE_SPECTRUM__
#define __RENDERMOON_CORE_SPECTRUM__

class Spectrum
{
public:
    Spectrum() 
	{
		c.x=0.0f;
		c.y=0.0f;
		c.z=0.0f;
	}

    Spectrum(float value) 	
	{
		c.x=value;
		c.y=value;
		c.z=value;
	}

    Spectrum(const Vec3 value) 	
	{
		c.x=value.x;
		c.y=value.y;
		c.z=value.z;
	}


    Spectrum &operator+=(const Spectrum s) 
	{
        c.x+=s.c.x; c.y+=s.c.y; c.z+=s.c.z;
        return *this;
    }

    Spectrum &operator/=(float v) 
	{
        float inv = 1.0f/v;
        c.x *= inv; c.y *= inv; c.z *= inv;
        return *this;
    }

    Spectrum operator*(const Spectrum s) 
	{
        return Spectrum(Vec3(c.x * s.c.x, c.y * s.c.y, c.z * s.c.z));
    }


	Vec3 c;

//	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};

#endif

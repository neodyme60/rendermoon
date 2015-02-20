#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_SPECTRUM__
#define __RENDERMOON_CORE_SPECTRUM__

inline void XYZToRGB(const float xyz[3], float rgb[3])
{
    rgb[0] =  3.240479f*xyz[0] - 1.537150f*xyz[1] - 0.498535f*xyz[2];
    rgb[1] = -0.969256f*xyz[0] + 1.875991f*xyz[1] + 0.041556f*xyz[2];
    rgb[2] =  0.055648f*xyz[0] - 0.204043f*xyz[1] + 1.057311f*xyz[2];
}


inline void RGBToXYZ(const float rgb[3], float xyz[3])
{
    xyz[0] = 0.412453f*rgb[0] + 0.357580f*rgb[1] + 0.180423f*rgb[2];
    xyz[1] = 0.212671f*rgb[0] + 0.715160f*rgb[1] + 0.072169f*rgb[2];
    xyz[2] = 0.019334f*rgb[0] + 0.119193f*rgb[1] + 0.950227f*rgb[2];
}

class Spectrum
{
public:
    Spectrum() 
	{
        m_data = std::vector<float>(3);
        for(int i=0 ; i< 3; i++)
	    	m_data[i]=0.0f;
	}

    Spectrum(float value) 	
	{
        m_data = std::vector<float>(3);
        for(int i=0 ; i< 3; i++)
            m_data[i]=value;
	}

    Spectrum(const Vec3 value) 	
	{
        m_data = std::vector<float>(3);
        m_data[0]=value.x;
        m_data[1]=value.y;
        m_data[2]=value.z;
	}

    Spectrum &operator+=(const Spectrum& s)
	{
        for(int i=0 ; i< 3; i++)
            m_data[i]+=s.m_data[i];
        return *this;
    }

    Spectrum &operator/=(float v)
	{
        float inv = 1.0f/v;
        for(int i=0 ; i< 3; i++)
            m_data[i]*=inv;
        return *this;
    }

    Spectrum operator*(const Spectrum& s)  const
	{
        Spectrum c;
        for(int i=0 ; i< 3; i++)
            c.m_data[i]=s.m_data[i] * this->m_data[i];
        return c;
    }

    Spectrum operator*(float s)  const
    {
        Spectrum c;
        for(int i=0 ; i< 3; i++)
            c.m_data[i]=this->m_data[i] * s;
        return c;
    }

    static Spectrum FromRGB(const float rgb[3])
    {
        Spectrum s;
        s.m_data[0] = rgb[0];
        s.m_data[1] = rgb[1];
        s.m_data[2] = rgb[2];
//        Assert(!s.HasNaNs());
        return s;
    }


    void ToXYZ(float xyz[3]) const
    {
        RGBToXYZ(&m_data[0], xyz);
    }


    static Spectrum FromXYZ(const float xyz[3])
    {
        Spectrum r;
        XYZToRGB(xyz, &r.m_data[0]);
        return r;
    }

    float IsBlack() const
    {
        for (int i = 0; i < 3; ++i)
            if (m_data[i] != 0.) return false;
        return true;
    }

    float y() const
    {
        const float YWeight[3] = { 0.212671f, 0.715160f, 0.072169f };
        return YWeight[0] * m_data[0] + YWeight[1] * m_data[1] + YWeight[2] * m_data[2];
    }

    void ToRGB(float *rgb) const
    {
        rgb[0] = m_data[0];
        rgb[1] = m_data[1];
        rgb[2] = m_data[2];
    }

	std::vector<float> m_data;

//	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};

#endif

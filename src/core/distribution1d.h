#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_DISTRIBUTION1D__
#define __RENDERMOON_CORE_DISTRIBUTION1D__


struct Distribution1D
{
    Distribution1D(const vector<float>& samples)
    {
		m_FunctionSamples = vector<float>(samples);	//copy plain float array into vector of same size
		m_cdf = vector<float>(samples.size()+1, 0.0f);	//array of n+1 value set to zero

        //
        //build CDF
        //

        //step 1 : sum on range [0..1]
		float delta = 1.0 / m_FunctionSamples.size();
		for (int i = 1; i < m_FunctionSamples.size() + 1; ++i)
		{
			float area = m_FunctionSamples[i - 1] * delta;
			m_cdf[i] = m_cdf[i - 1] + area;
		}

		m_FunctionIntegral = m_cdf.back();

        //step 2: normalize
		if (m_cdf.back() == 0.0f) //use uniform distribution if something goes wrong
		{
			for (int i = 1; i < m_FunctionSamples.size() + 1; ++i)
				m_cdf[i] = float(i) / m_FunctionIntegral;
		}
		else
		{
			//normalize area: divide each element (delta area) by total area (last cdf value)
			std::transform(m_cdf.begin(), m_cdf.end(), m_cdf.begin(), std::bind2nd(std::multiplies<float>(), 1.0 / m_FunctionIntegral));
		}
    }

    ~Distribution1D()
    {

    }

    float SampleContinuous(float u, float *pdf, int *off = NULL) const
    {

		int offset = SampleDiscrete(u, pdf);

        if (off) *off = offset;
//        Assert(offset < count);
//        Assert(u >= cdf[offset] && u < cdf[offset+1]);

        // Compute offset along CDF segment
        float du = (u - m_cdf[offset]) / (m_cdf[offset+1] - m_cdf[offset]);
//        Assert(!isnan(du));

        // Compute PDF for sampled offset
		if (pdf) *pdf = m_FunctionSamples[offset] / m_FunctionIntegral;

        // Return $x\in{}[0,1)$ corresponding to sample
        return (offset + du) / m_FunctionSamples.size();
    }

    int SampleDiscrete(float u, float *pdf) const
    {
		vector<float>::const_iterator  up = std::upper_bound(m_cdf.begin(), m_cdf.end(), u);	//find iterator for first element greater than u
		int offset = max(0, int(std::distance(m_cdf.begin(), up))-1);
		if (pdf)
			*pdf = m_FunctionSamples[offset] / (m_FunctionIntegral * m_FunctionSamples.size());
        return offset;
    }

private:
	vector<float> 	m_FunctionSamples;
	vector<float> 	m_cdf;
	float 			m_FunctionIntegral;
};

#endif
#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_DISTRIBUTION1D__
#define __RENDERMOON_CORE_DISTRIBUTION1D__


struct Distribution1D
{
    Distribution1D(const vector<float>& f)
    {
		func = vector<float>(f);	//copy plain float array into vector of same size
		cdf = vector<float>(f.size()+1, 0.0f);	//array of n+1 value set to zero

        //
        //build CDF
        //

        //step 1 : sum on range [0..1]
		float delta = 1.0 / func.size();
		for (int i = 1; i < func.size() + 1; ++i)
		{
			float area = func[i - 1] * delta;
			cdf[i] = cdf[i - 1] + area;
		}

		function_integral = cdf.back();
        //step 2: normalize
		if (cdf.back() == 0.0f) //use uniform distribution if something goes wrong
		{
			for (int i = 1; i < func.size() + 1; ++i)
				cdf[i] = float(i) / function_integral;
		}
		else
		{
			//normalize area: divide each element (delta area) by total area (last cdf value)
			std::transform(cdf.begin(), cdf.end(), cdf.begin(), std::bind2nd(std::multiplies<float>(), 1.0 / cdf.back()));
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
        float du = (u - cdf[offset]) / (cdf[offset+1] - cdf[offset]);
//        Assert(!isnan(du));

        // Compute PDF for sampled offset
		if (pdf) *pdf = func[offset] / function_integral;

        // Return $x\in{}[0,1)$ corresponding to sample
        return (offset + du) / func.size();
        return 0;
    }

    int SampleDiscrete(float u, float *pdf) const
    {
		vector<float>::const_iterator  up = std::upper_bound(cdf.begin(), cdf.end(), u);	//find iterator for first element greater than u
		int offset = max(0, int(std::distance(cdf.begin(), up))-1);
//        Assert(offset < count);
//        Assert(u >= cdf[offset] && u < cdf[offset+1]);
		if (pdf) *pdf = func[offset] / (function_integral * func.size());
        return offset;
    }

private:
	vector<float> func;
	vector<float> cdf;
	float function_integral;
};

#endif
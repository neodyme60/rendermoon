#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_DISTRIBUTION1D__
#define __RENDERMOON_CORE_DISTRIBUTION1D__


struct Distribution1D
{
    Distribution1D(const float *f, int n)
    {
        count = n;
        func = new float[n];
        memcpy(func, f, n*sizeof(float));
        cdf = new float[n+1];

        cdf[0] = 0.;
        for (int i = 1; i < count+1; ++i)
            cdf[i] = cdf[i-1] + func[i-1] / n;

        funcInt = cdf[count];
        if (funcInt == 0.f)
        {
            for (int i = 1; i < n+1; ++i)
                cdf[i] = float(i) / float(n);
        }
        else
        {
            for (int i = 1; i < n+1; ++i)
                cdf[i] /= funcInt;
        }
    }

    ~Distribution1D()
    {
        delete[] func;
        delete[] cdf;
    }

    float SampleContinuous(float u, float *pdf, int *off = NULL) const
    {
        // Find surrounding CDF segments and _offset_
        float *ptr = std::upper_bound(cdf, cdf+count+1, u);
        int offset = max(0, int(ptr-cdf-1));
        if (off) *off = offset;
//        Assert(offset < count);
//        Assert(u >= cdf[offset] && u < cdf[offset+1]);

        // Compute offset along CDF segment
        float du = (u - cdf[offset]) / (cdf[offset+1] - cdf[offset]);
//        Assert(!isnan(du));

        // Compute PDF for sampled offset
        if (pdf) *pdf = func[offset] / funcInt;

        // Return $x\in{}[0,1)$ corresponding to sample
        return (offset + du) / count;
    }

    int SampleDiscrete(float u, float *pdf) const
    {
        // Find surrounding CDF segments and _offset_
        float *ptr = std::upper_bound(cdf, cdf+count+1, u);
        int offset = max(0, int(ptr-cdf-1));
//        Assert(offset < count);
//        Assert(u >= cdf[offset] && u < cdf[offset+1]);
        if (pdf) *pdf = func[offset] / (funcInt * count);
        return offset;
    }
private:
    friend struct Distribution2D;
    // Distribution1D Private Data
    float *func, *cdf;
    float funcInt;
    int count;
};

#endif
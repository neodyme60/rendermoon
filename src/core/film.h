#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CORE_FILM__
#define __RENDERMOON_CORE_FILM__

class Spectrum;

class Film
{
public:
    // Film Interface
    Film(int width, int height) : m_width(width), m_height(height) { }
    virtual ~Film() {}
/*
    virtual void Splat(const CameraSample &sample, const Spectrum &L) = 0;
    virtual void GetSampleExtent(int *xstart, int *xend, int *ystart, int *yend) const = 0;
    virtual void GetPixelExtent(int *xstart, int *xend, int *ystart, int *yend) const = 0;
*/
    virtual void AddSample(const CameraSample &sample, const Spectrum &L) = 0;
    virtual void WriteImage(float splatScale = 1.f) = 0;
    virtual void UpdateDisplay(int x0, int y0, int x1, int y1, float splatScale = 1.f);

    int GetWidth() const;
    int GetHeight() const;
protected:
    const int m_width, m_height;
};

#endif

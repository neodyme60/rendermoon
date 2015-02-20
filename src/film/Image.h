#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_FILM_IMAGE__
#define __RENDERMOON_FILM_IMAGE__

#include <string>

class Image : public Film
{
public:
    Image(int width, int height, std::string filename);
    virtual ~Image() {}


    void AddSample(const CameraSample &sample, const Spectrum &L);

	void WriteImage(float splatScale = 1.f);

	int *data;
	std::string m_filename;
};


#endif

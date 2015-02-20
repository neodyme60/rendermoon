#include <rendermoon.h>

Image::Image(int width, int height, std::string filename) : Film(width, height)
{
	data = new int[width*height];
	m_filename = filename;
}

// 32 bit image
typedef struct
{
    int width, height;
    int* data;
} RBitmap;

int write_truecolor_tga( RBitmap* data, std::string filename)
{
	FILE *fp = fopen(filename.c_str(), "wb+");
    if (fp == NULL) return 0;

// The image header
    char header[ 18 ] = { 0 }; // char = byte
    header[ 2 ] = 2; // truecolor
    header[ 12 ] = data->width & 0xFF;
    header[ 13 ] = (data->width >> 8) & 0xFF;
    header[ 14 ] = data->height & 0xFF;
    header[ 15 ] = (data->height >> 8) & 0xFF;
    header[ 16 ] = 24; // bits per pixel

    fwrite((const char*)&header, 1, sizeof(header), fp);

// The image data is stored bottom-to-top, left-to-right
    for (int y = data->height -1; y >= 0; y--)
        for (int x = 0; x < data->width; x++)
        {
            char b = (data->data[x+(y*data->width)] & 0x0000FF);
            char g = (data->data[x+(y*data->width)] & 0x00FF00) >> 8;
            char r = (data->data[x+(y*data->width)] & 0xFF0000) >> 16;
            putc((int)(b & 0xFF),fp);
            putc((int)(g & 0xFF),fp);
            putc((int)(r & 0xFF),fp);
        }

// The file footer
    static const char footer[ 26 ] =
            "\0\0\0\0" // no extension area
                    "\0\0\0\0" // no developer directory
                    "TRUEVISION-XFILE" // yep, this is a TGA file
                    ".";
    fwrite((const char*)&footer, 1, sizeof(footer), fp);

    fclose(fp);
    return 1;
}

void Image::WriteImage(float splatScale)
{
    RBitmap bitmap = RBitmap();
    bitmap.width = m_width;
    bitmap.height = m_height;
    bitmap.data = data;
    write_truecolor_tga(&bitmap, m_filename);
}

void Image::AddSample(const CameraSample &sample, const Spectrum &L)
{
	int r = (int)Clamp(pow(L.m_data[0], 1.0/2.2)*255.0f, 0.0f, 255.0f);
	int g = (int)Clamp(pow(L.m_data[1], 1.0/2.2)*255.0f, 0.0f, 255.0f);
	int b = (int)Clamp(pow(L.m_data[2], 1.0/2.2)*255.0f, 0.0f, 255.0f);

	data[sample.imageX+sample.imageY*m_width] = (r<<16) + (g<<8) + b;
}

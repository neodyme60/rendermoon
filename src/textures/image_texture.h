#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_TEXTURE_IMAGE_TEXTURE__
#define __RENDERMOON_TEXTURE_IMAGE_TEXTURE__

#include <core/mip_map.h>

struct TexInfo
{
    TexInfo(const string &f, bool dt, float ma, ImageWrap wm, float sc, float ga) : filename(f), doTrilinear(dt), maxAniso(ma), wrapMode(wm), scale(sc), gamma(ga) { }
    string filename;
    bool doTrilinear;
    float maxAniso;
    ImageWrap wrapMode;
    float scale, gamma;
    bool operator<(const TexInfo &t2) const
    {
        if (filename != t2.filename) return filename < t2.filename;
        if (doTrilinear != t2.doTrilinear) return doTrilinear < t2.doTrilinear;
        if (maxAniso != t2.maxAniso) return maxAniso < t2.maxAniso;
        if (scale != t2.scale) return scale < t2.scale;
        if (gamma != t2.gamma) return gamma < t2.gamma;
        return wrapMode < t2.wrapMode;
    }
};

template <typename Tmemory, typename Treturn>
class ImageTexture : public Texture<Treturn>
{
public:
    ImageTexture(TextureMapping2D *m, const string &filename, bool doTri, float maxAniso, ImageWrap wm, float scale, float gamma);
    Treturn Evaluate(const DifferentialGeometry &) const;
    ~ImageTexture();
    /*
    static void ClearCache()
    {
        typename std::map<TexInfo, MIPMap<Tmemory> *>::iterator iter;
        iter = textures.begin();
        while (iter != textures.end()) {
            delete iter->second;
            ++iter;
        }
        textures.erase(textures.begin(), textures.end());
    }
    */
private:
    // ImageTexture Private Methods
  //  static MIPMap<Tmemory> *GetTexture(const string &filename, bool doTrilinear, float maxAniso, ImageWrap wm, float scale, float gamma);
    /*
    static void convertIn(const Spectrum &from, Spectrum *to, float scale, float gamma)
    {
        *to = pow(from * scale, gamma);
    }
    static void convertIn(const Spectrum &from, float *to, float scale, float gamma)
    {
        *to = powf(scale * from.y(), gamma);
    }
    static void convertOut(const Spectrum &from, Spectrum *to)
    {
        float rgb[3];
        from.ToRGB(rgb);
        *to = Spectrum::FromRGB(rgb);
    }
    static void convertOut(float from, float *to)
    {
        *to = from;
    }
*/
    // ImageTexture Private Data
//    MIPMap<Tmemory> *mipmap;
    TextureMapping2D *mapping;
 //   static std::map<TexInfo, MIPMap<Tmemory> *> textures;
};



#endif

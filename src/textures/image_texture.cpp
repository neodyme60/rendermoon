#include <rendermoon.h>
/*
// ImageTexture Method Definitions
template <typename Tmemory, typename Treturn>
ImageTexture<Tmemory, Treturn>::ImageTexture(TextureMapping2D *m, const string &filename, bool doTrilinear, float maxAniso, ImageWrap wrapMode, float scale, float gamma)
{
    mapping = m;
    mipmap = GetTexture(filename, doTrilinear, maxAniso, wrapMode, scale, gamma);
}


template <typename Tmemory, typename Treturn>
ImageTexture<Tmemory, Treturn>::~ImageTexture()
{
    delete mapping;
}


template <typename Tmemory, typename Treturn> MIPMap<Tmemory> *
ImageTexture<Tmemory, Treturn>::GetTexture(const string &filename,
        bool doTrilinear, float maxAniso, ImageWrap wrap,
        float scale, float gamma) {
    // Look for texture in texture cache
    TexInfo texInfo(filename, doTrilinear, maxAniso, wrap, scale, gamma);
    if (textures.find(texInfo) != textures.end())
        return textures[texInfo];
    int width, height;
    RGBSpectrum *texels = ReadImage(filename, &width, &height);
    MIPMap<Tmemory> *ret = NULL;
    if (texels) {
        // Convert texels to type _Tmemory_ and create _MIPMap_
        Tmemory *convertedTexels = new Tmemory[width*height];
        for (int i = 0; i < width*height; ++i)
            convertIn(texels[i], &convertedTexels[i], scale, gamma);
        ret = new MIPMap<Tmemory>(width, height, convertedTexels, doTrilinear,
                maxAniso, wrap);
        delete[] texels;
        delete[] convertedTexels;
    }
    else {
        // Create one-valued _MIPMap_
        Tmemory *oneVal = new Tmemory[1];
        oneVal[0] = powf(scale, gamma);
        ret = new MIPMap<Tmemory>(1, 1, oneVal);
        delete[] oneVal;
    }
    textures[texInfo] = ret;
    PBRT_LOADED_IMAGE_MAP(const_cast<char *>(filename.c_str()), width, height, sizeof(Tmemory), ret);
    return ret;
}


template <typename Tmemory, typename Treturn>
std::map<TexInfo, MIPMap<Tmemory> *>
ImageTexture<Tmemory, Treturn>::textures;

template <typename Tmemory, typename Treturn> Treturn
ImageTexture<Tmemory,Treturn>::Evaluate(const DifferentialGeometry &dg) const
{
    float s, t, dsdx, dtdx, dsdy, dtdy;
    mapping->Map(dg, &s, &t, &dsdx, &dtdx, &dsdy, &dtdy);
    Tmemory mem = mipmap->Lookup(s, t, dsdx, dtdx, dsdy, dtdy);
    Treturn ret;
    convertOut(mem, &ret);
    return ret;
}
*/
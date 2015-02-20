#if defined(_MSC_VER)
#pragma once
#endif


#ifndef __RENDERMOON_CORE_PARAMSET__
#define __RENDERMOON_CORE_PARAMSET__

#include <string>
#include <map>

class Point;
class Vec3;
class Normal;
class Spectrum;
template <typename T> struct ParamSetItem;
template <typename T> class Reference;
using namespace std;

class ParamSet
{
public:
    // ParamSet Public Methods
    ParamSet() { }
    void AddFloat(const string &, const float *, int nItems = 1);
    void AddInt(const string &, const int *, int nItems);
    void AddBool(const string &, const bool *, int nItems);
    void AddPoint(const string &, const Point *, int nItems);
    void AddVector(const string &, const Vec3 *, int nItems);
    void AddNormal(const string &, const Normal *, int nItems);
    void AddString(const string &, const string *, int nItems);
    void AddTexture(const string &, const string &);
    void AddRGBSpectrum(const string &, const float *, int nItems);
    void AddXYZSpectrum(const string &, const float *, int nItems);
/*
    void AddBlackbodySpectrum(const string &, const float *, int nItems);
    void AddSampledSpectrumFiles(const string &, const char **, int nItems);
    void AddSampledSpectrum(const string &, const float *, int nItems);
*/
    bool EraseInt(const string &);
    bool EraseBool(const string &);
    bool EraseFloat(const string &);
    bool ErasePoint(const string &);
    bool EraseVector(const string &);
    bool EraseNormal(const string &);
    bool EraseSpectrum(const string &);
    bool EraseString(const string &);
    bool EraseTexture(const string &);
    float FindOneFloat(const string &, float d) const;
    int FindOneInt(const string &, int d) const;
    bool FindOneBool(const string &, bool d) const;
    Point FindOnePoint(const string &, const Point &d) const;
    Vec3 FindOneVector(const string &, const Vec3 &d) const;
    Normal FindOneNormal(const string &, const Normal &d) const;
    Spectrum FindOneSpectrum(const string &, const Spectrum &d) const;
    string FindOneString(const string &, const string &d) const;
//    string FindOneFilename(const string &, const string &d) const;
    string FindTexture(const string &) const;
    const float *FindFloat(const string &, int *nItems) const;
    const int *FindInt(const string &, int *nItems) const;
    const bool *FindBool(const string &, int *nItems) const;
    const Point *FindPoint(const string &, int *nItems) const;
    const Vec3 *FindVector(const string &, int *nItems) const;
    const Normal *FindNormal(const string &, int *nItems) const;
    const Spectrum *FindSpectrum(const string &, int *nItems) const;
    const string *FindString(const string &, int *nItems) const;
    void ReportUnused() const;
    void Clear();
//    string ToString() const;

private:
    // ParamSet Private Data
    vector<Reference<ParamSetItem<bool> > >     bools;
    vector<Reference<ParamSetItem<int> > >      ints;
    vector<Reference<ParamSetItem<float> > >    floats;
    vector<Reference<ParamSetItem<Point> > >    points;
    vector<Reference<ParamSetItem<Vec3> > >     vectors;
    vector<Reference<ParamSetItem<Normal> > >   normals;
    vector<Reference<ParamSetItem<Spectrum> > > spectra;
    vector<Reference<ParamSetItem<string> > >   strings;
    vector<Reference<ParamSetItem<string> > >   textures;
    static map<string, Spectrum> cachedSpectra;
};

#endif

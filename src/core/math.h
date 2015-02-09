#ifndef __RENDERMOON_CORE_MATH__
#define __RENDERMOON_CORE_MATH__

class Point;
class Normal;

// Geometry Declarations
class Vec3 
{
public:
    // Vector Public Methods
    Vec3() { x = y = z = 0.f; }
    Vec3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) 
	{
//        Assert(!HasNaNs());
    }
    bool HasNaNs() const { return isnan(x) || isnan(y) || isnan(z); }
    explicit Vec3(const Point &p);
#ifndef NDEBUG
    // The default versions of these are fine for release builds; for debug
    // we define them so that we can add the Assert checks.
    Vec3(const Vec3 &v) {
//        Assert(!v.HasNaNs());
        x = v.x; y = v.y; z = v.z;
    }
    
    Vec3 &operator=(const Vec3 &v) {
//        Assert(!v.HasNaNs());
        x = v.x; y = v.y; z = v.z;
        return *this;
    }
#endif // !NDEBUG
    Vec3 operator+(const Vec3 &v) const {
 //       Assert(!v.HasNaNs());
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator*(const Vec3 &v) const {
 //       Assert(!v.HasNaNs());
        return Vec3(x * v.x, y * v.y, z * v.z);
    }
    
    Vec3& operator+=(const Vec3 &v) {
//        Assert(!v.HasNaNs());
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    Vec3 operator-(const Vec3 &v) const {
 //       Assert(!v.HasNaNs());
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    
    Vec3& operator-=(const Vec3 &v) {
 //       Assert(!v.HasNaNs());
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    Vec3 operator*(float f) const { return Vec3(f*x, f*y, f*z); }
    
    Vec3 &operator*=(float f) {
  //      Assert(!isnan(f));
        x *= f; y *= f; z *= f;
        return *this;
    }
    Vec3 operator/(float f) const {
//        Assert(f != 0);
        float inv = 1.f / f;
        return Vec3(x * inv, y * inv, z * inv);
    }
    
    Vec3 &operator/=(float f) {
 //       Assert(f != 0);
        float inv = 1.f / f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    Vec3 operator-() const { return Vec3(-x, -y, -z); }
    float operator[](int i) const {
  //      Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    
    float &operator[](int i) {
   //     Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    float LengthSquared() const { return x*x + y*y + z*z; }
    float Length() const { return sqrtf(LengthSquared()); }
    explicit Vec3(const Normal &n);

    bool operator==(const Vec3 &v) const {
        return x == v.x && y == v.y && z == v.z;
    }
    bool operator!=(const Vec3 &v) const {
        return x != v.x || y != v.y || z != v.z;
    }

    // Vector Public Data
    float x, y, z;
};


class Point 
{
public:
    // Point Public Methods
    Point() { x = y = z = 0.f; }
    Point(float xx, float yy, float zz)
        : x(xx), y(yy), z(zz) {
    //    Assert(!HasNaNs());
    }
#ifndef NDEBUG
    Point(const Point &p) {
   //     Assert(!p.HasNaNs());
        x = p.x; y = p.y; z = p.z;
    }
    
    Point &operator=(const Point &p) {
  //      Assert(!p.HasNaNs());
        x = p.x; y = p.y; z = p.z;
        return *this;
    }
#endif // !NDEBUG
    Point operator+(const Vec3 &v) const {
   //     Assert(!v.HasNaNs());
        return Point(x + v.x, y + v.y, z + v.z);
    }
    
    Point &operator+=(const Vec3 &v) {
   //     Assert(!v.HasNaNs());
        x += v.x; y += v.y; z += v.z;
        return *this;
    }
    Vec3 operator-(const Point &p) const {
 //       Assert(!p.HasNaNs());
        return Vec3(x - p.x, y - p.y, z - p.z);
    }
    
    Point operator-(const Vec3 &v) const {
  //      Assert(!v.HasNaNs());
        return Point(x - v.x, y - v.y, z - v.z);
    }
    
    Point &operator-=(const Vec3 &v) {
   //     Assert(!v.HasNaNs());
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    }
    Point &operator+=(const Point &p) {
   //     Assert(!p.HasNaNs());
        x += p.x; y += p.y; z += p.z;
        return *this;
    }
    Point operator+(const Point &p) const {
  //      Assert(!p.HasNaNs());
        return Point(x + p.x, y + p.y, z + p.z);
    }
    Point operator* (float f) const {
        return Point(f*x, f*y, f*z);
    }
    Point &operator*=(float f) {
        x *= f; y *= f; z *= f;
        return *this;
    }
    Point operator/ (float f) const {
        float inv = 1.f/f;
        return Point(inv*x, inv*y, inv*z);
    }
    Point &operator/=(float f) {
        float inv = 1.f/f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    float operator[](int i) const {
//        Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    
    float &operator[](int i) {
   //     Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    bool HasNaNs() const {
        return isnan(x) || isnan(y) || isnan(z);
    }

    bool operator==(const Point &p) const {
        return x == p.x && y == p.y && z == p.z;
    }
    bool operator!=(const Point &p) const {
        return x != p.x || y != p.y || z != p.z;
    }

    // Point Public Data
    float x, y, z;
};


class Normal 
{
public:
    // Normal Public Methods
    Normal() { x = y = z = 0.f; }
    Normal(float xx, float yy, float zz)
        : x(xx), y(yy), z(zz) {
  //      Assert(!HasNaNs());
    }

    Normal operator-() const {
        return Normal(-x, -y, -z);
    }
    Normal operator+ (const Normal &n) const {
  //      Assert(!n.HasNaNs());
        return Normal(x + n.x, y + n.y, z + n.z);
    }
    
    Normal& operator+=(const Normal &n) {
  //      Assert(!n.HasNaNs());
        x += n.x; y += n.y; z += n.z;
        return *this;
    }
    Normal operator- (const Normal &n) const {
   //     Assert(!n.HasNaNs());
        return Normal(x - n.x, y - n.y, z - n.z);
    }
    
    Normal& operator-=(const Normal &n) {
  //      Assert(!n.HasNaNs());
        x -= n.x; y -= n.y; z -= n.z;
        return *this;
    }
    bool HasNaNs() const {
        return isnan(x) || isnan(y) || isnan(z);
    }
    Normal operator*(float f) const {
        return Normal(f*x, f*y, f*z);
    }
    
    Normal &operator*=(float f) {
        x *= f; y *= f; z *= f;
        return *this;
    }
    Normal operator/(float f) const {
  //      Assert(f != 0);
        float inv = 1.f/f;
        return Normal(x * inv, y * inv, z * inv);
    }
    
    Normal &operator/=(float f) {
   //     Assert(f != 0);
        float inv = 1.f/f;
        x *= inv; y *= inv; z *= inv;
        return *this;
    }
    float LengthSquared() const { return x*x + y*y + z*z; }
    float Length() const        { return sqrtf(LengthSquared()); }
    
#ifndef NDEBUG
    Normal(const Normal &n) {
    //    Assert(!n.HasNaNs());
        x = n.x; y = n.y; z = n.z;
    }
    
    Normal &operator=(const Normal &n) {
  //      Assert(!n.HasNaNs());
        x = n.x; y = n.y; z = n.z;
        return *this;
    }
#endif // !NDEBUG
    explicit Normal(const Vec3 &v)
      : x(v.x), y(v.y), z(v.z) {
  //      Assert(!v.HasNaNs());
    }
    float operator[](int i) const {
  //      Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }
    
    float &operator[](int i) {
  //      Assert(i >= 0 && i <= 2);
        return (&x)[i];
    }

    bool operator==(const Normal &n) const {
        return x == n.x && y == n.y && z == n.z;
    }
    bool operator!=(const Normal &n) const {
        return x != n.x || y != n.y || z != n.z;
    }

    // Normal Public Data
    float x, y, z;
};


inline bool Quadratic(float A, float B, float C, float *t0, float *t1) {
    // Find quadratic discriminant
    float discrim = B * B - 4.f * A * C;
    if (discrim < 0.) return false;
    float rootDiscrim = sqrtf(discrim);

    // Compute quadratic _t_ values
    float q;
    if (B < 0) q = -.5f * (B - rootDiscrim);
    else       q = -.5f * (B + rootDiscrim);
    *t0 = q / A;
    *t1 = C / q;
    if (*t0 > *t1) swap(*t0, *t1);
    return true;
}


// Geometry Inline Functions
inline Vec3::Vec3(const Point &p)
    : x(p.x), y(p.y), z(p.z) {
 //   Assert(!HasNaNs());
}


inline Vec3 operator*(float f, const Vec3 &v) { return v*f; }
inline float Dot(const Vec3 &v1, const Vec3 &v2) {
//    Assert(!v1.HasNaNs() && !v2.HasNaNs());
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}


inline float AbsDot(const Vec3 &v1, const Vec3 &v2) {
 //   Assert(!v1.HasNaNs() && !v2.HasNaNs());
    return fabsf(Dot(v1, v2));
}


inline Vec3 Cross(const Vec3 &v1, const Vec3 &v2) {
 //   Assert(!v1.HasNaNs() && !v2.HasNaNs());
    float v1x = v1.x, v1y = v1.y, v1z = v1.z;
    float v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vec3((v1y * v2z) - (v1z * v2y),
                  (v1z * v2x) - (v1x * v2z),
                  (v1x * v2y) - (v1y * v2x));
}


inline Vec3 Cross(const Vec3 &v1, const Normal &v2) {
 //   Assert(!v1.HasNaNs() && !v2.HasNaNs());
    float v1x = v1.x, v1y = v1.y, v1z = v1.z;
    float v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vec3((v1y * v2z) - (v1z * v2y),
                  (v1z * v2x) - (v1x * v2z),
                  (v1x * v2y) - (v1y * v2x));
}


inline Vec3 Cross(const Normal &v1, const Vec3 &v2) {
  //  Assert(!v1.HasNaNs() && !v2.HasNaNs());
    float v1x = v1.x, v1y = v1.y, v1z = v1.z;
    float v2x = v2.x, v2y = v2.y, v2z = v2.z;
    return Vec3((v1y * v2z) - (v1z * v2y),
                  (v1z * v2x) - (v1x * v2z),
                  (v1x * v2y) - (v1y * v2x));
}


inline Vec3 Normalize(const Vec3 &v) { return v / v.Length(); }



inline Point operator*(float f, const Point &p) {
  //  Assert(!p.HasNaNs());
    return p*f;
}


inline Normal operator*(float f, const Normal &n) {
    return Normal(f*n.x, f*n.y, f*n.z);
}


inline Normal Normalize(const Normal &n) {
    return n / n.Length();
}


inline Vec3::Vec3(const Normal &n)
  : x(n.x), y(n.y), z(n.z) {
 //   Assert(!n.HasNaNs());
}


inline float Dot(const Normal &n1, const Vec3 &v2) {
//    Assert(!n1.HasNaNs() && !v2.HasNaNs());
    return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
}


inline float Dot(const Vec3 &v1, const Normal &n2) {
//    Assert(!v1.HasNaNs() && !n2.HasNaNs());
    return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}


inline float Dot(const Normal &n1, const Normal &n2) {
//    Assert(!n1.HasNaNs() && !n2.HasNaNs());
    return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}


inline float AbsDot(const Normal &n1, const Vec3 &v2) {
  //  Assert(!n1.HasNaNs() && !v2.HasNaNs());
    return fabsf(n1.x * v2.x + n1.y * v2.y + n1.z * v2.z);
}


inline float AbsDot(const Vec3 &v1, const Normal &n2) {
  //  Assert(!v1.HasNaNs() && !n2.HasNaNs());
    return fabsf(v1.x * n2.x + v1.y * n2.y + v1.z * n2.z);
}


inline float AbsDot(const Normal &n1, const Normal &n2) {
 //   Assert(!n1.HasNaNs() && !n2.HasNaNs());
    return fabsf(n1.x * n2.x + n1.y * n2.y + n1.z * n2.z);
}

#endif

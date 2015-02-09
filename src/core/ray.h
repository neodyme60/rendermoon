#ifndef __RENDERMOON_CORE_RAY__
#define __RENDERMOON_CORE_RAY__

class Ray
{
public:
    Point   m_origin;
    Vec3    m_direction;
    float   mint, maxt;
    float   m_time;
    int     m_depth;
public:
    Ray() : mint(0.f), maxt(rm_infintiy), m_time(0.f), m_depth(0) { }
    Ray(Point o, Vec3 d, float start, float end = rm_infintiy, float t = 0.0f, int depth = 0) : m_origin(o), m_direction(d), mint(start), maxt(end), m_time(t), m_depth(depth) { }

    Point GetOrigin() const;
    Vec3 GetDirection() const;

    Point& GetOrigin();
    Vec3& GetDirection();

    Point GetAt(float t) const;

    float GetTime() const;
    void SetTime(float t);

    float GetMaxt() const;
    void SetMaxt(float t);

    float GetMint() const;
    void SetMint(float t);

    void SetDirection(Vec3 d);
    void SetOrigin(Point o);

    int GetDepth() const;
    void SetDepth(int d);

    virtual ~Ray() {}

    friend ostream& operator<<(ostream& os, const Ray& dt);

};

#endif
#if defined(_MSC_VER)
#pragma once
#endif

#ifndef __RENDERMOON_CORE_TRANSFORM__
#define __RENDERMOON_CORE_TRANSFORM__

class Ray;
class BBox;


struct Mat4
{
    // Matrix4x4 Public Methods
    Mat4() {
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.f;
        m[0][1] = m[0][2] = m[0][3] = m[1][0] =
             m[1][2] = m[1][3] = m[2][0] = m[2][1] = m[2][3] =
             m[3][0] = m[3][1] = m[3][2] = 0.f;
    }
    Mat4(float mat[4][4]);
    Mat4(float t00, float t01, float t02, float t03,
              float t10, float t11, float t12, float t13,
              float t20, float t21, float t22, float t23,
              float t30, float t31, float t32, float t33);
    bool operator==(const Mat4 &m2) const {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (m[i][j] != m2.m[i][j]) return false;
        return true;
    }
    bool operator!=(const Mat4 &m2) const {
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                if (m[i][j] != m2.m[i][j]) return true;
        return false;
    }
    friend Mat4 Transpose(const Mat4 &);

    static Mat4 Mul(const Mat4 &m1, const Mat4 &m2) {
        Mat4 r;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                r.m[i][j] = m1.m[i][0] * m2.m[0][j] +
                            m1.m[i][1] * m2.m[1][j] +
                            m1.m[i][2] * m2.m[2][j] +
                            m1.m[i][3] * m2.m[3][j];
        return r;
    }
    friend Mat4 Inverse(const Mat4 &);
    float m[4][4];
};


class Transform
{
protected:
public:
    Mat4 m, mInv;

    Transform();
    Transform(const Mat4& t);
    Transform(const Mat4& t, const Mat4& t_inv);

    Transform GetInverse() const;

	BBox TransformBBox(const BBox &b) const;

	Normal TransformNormal(const Normal &pt) const;
    void TransformNormal(const Normal &pt, Normal *ptrans) const;

    Point TransformPoint(const Point &pt) const;
    void TransformPoint(const Point &pt, Point *ptrans) const;

    Vec3 TransformVec3(const Vec3 &v) const;
    void TransformVec3(const Vec3 &v, Vec3 *vt) const;
/*
    Normal operator()(const Normal &) const;
    void operator()(const Normal &, Normal *nt) const;
    Ray operator()(const Ray &r) const;
*/
    void TransformRay(const Ray &r, Ray *rt) const;

    Transform operator*(const Transform &t2) const;

    static Transform CreateLookAt(const Point &pos, const Point &lookat, const Vec3 &up);
    static Transform CreateScale(float x, float y, float z);
    static Transform CreateScale(Vec3 s);
    static Transform CreateRotate_x(float angle);
    static Transform CreateRotate_y(float angle);
    static Transform CreateRotate_z(float angle);
    static Transform CreateTranslate(const Vec3& t);
    static Transform CreateTranslate(float x, float y, float z);
    static Transform CreateOrthographic(float znear, float zfar);
    static Transform CreatePerspective(float fov, float znear, float zfar);

	

    virtual ~Transform() {}

//	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};


#endif

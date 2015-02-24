#include <rendermoon.h>


// BBox Method Definitions
BBox Union(const BBox &b, const Point &p) {
    BBox ret = b;
    ret.pMin.x = min(b.pMin.x, p.x);
    ret.pMin.y = min(b.pMin.y, p.y);
    ret.pMin.z = min(b.pMin.z, p.z);
    ret.pMax.x = max(b.pMax.x, p.x);
    ret.pMax.y = max(b.pMax.y, p.y);
    ret.pMax.z = max(b.pMax.z, p.z);
    return ret;
}


BBox Union(const BBox &b, const BBox &b2) {
    BBox ret;
    ret.pMin.x = min(b.pMin.x, b2.pMin.x);
    ret.pMin.y = min(b.pMin.y, b2.pMin.y);
    ret.pMin.z = min(b.pMin.z, b2.pMin.z);
    ret.pMax.x = max(b.pMax.x, b2.pMax.x);
    ret.pMax.y = max(b.pMax.y, b2.pMax.y);
    ret.pMax.z = max(b.pMax.z, b2.pMax.z);
    return ret;
}

Mat4::Mat4(float mat[4][4])
{
    memcpy(m, mat, 16*sizeof(float));
}

Mat4::Mat4(float t00, float t01, float t02, float t03,
                     float t10, float t11, float t12, float t13,
                     float t20, float t21, float t22, float t23,
                     float t30, float t31, float t32, float t33) {
    m[0][0] = t00; m[0][1] = t01; m[0][2] = t02; m[0][3] = t03;
    m[1][0] = t10; m[1][1] = t11; m[1][2] = t12; m[1][3] = t13;
    m[2][0] = t20; m[2][1] = t21; m[2][2] = t22; m[2][3] = t23;
    m[3][0] = t30; m[3][1] = t31; m[3][2] = t32; m[3][3] = t33;
}

Mat4 Transpose(const Mat4 &m)
{
   return Mat4(m.m[0][0], m.m[1][0], m.m[2][0], m.m[3][0],
                m.m[0][1], m.m[1][1], m.m[2][1], m.m[3][1],
                m.m[0][2], m.m[1][2], m.m[2][2], m.m[3][2],
                m.m[0][3], m.m[1][3], m.m[2][3], m.m[3][3]);
}

Mat4 Inverse(const Mat4 &m)
{
    int indxc[4], indxr[4];
    int ipiv[4] = { 0, 0, 0, 0 };
    float minv[4][4];
    memcpy(minv, m.m, 4*4*sizeof(float));
    for (int i = 0; i < 4; i++)
    {
        int irow = -1, icol = -1;
        float big = 0.;
        // Choose pivot
        for (int j = 0; j < 4; j++)
        {
            if (ipiv[j] != 1) {
                for (int k = 0; k < 4; k++) {
                    if (ipiv[k] == 0) {
                        if (fabsf(minv[j][k]) >= big) {
                            big = float(fabsf(minv[j][k]));
                            irow = j;
                            icol = k;
                        }
                    }
                    else if (ipiv[k] > 1)
					{
                     //   Error("Singular matrix in MatrixInvert");
					}
                }
            }
        }
        ++ipiv[icol];
        // Swap rows _irow_ and _icol_ for pivot
        if (irow != icol) {
            for (int k = 0; k < 4; ++k)
                swap(minv[irow][k], minv[icol][k]);
        }
        indxr[i] = irow;
        indxc[i] = icol;
        if (minv[icol][icol] == 0.)
		{
         //   Error("Singular matrix in MatrixInvert");
		}
        // Set $m[icol][icol]$ to one by scaling row _icol_ appropriately
        float pivinv = 1.f / minv[icol][icol];
        minv[icol][icol] = 1.f;
        for (int j = 0; j < 4; j++)
            minv[icol][j] *= pivinv;

        // Subtract this row from others to zero out their columns
        for (int j = 0; j < 4; j++) {
            if (j != icol) {
                float save = minv[j][icol];
                minv[j][icol] = 0;
                for (int k = 0; k < 4; k++)
                    minv[j][k] -= minv[icol][k]*save;
            }
        }
    }
    // Swap columns to reflect permutation
    for (int j = 3; j >= 0; j--) {
        if (indxr[j] != indxc[j]) {
            for (int k = 0; k < 4; k++)
                std::swap(minv[k][indxr[j]], minv[k][indxc[j]]);
        }
    }
    return Mat4(minv);
}

Transform::Transform()
{
    m = Mat4();
    mInv = Mat4();
}

Transform::Transform(const Mat4& m)
{
    this->m = m;
    this->mInv = Inverse(m);
}

Transform::Transform(const Mat4& m, const Mat4& mInv)
{
    this->m = m;
    this->mInv = mInv;
}

Transform Transform::GetInverse() const
{
    return Transform(mInv, m);
}

Transform Transform::operator*(const Transform &t2) const
{
//    Mat4 m1 = m *  t2.m;
//    Mat4 m2 = t2.mInv* mInv;
    Mat4 m1 = Mat4::Mul(m, t2.m);
    Mat4 m2 = Mat4::Mul(t2.mInv, mInv);
    return Transform(m1, m2);
}

BBox Transform::TransformBBox(const BBox &b) const 
{
	const Transform &M = *this;
	BBox ret(        M.TransformPoint(Point(b.pMin.x, b.pMin.y, b.pMin.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMax.x, b.pMin.y, b.pMin.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMin.x, b.pMax.y, b.pMin.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMin.x, b.pMin.y, b.pMax.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMin.x, b.pMax.y, b.pMax.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMax.x, b.pMax.y, b.pMin.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMax.x, b.pMin.y, b.pMax.z)));
	ret = Union(ret, M.TransformPoint(Point(b.pMax.x, b.pMax.y, b.pMax.z)));
	return ret;
}

Normal Transform::TransformNormal(const Normal &n) const
{
    float x = n.x, y = n.y, z = n.z;
    return Normal(
            mInv.m[0][0]*x + mInv.m[1][0]*y + mInv.m[2][0]*z,
            mInv.m[0][1]*x + mInv.m[1][1]*y + mInv.m[2][1]*z,
            mInv.m[0][2]*x + mInv.m[1][2]*y + mInv.m[2][2]*z);
}

void Transform::TransformNormal(const Normal &n, Normal *nt) const
{
    float x = n.x, y = n.y, z = n.z;
    nt->x = mInv.m[0][0] * x + mInv.m[1][0] * y + mInv.m[2][0] * z;
    nt->y = mInv.m[0][1] * x + mInv.m[1][1] * y + mInv.m[2][1] * z;
    nt->z = mInv.m[0][2] * x + mInv.m[1][2] * y + mInv.m[2][2] * z;
}

Point Transform::TransformPoint(const Point &pt) const
{
    float x = pt.x, y = pt.y, z = pt.z;
    float xp = m.m[0][0]*x + m.m[0][1]*y + m.m[0][2]*z + m.m[0][3];
    float yp = m.m[1][0]*x + m.m[1][1]*y + m.m[1][2]*z + m.m[1][3];
    float zp = m.m[2][0]*x + m.m[2][1]*y + m.m[2][2]*z + m.m[2][3];
    float wp = m.m[3][0]*x + m.m[3][1]*y + m.m[3][2]*z + m.m[3][3];
    //Assert(wp != 0);
    if (wp == 1.) return Point(xp, yp, zp);
    else          return Point(xp, yp, zp)/wp;

	/*
    float x = pt.x();
    float y = pt.y();
    float z = pt.z();
    float xp = m(0,0)*x + m(0,1)*y + m(0,2)*z + m(0,3);
    float yp = m(1,0)*x + m(1,1)*y + m(1,2)*z + m(1,3);
    float zp = m(2,0)*x + m(2,1)*y + m(2,2)*z + m(2,3);
    float wp = m(3,0)*x + m(3,1)*y + m(3,2)*z + m(3,3);
//    Assert(wp != 0);
    if (wp == 1.) return Point(xp, yp, zp);
    else          return Point(xp, yp, zp)/wp;*/
}


void Transform::TransformPoint(const Point &pt, Point *ptrans) const
{

    float x = pt.x, y = pt.y, z = pt.z;
    ptrans->x = m.m[0][0]*x + m.m[0][1]*y + m.m[0][2]*z + m.m[0][3];
    ptrans->y = m.m[1][0]*x + m.m[1][1]*y + m.m[1][2]*z + m.m[1][3];
    ptrans->z = m.m[2][0]*x + m.m[2][1]*y + m.m[2][2]*z + m.m[2][3];
    float w   = m.m[3][0]*x + m.m[3][1]*y + m.m[3][2]*z + m.m[3][3];
    if (w != 1.) *ptrans /= w;
/*
    float x = pt.x(), y = pt.y(), z = pt.z();
    ptrans->x() = m(0,0)*x + m(0,1)*y + m(0,2)*z + m(0,3);
    ptrans->y() = m(1,0)*x + m(1,1)*y + m(1,2)*z + m(1,3);
    ptrans->z() = m(2,0)*x + m(2,1)*y + m(2,2)*z + m(2,3);
    float w   = m(3,0)*x + m(3,1)*y + m(3,2)*z + m(3,3);
    if (w != 1.0) *ptrans /= w;
*/
}

Vec3 Transform::TransformVec3(const Vec3 &v) const
{
	/*
    float x = v.x(), y = v.y(), z = v.z();
    return Vec3(
            m(0,0)*x + m(0,1)*y + m(0,2)*z,
            m(1,0)*x + m(1,1)*y + m(1,2)*z,
            m(2,0)*x + m(2,1)*y + m(2,2)*z);
			*/

  float x = v.x, y = v.y, z = v.z;
  return Vec3(m.m[0][0]*x + m.m[0][1]*y + m.m[0][2]*z,
                m.m[1][0]*x + m.m[1][1]*y + m.m[1][2]*z,
                m.m[2][0]*x + m.m[2][1]*y + m.m[2][2]*z);
}

void Transform::TransformVec3(const Vec3 &v, Vec3 *vt) const
{
	/*
    float x = v.x(), y = v.y(), z = v.z();
    vt->x() = m(0,0)*x + m(0,1)*y + m(0,2)*z;
    vt->y() = m(1,0)*x + m(1,1)*y + m(1,2)*z;
    vt->z() = m(2,0)*x + m(2,1)*y + m(2,2)*z;
	*/
  float x = v.x, y = v.y, z = v.z;
  vt->x = m.m[0][0] * x + m.m[0][1] * y + m.m[0][2] * z;
  vt->y = m.m[1][0] * x + m.m[1][1] * y + m.m[1][2] * z;
  vt->z = m.m[2][0] * x + m.m[2][1] * y + m.m[2][2] * z;
}
/*
Normal Transform::operator()(const Normal &n) const
{
    float x = n.x, y = n.y, z = n.z;
    return Normal(
            mInv.m[0][0]*x + mInv.m[1][0]*y + mInv.m[2][0]*z,
            mInv.m[0][1]*x + mInv.m[1][1]*y + mInv.m[2][1]*z,
            mInv.m[0][2]*x + mInv.m[1][2]*y + mInv.m[2][2]*z);
}

void Transform::operator()(const Normal &n, Normal *nt) const
{
    float x = n.x, y = n.y, z = n.z;
    nt->x = mInv.m[0][0] * x + mInv.m[1][0] * y + mInv.m[2][0] * z;
    nt->y = mInv.m[0][1] * x + mInv.m[1][1] * y + mInv.m[2][1] * z;
    nt->z = mInv.m[0][2] * x + mInv.m[1][2] * y + mInv.m[2][2] * z;
}

Ray Transform::operator()(const Ray &r) const
{
    Ray ret = r;
    (*this)(ret.GetOrigin(), &ret.GetOrigin());
    (*this)(ret.GetDirection(), &ret.GetDirection());
    return ret;
}
*/

void Transform::TransformRay(const Ray &r, Ray *rt) const
{
    (*this).TransformPoint(r.GetOrigin(), &rt->GetOrigin());
    (*this).TransformVec3(r.GetDirection(), &rt->GetDirection());
    if (rt != &r)
    {
        rt->SetMint(r.GetMint());
        rt->SetMaxt(r.GetMaxt());
        rt->SetTime(r.GetTime());
        rt->SetDepth(r.GetDepth());
    }
}


Transform Transform::CreateScale(float x, float y, float z)
{
	/*
    Mat4 m = Mat4::Identity();
    m(0, 0) = x;
    m(1, 1) = y;
    m(2,2) = z;
    m(3,3) = 1.0f;
    Mat4 mInv = Mat4::Identity();
    mInv(0, 0) = 1.0/x;
    mInv(1, 1) = 1.0/y;
    mInv(2,2) = 1.0/z;
    mInv(3,3) = 1.0f;
    return Transform(m, mInv);
*/
	    Mat4 m(x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, z, 0,
                0, 0, 0, 1);
    Mat4 minv(1.f/x,     0,     0,     0,
                   0,     1.f/y,     0,     0,
                   0,         0,     1.f/z, 0,
                   0,         0,     0,     1);
    return Transform(m, minv);
}

Transform Transform::CreateScale(Vec3 s)
{
    return Transform::CreateScale(s[0], s[1], s[2]);
}

Transform Transform::CreateRotate_x(float angle)
{
	/*
    float cosr = cosf(angle);
    float sinr = sinf(angle);

    Mat4 t = Mat4::Identity();
    t(1,1) = cosr;
    t(1,2) = -sinr;
    t(2,1) = sinr;
    t(2,2) = cosr;
    return Transform(t);
	*/
    float sin_t = sinf(Radians(angle));
    float cos_t = cosf(Radians(angle));
    Mat4 m(1,     0,      0, 0,
                0, cos_t, -sin_t, 0,
                0, sin_t,  cos_t, 0,
                0,     0,      0, 1);
    Mat4 mt= Transpose(m);
    return Transform(m, mt);
}

Transform Transform::CreateRotate_y(float angle)
{
	/*
    float cosr = cosf(angle);
    float sinr = sinf(angle);

    Mat4 t = Mat4::Identity();
    t(0,0) = cosr;
    t(2,0) = -sinr;
    t(0,2) = sinr;
    t(2,2) = cosr;
    return Transform(t);
	*/
    float sin_t = sinf(Radians(angle));
    float cos_t = cosf(Radians(angle));
    Mat4 m( cos_t,   0,  sin_t, 0,
                 0,   1,      0, 0,
                -sin_t,   0,  cos_t, 0,
                 0,   0,   0,    1);
    Mat4 mt= Transpose(m);
    return Transform(m, mt);
}

Transform Transform::CreateRotate_z(float angle)
{
	/*
    float cosr = cosf(angle);
    float sinr = sinf(angle);

    Mat4 t = Mat4::Identity();
    t(0,0) = cosr;
    t(0,1) = -sinr;
    t(1,0) = sinr;
    t(1,1) = cosr;
    return Transform(t);
*/
    float sin_t = sinf(Radians(angle));
    float cos_t = cosf(Radians(angle));
    Mat4 m(cos_t, -sin_t, 0, 0,
                sin_t,  cos_t, 0, 0,
                0,      0, 1, 0,
                0,      0, 0, 1);
    Mat4 mt= Transpose(m);
    return Transform(m, mt);
}

Transform Transform::CreateTranslate(const Vec3& t)
{
    return Transform::CreateTranslate(t.x, t.y, t.z);
}

Transform Transform::CreateTranslate(float x, float y, float z)
{
	/*
    Mat4 m = Mat4::Identity();
    m(0,3) = x;
    m(1,3) = y;
    m(2,3) = z;
    m(3,3) = 1.0;
    Mat4 mInv = Mat4::Identity();
    mInv(0,3) = -x;
    mInv(1,3) = -y;
    mInv(2,3) = -z;
    mInv(3,3) = 1.0;
    return Transform(m, mInv);*/
    Mat4 m(1, 0, 0, x,
                0, 1, 0, y,
                0, 0, 1, z,
                0, 0, 0,       1);
    Mat4 minv(1, 0, 0, -x,
                   0, 1, 0, -y,
                   0, 0, 1, -z,
                   0, 0, 0,        1);
    return Transform(m, minv);
}

Transform Transform::CreateLookAt(const Point &pos, const Point &look, const Vec3 &up)
{
    float m[4][4];
    // Initialize fourth column of viewing matrix
    m[0][3] = pos.x;
    m[1][3] = pos.y;
    m[2][3] = pos.z;
    m[3][3] = 1;

    // Initialize first three columns of viewing matrix
    Vec3 dir = Normalize(look - pos);
    Vec3 left = Normalize(Cross(Normalize(up), dir));
    Vec3 newUp = Cross(dir, left);
    m[0][0] = left.x;
    m[1][0] = left.y;
    m[2][0] = left.z;
    m[3][0] = 0.;
    m[0][1] = newUp.x;
    m[1][1] = newUp.y;
    m[2][1] = newUp.z;
    m[3][1] = 0.;
    m[0][2] = dir.x;
    m[1][2] = dir.y;
    m[2][2] = dir.z;
    m[3][2] = 0.;
    Mat4 camToWorld(m);
    Mat4 inv = Inverse(camToWorld);
    return Transform(inv, camToWorld);
	/*
    Vec3 w = (eyePos -lookAtPoint ).normalized();
    Vec3 u = upVec.cross(w).normalized();
    Vec3 v = w.cross(u);

    Mat4 rot;
    rot << u.x(), u.y(), u.z(), 0,
            v.x(), v.y(), v.z(), 0,
            w.x(), w.y(), w.z(), 0,
            0,     0,     0,     1;

	Vec3 e = -eyePos;
    return Transform(rot) * Transform::CreateTranslate(e);*/
	
}

Transform Transform::CreateOrthographic(float znear, float zfar)
{
    return Transform::CreateScale(1.0f, 1.0f, 1.0f / (zfar-znear)) * Transform::CreateTranslate(0.0f, 0.0f, -znear);
}

Transform Transform::CreatePerspective(float fov, float n, float f)
{
	/*
    float aspect = 1.0;
    float f = 1.0f / tanf(DEG2RAD*fov/2.0f);
    Mat4 mat;
    mat << f / aspect, 0, 0, 0,
            0, f, 0, 0,
            0, 0, (zfar+znear)/(znear-zfar), (2*zfar*znear)/(znear-zfar),
            0, 0, -1, 0;
    return Transform(mat);
	/*
    // Perform projective divide
    Mat4 persp;
	persp <<1, 0,           0,              0,
            0, 1,           0,              0,
            0, 0, f / (f - n), -f*n / (f - n),
            0, 0,           1,              0;
			
    // Scale to canonical viewing volume
    float invTanAng = 1.0 / tanf(Radians(fov) / 2.0);
	return Transform::CreateScale(invTanAng, invTanAng, 1) * Transform(persp);*/
	    // Perform projective divide
    Mat4 persp = Mat4(1, 0,           0,              0,
                                0, 1,           0,              0,
                                0, 0, f / (f - n), -f*n / (f - n),
                                0, 0,           1,              0);

    // Scale to canonical viewing volume
    float invTanAng = 1.f / tanf(Radians(fov) / 2.f);
    return Transform::CreateScale(invTanAng, invTanAng, 1) * Transform(persp);
}

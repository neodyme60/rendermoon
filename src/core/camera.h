#ifndef __RENDERMOON_CORE_CAMERA__
#define __RENDERMOON_CORE_CAMERA__

class Transform;
class Film;

class Camera
{
public:
    Camera(const Transform &cam2world, Film *film);
    virtual         ~Camera() {}
    virtual float   GenerateRay(const CameraSample &sample, Ray *ray) const = 0;
    Film*           GetFilm() const;
    Transform       m_CameraToWorld;
    Film*           m_film;
};

#endif

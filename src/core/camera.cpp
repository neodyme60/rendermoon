#include <rendermoon.h>


Camera::Camera(const Transform &cam2world, Film *film)
{
	m_CameraToWorld = cam2world;
    m_film = film;
/*
    if (m_CameraToWorld.HasScale())
        Warning("Scaling detected in world-to-camera transformation!\n"
                "The system has numerous assumptions, implicit and explicit,\n"
                "that this transform will have no scale factors in it.\n"
                "Proceed at your own risk; your image may have errors or\n"
                "the system may crash as a result of this.");
*/
}

Film* Camera::GetFilm() const
{
    return m_film;
}

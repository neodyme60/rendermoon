#include <iostream>
#include <glm/common.hpp>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective


#define DEG2RAD glm::pi<double>()/180.0

template <typename T>
class Buffer {
public:
    Buffer(int width, int height) : m_width(width), m_height(height)
    {
        m_data = new T[m_width*m_height];
    }
    T& operator[](std::size_t idx) { return m_data[idx]; }
    T* get_ptr() { return m_data; }
    virtual ~Buffer() { delete[] m_data; }

protected:
    T* m_data;
    int m_width, m_height;
};

struct Ray{
    Ray() {}
    virtual ~Ray() {}
    glm::vec3 o,d;
};
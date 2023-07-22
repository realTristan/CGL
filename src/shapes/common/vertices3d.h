#ifndef SHAPES_VERTICES3D_H
#define SHAPES_VERTICES3D_H

#include <GLFW/glfw3.h>

#include <utils/vector3d.h>

#include <vector>

typedef Vec3D<GLfloat> Vertex3D;

class Vertices3D
{
private:
    std::vector<Vertex3D> points;
    
public:
    Vertices3D()
    {
        this->points = std::vector<Vertex3D>();
    }
    Vertices3D(int n)
    {
        this->points = std::vector<Vertex3D>(n);
    }
    Vertices3D(int n, Vertex3D v)
    {
        this->points = std::vector<Vertex3D>(n, v);
    }
    
    /**
     * @brief Pushback a vertex into the vertices
     *
     * @param v The vertex to push back
     */
    void push_back(Vertex3D v)
    {
        this->points.push_back(v);
    }

    /**
     * @brief Push a vertex into the vertices at the front
     *
     * @param v The vertex to push front
     */
    void push_front(Vertex3D v)
    {
        this->points.insert(this->points.begin(), v);
    }
    
    /**
     * @brief Sets the vertex at the specified index.
     *
     * @param i The index of the vertex to set.
     * @param v The vertex to set.
     */
    void set(int i, Vertex3D v)
    {
        this->points[i] = v;
    }
    
    /**
     * @brief Get the vertices in a vector of Vec3D<GLfloat>
     *
     * @return The vertices in a vector array
     */
    std::vector<Vertex3D> as_vector() {
        return this->points;
    }
    
    /**
     * @brief Get the vertices in an array of Vec3D<GLfloat>
     *
     * @return The vertices in an array
     */
    Vec3D<GLfloat> *as_vec3d_arr()
    {
        return this->points.data();
    }

    /**
     * @brief Returns the vertices as a GLfloat array.
     *
     * @return GLfloat* The vertices as a GLfloat array.
     */
    GLfloat *as_glfloat_arr()
    {
        GLfloat *vertices = new GLfloat[this->points.size() * 3];

        for (int i = 0; i < this->points.size(); i++)
        {
            vertices[i * 3] = this->points[i].x;
            vertices[i * 3 + 1] = this->points[i].y;
            vertices[i * 3 + 2] = this->points[i].z;
        }

        return vertices;
    }
};

#endif // SHAPES_VERTICES_H
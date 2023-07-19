#ifndef SHAPES_VERTICES_H
#define SHAPES_VERTICES_H

#include <utils/vector3d.h>
#include <GLFW/glfw3.h>
#include <vector>

typedef Vec3D<GLfloat> Vertex;

class Vertices
{
private:
    std::vector<Vertex> points;
    
public:
    Vertices()
    {
        this->points = std::vector<Vertex>();
    }
    Vertices(int n)
    {
        this->points = std::vector<Vertex>(n);
    }
    Vertices(int n, Vertex v)
    {
        this->points = std::vector<Vertex>(n, v);
    }
    
    /**
     * @brief Pushback a vertex into the vertices
     *
     * @param v The vertex to push back
     */
    void push_back(Vertex v)
    {
        this->points.push_back(v);
    }
    
    /**
     * @brief Sets the vertex at the specified index.
     *
     * @param i The index of the vertex to set.
     * @param v The vertex to set.
     */
    void set(int i, Vertex v)
    {
        this->points[i] = v;
    }
    
    /**
     * @brief Get the vertices in vertex (Vec3D<GLfloat>) form
     *
     * @return The vertices in a vector array
     */
    std::vector<Vertex> get_as_vector() {
        return this-points;
    }

    /**
     * @brief Returns the vertices as a GLfloat array.
     *
     * @return GLfloat* The vertices as a GLfloat array.
     */
    GLfloat *get_as_glfloat_arr()
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
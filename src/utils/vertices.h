#ifndef VERTICES_H
#define VERTICES_H

#include <utils/vector3d.h>
#include <GLFW/glfw3.h>
#include <vector>

typedef Vec3D<GLfloat> Vertex;

class Vertices
{
public:
    std::vector<Vertex> points;

    Vertices()
    {
        this->points = std::vector<Vertex>();
    }

    Vertices(int n)
    {
        this->points = std::vector<Vertex>(n, Vertex(0, 0, 0));
    }

    Vertices(int n, GLfloat x, GLfloat y, GLfloat z)
    {
        this->points = std::vector<Vertex>(n, Vertex(x, y, z));
    }

    Vertices(int n, Vertex v)
    {
        this->points = std::vector<Vertex>(n, v);
    }

    void set(int i, Vertex v)
    {
        this->points[i] = v;
    }

    GLfloat *get()
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

#endif // VERTICES_H
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <utils/vertices.hpp>
#include <utils/vector3d.hpp>
#include <GLFW/glfw3.h>
#include <math.h>

#define M_PI 3.14159265358979323846 /* pi */
#define M_PI_2 2.0f * M_PI

class Circle
{
private:
    GLint sides;
    GLint numOfVertices;
    GLfloat *vertices;

    Vec3D<GLfloat> position;
    GLfloat radius;

public:
    Circle(Vec3D<GLfloat> position, GLfloat radius, GLint sides)
    {
        this->position = position;
        this->radius = radius;
        this->sides = sides;
        this->numOfVertices = this->sides + 2;
        this->updateVertices();
    }

    void setSides(GLint sides)
    {
        this->sides = sides;
        this->numOfVertices = this->sides + 2;
        this->updateVertices();
    }

    void setPosition(Vec3D<GLfloat> position)
    {
        this->position = position;
        this->updateVertices();
    }

    void setRadius(GLfloat radius)
    {
        this->radius = radius;
        this->updateVertices();
    }

    void updateVertices()
    {
        Vertices vertices = Vertices(this->numOfVertices, this->position);
        for (int i = 1; i < this->numOfVertices; i++)
        {
            vertices.set(i, Vec3D<GLfloat>(
                                this->position.x + (this->radius * cos(i * M_PI_2 / this->sides)),
                                this->position.y + (this->radius * sin(i * M_PI_2 / this->sides)),
                                this->position.z));
        }
        this->vertices = vertices.get();
    }

    void draw()
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, this->vertices);
        glDrawArrays(GL_TRIANGLE_FAN, 0, this->numOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif // CIRCLE_HPP
#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include <shapes/vertices.h>
#include <utils/vector3d.h>
#include <utils/color.h>
#include <utils/math.h>
#include <GLFW/glfw3.h>
#include <math.h>

class Circle
{
private:
    GLint sides;
    GLint numOfVertices;
    GLfloat *vertices;

    Vec3D<GLfloat> position;
    GLfloat radius;

    Color color = WHITE;

public:
    Circle(Vec3D<GLfloat> position, GLfloat radius, GLint sides)
    {
        this->position = position;
        this->radius = radius;
        this->sides = sides;
        this->numOfVertices = this->sides + 2;
        this->updateVertices();
    }

    void setColor(Color color)
    {
        this->color = color;
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
        glColor3f(this->color.r, this->color.g, this->color.b);
        glDrawArrays(GL_TRIANGLE_FAN, 0, this->numOfVertices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif // SHAPES_CIRCLE_H
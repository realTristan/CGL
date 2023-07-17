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
    GLint num_of_vertices;
    GLfloat *vertices;

    Vec3D<GLfloat> position;
    GLfloat radius;

    Color fill_color = WHITE;
    Color outline_color = WHITE;
    GLfloat width = 0;

public:
    Circle(Vec3D<GLfloat> position, GLfloat radius, GLint sides)
    {
        this->position = position;
        this->radius = radius;
        this->sides = sides;
        this->num_of_vertices = this->sides + 2;
        this->update_vertices();
    }

    void set_fill_color(Color color)
    {
        this->fill_color = color;
    }

    void set_outline_color(Color color)
    {
        this->outline_color = color;
    }

    void set_outline_width(GLfloat width)
    {
        this->width = width;
    }

    void set_sides(GLint sides)
    {
        this->sides = sides;
        this->num_of_vertices = this->sides + 2;
        this->update_vertices();
    }

    void set_position(Vec3D<GLfloat> position)
    {
        this->position = position;
        this->update_vertices();
    }

    void set_radius(GLfloat radius)
    {
        this->radius = radius;
        this->update_vertices();
    }

    void update_vertices()
    {
        Vertices vertices = Vertices(this->num_of_vertices, this->position);
        for (int i = 1; i < this->num_of_vertices; i++)
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

        // Draw the circle outline
        if (this->width > 0)
        {
            glColor3f(this->outline_color.r, this->outline_color.g, this->outline_color.b);
            glLineWidth(this->width);
            glDrawArrays(GL_LINE_LOOP, 0, this->num_of_vertices);
        }

        // Draw the circle fill
        glColor3f(this->fill_color.r, this->fill_color.g, this->fill_color.b);
        glDrawArrays(GL_TRIANGLE_FAN, 0, this->num_of_vertices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif // SHAPES_CIRCLE_H
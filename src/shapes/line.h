
#include <shapes/vertices.h>
#include <utils/vector3d.h>
#include <window/window.h>
#include <utils/color.h>
#include <utils/math.h>
#include <GLFW/glfw3.h>
#include <math.h>

class Line
{
private:
    Vec3D<GLfloat> start_position;
    Vec3D<GLfloat> end_position;

    Color color = WHITE;
    GLfloat width = 0;

public:
    Line(Vec3D<GLfloat> start_position, Vec3D<GLfloat> end_position)
    {
        this->start_position = start_position;
        this->end_position = end_position;
    }

    Vec3D<GLfloat> get_start_position() {
        return this->start_position;
    }

    Vec3D<GLfloat> get_end_position() {
        return this->end_position;
    }

    void set_color(Color color)
    {
        this->color = color;
    }

    void set_width(GLfloat width)
    {
        this->width = width;
    }

    void set_start_position(Window *window, Vec3D<GLfloat> start_position)
    {
        this->start_position = start_position;
    }

    void set_end_position(Window *window, Vec3D<GLfloat> end_position)
    {
        this->end_position = end_position;
    }

    void draw(Window *window)
    {
        GLfloat vertices[] = {
            this->start_position.x, this->start_position.y, this->start_position.z,
            this->end_position.x, this->end_position.y, this->end_position.z
        };

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);

        // Draw the circle fill
        glColor3f(this->color.r, this->color.g, this->color.b);
        glDrawArrays(GL_LINES, 0, 2);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};
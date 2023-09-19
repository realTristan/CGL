#ifndef SHAPES_ANGLED_LINE_HPP
#define SHAPES_ANGLED_LINE_HPP

#include <GLFW/glfw3.h>

#include <shapes/line/line.hpp>

#include <utils/vector3d.hpp>
#include <utils/color.hpp>
#include <utils/math.h>

#include <math.h>

class AngledLine : public Line
{
private:
    GLfloat angle;
    GLfloat length = 1;

public:
    /**
     * @brief Creates a new line.
     *
     * @param start_position The start position of the line.
     * @param length The length of the line.
     * @param angle The angle of the line.
     * @param width The width of the line.
     */
    AngledLine(Vec3D<GLfloat> start_position, GLfloat length, GLfloat angle, GLfloat width = 1) : Line(start_position, width)
    {
        this->angle = angle * (M_PI / 180);
        this->length = length;
        this->set_end_position(this->calculate_end_position());
    }

    /**
     * @brief Calculates the end position of the line.
     *
     * @return The end position of the line.
     */
    Vec3D<GLfloat> calculate_end_position()
    {
        GLfloat x = this->get_start_position().x + this->length;
        GLfloat y = this->get_start_position().y + this->length * sin(this->angle);
        return Vec3D<GLfloat>(x, y, 0);
    }

    /**
     * @brief Gets the angle of the line.
     *
     * @return The angle of the line.
     */
    GLfloat get_angle()
    {
        return this->angle;
    }

    /**
     * @brief Sets the angle of the line.
     *
     * @param angle The angle of the line.
     */
    void set_angle(GLfloat angle)
    {
        this->angle = angle;
    }
};

#endif // SHAPES_ANGLED_LINE_HPP
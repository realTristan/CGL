#ifndef SHAPES_POSITIONED_LINE_H
#define SHAPES_POSITIONED_LINE_H

#include <GLFW/glfw3.h>

#include <shapes/line/line.h>

class PositionedLine : public Line
{
public:
    /**
     * @brief Creates a new line.
     *
     * @param start_position The start position of the line.
     * @param end_position The end position of the line.
     * @param width The width of the line.
     */
    PositionedLine(Vec3D<GLfloat> start_position, Vec3D<GLfloat> end_position, GLfloat width = 1) : Line(start_position, width)
    {
        this->set_end_position(end_position);
    }
};

#endif // SHAPES_POSITIONED_LINE_H
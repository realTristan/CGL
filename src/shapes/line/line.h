#ifndef SHAPES_LINE_H
#define SHAPES_LINE_H

#include <GLFW/glfw3.h>

#include <window/window.h>

#include <utils/vector3d.h>
#include <utils/color.h>
#include <utils/math.h>

#include <math.h>
#include <vector>

class Line
{
private:
    Vec3D<GLfloat> start_position;
    Vec3D<GLfloat> end_position;

    Color color = WHITE;
    GLfloat width = 1;

public:
    /**
     * @brief Creates a new line.
     *
     * @param start_position The start position of the line.
     * @param width The width of the line.
     * @param color The color of the line.
     */
    Line(Vec3D<GLfloat> start_position, GLfloat width = 1, Color color = WHITE)
    {
        this->start_position = start_position;
        this->end_position = start_position;
        this->color = color;
        this->width = width;
    }

    /**
     * @brief Gets the start position of the line.
     *
     * @return The start position of the line.
     */
    Vec3D<GLfloat> get_start_position() {
        return this->start_position;
    }

    /**
     * @brief Sets the color of the line.
     * 
     * @param color The color of the line.
     *
     * @return The color of the line.
     */
    void set_color(Color color)
    {
        this->color = color;
    }

    /**
     * @brief Sets the width of the line.
     * 
     * @param width The width of the line.
     *
     * @return The width of the line.
     */
    void set_width(GLfloat width)
    {
        this->width = width;
    }

    /**
     * @brief Sets the start position of the line.
     * 
     * @param start_position The start position of the line.
     *
     * @return The start position of the line.
     */
    void set_start_position(Vec3D<GLfloat> start_position)
    {
        this->start_position = start_position;
    }

    /**
     * @brief Gets the end position of the line.
     *
     * @return The end position of the line.
     */
    Vec3D<GLfloat> get_end_position() {
        return this->end_position;
    }

    /**
     * @brief Sets the end position of the line.
     * 
     * @param end_position The end position of the line.
     *
     * @return The end position of the line.
     */
    void set_end_position(Vec3D<GLfloat> end_position)
    {
        this->end_position = end_position;
    }

    /**
     * @brief Draws the line.
     *
     */
    void draw()
    {
        // Fill the vertices with extra vertices to make the line thicker
        std::vector<GLfloat> vertices(this->width * 6);
        for (int i = 0; i < this->width; i++) {
            vertices.push_back(this->start_position.x);
            vertices.push_back(this->start_position.y + i);
            vertices.push_back(this->start_position.z);
            vertices.push_back(this->end_position.x);
            vertices.push_back(this->end_position.y + i);
            vertices.push_back(this->end_position.z);
        }

        // Enable vertex arrays
        glEnableClientState(GL_VERTEX_ARRAY);
        // Set the vertex pointer
        glVertexPointer(3, GL_FLOAT, 0, vertices.data());
        // Set the color
        glColor3f(this->color.r, this->color.g, this->color.b);
        // Draw the line
        glDrawArrays(GL_LINES, 0, this->width * 4);
        // Disable vertex arrays
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif // SHAPES_LINE_H
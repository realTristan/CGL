#ifndef SHAPES_CIRCLE_H
#define SHAPES_CIRCLE_H

#include <shapes/vertices.h>
#include <utils/vector3d.h>
#include <utils/color.h>
#include <utils/math.h>
#include <GLFW/glfw3.h>
#include <math.h>

/**
 * @brief A class that represents a circle.
 * 
 */
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
    GLfloat outline_width = 0;

public:
    /**
     * @brief Creates a new circle.
     *
     * @param position The position of the circle.
     * @param radius The radius of the circle.
     * @param sides The number of sides of the circle.
     */
    Circle(Vec3D<GLfloat> position, GLfloat radius, GLint sides)
    {
        this->position = position;
        this->radius = radius;
        this->sides = sides;
        this->num_of_vertices = this->sides + 2;
        this->update_vertices();
    }

    /**
     * @brief Gets the fill color of the circle.
     *
     * @return The fill color of the circle.
     */
    Color get_fill_color()
    {
        return this->fill_color;
    }

    /**
     * @brief Gets the outline color of the circle.
     *
     * @return The outline color of the circle.
     */
    Color get_outline_color()
    {
        return this->outline_color;
    }

    /**
     * @brief Gets the outline width of the circle.
     *
     * @return The outline width of the circle.
     */
    GLfloat get_outline_width()
    {
        return this->outline_width;
    }

    /**
     * @brief Gets the number of sides of the circle.
     *
     * @return The number of sides of the circle.
     */
    GLint get_sides()
    {
        return this->sides;
    }

    /**
     * @brief Gets the position of the circle.
     *
     * @return The position of the circle.
     */
    Vec3D<GLfloat> get_position()
    {
        return this->position;
    }

    /**
     * @brief Gets the radius of the circle.
     *
     * @return The radius of the circle.
     */
    GLfloat get_radius()
    {
        return this->radius;
    }

    /**
     * @brief Gets the vertices of the circle.
     *
     * @return The vertices of the circle.
     */
    GLfloat get_vertices()
    {
        return *this->vertices;
    }

    /**
     * @brief Gets the number of vertices of the circle.
     *
     * @return The number of vertices of the circle.
     */
    GLint get_num_of_vertices()
    {
        return this->num_of_vertices;
    }

    /**
     * @brief Sets the fill color of the circle.
     *
     * @param color The color to set the fill color to.
     */
    void set_fill_color(Color color)
    {
        this->fill_color = color;
    }

    /**
     * @brief Sets the outline color of the circle.
     *
     * @param color The color to set the outline color to.
     */
    void set_outline_color(Color color)
    {
        this->outline_color = color;
    }

    /**
     * @brief Sets the outline width of the circle.
     *
     * @param width The width to set the outline width to.
     */
    void set_outline_width(GLfloat width)
    {
        this->outline_width = width;
    }

    /**
     * @brief Sets the number of sides of the circle.
     *
     * @param sides The number of sides to set the circle to.
     */
    void set_sides(GLint sides)
    {
        this->sides = sides;
        this->num_of_vertices = this->sides + 2;
        this->update_vertices();
    }

    /**
     * @brief Sets the position of the circle.
     *
     * @param position The position to set the circle to.
     */
    void set_position(Vec3D<GLfloat> position)
    {
        this->position = position;
        this->update_vertices();
    }

    /**
     * @brief Sets the radius of the circle.
     *
     * @param radius The radius to set the circle to.
     */
    void set_radius(GLfloat radius)
    {
        this->radius = radius;
        this->update_vertices();
    }

    /**
     * @brief Updates the vertices of the circle.
     */
    void update_vertices()
    {
        Vertices *vertices = new Vertices(this->num_of_vertices, this->position);
        for (int i = 1; i < this->num_of_vertices; i++)
        {
            Vertex vertex = Vertex(
                this->position.x + (this->radius * cos(i * M_PI_2 / this->sides)),
                this->position.y + (this->radius * sin(i * M_PI_2 / this->sides)),
                this->position.z);
            vertices->set(i, vertex);
        }
        this->vertices = vertices->as_glfloat_arr();
    }

    /**
     * @brief Draws the circle.
     */
    void draw()
    {
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, this->vertices);

        // Draw the circle outline
        if (this->outline_width > 0)
        {
            glColor3f(this->outline_color.r, this->outline_color.g, this->outline_color.b);
            glLineWidth(this->outline_width);
            glDrawArrays(GL_LINE_LOOP, 0, this->num_of_vertices);
        }

        // Draw the circle fill
        glColor3f(this->fill_color.r, this->fill_color.g, this->fill_color.b);
        glDrawArrays(GL_TRIANGLE_FAN, 0, this->num_of_vertices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
};

#endif // SHAPES_CIRCLE_H
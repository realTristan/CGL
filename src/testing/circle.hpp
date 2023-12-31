#ifndef TESTING_CIRCLE_HPP
#define TESTING_CIRCLE_HPP

#include <GLFW/glfw3.h>

#include <shapes/circle.hpp>
#include <window/window.hpp>
#include <testing/utils.hpp>

#include <utils/vector3d.hpp>
#include <utils/color.hpp>

#include <math.h>

class TestingCircle
{
public:
    static int start(void)
    {
        // Create a new window
        Window *window = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        if (!window->init())
        {
            return -1;
        }
        window->set_framerate(60);
        window->set_position(500, 200);

        // Create a new circle
        Vec3D<GLfloat> position = Vec3D<GLfloat>(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0);
        Circle *circle = new Circle(position, 120, 128);
        circle->set_fill_color(BLACK);
        circle->set_outline_color(WHITE);
        circle->set_outline_width(5);

        // Loop until the user closes the window
        while (window->is_open())
        {
            // Clear the window
            window->clear(BLACK);

            // Render OpenGL here
            circle->draw();

            // Display the window
            window->display();
        }

        // Close the window
        window->close();
        return 0;
    }
};

#endif // TESTING_CIRCLE_HPP
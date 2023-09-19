#ifndef TESTING_ANGLED_LINE_HPP
#define TESTING_ANGLED_LINE_HPP

#include <GLFW/glfw3.h>

#include <shapes/line/angled.hpp>
#include <window/window.hpp>
#include <testing/utils.hpp>

#include <utils/vector3d.hpp>
#include <utils/color.hpp>

#include <math.h>

class TestingAngledLine
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
        Vec3D<GLfloat> start_position = Vec3D<GLfloat>(100, 400, 0);
        AngledLine *line = new AngledLine(start_position, 100.0, -30.0, 2.0f);

        // Loop until the user closes the window
        while (window->is_open())
        {
            // Clear the window
            window->clear(BLACK);

            // Render OpenGL here
            line->draw();

            // Display the window
            window->display();
        }

        // Close the window
        window->close();
        return 0;
    }
};

#endif // TESTING_ANGLED_LINE_HPP
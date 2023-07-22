#ifndef TESTING_POSITIONED_LINE
#define TESTING_POSITIONED_LINE

#include <GLFW/glfw3.h>

#include <shapes/line/positioned.h>
#include <testing/utils.h>
#include <window/window.h>

#include <utils/vector3d.h>
#include <utils/color.h>

#include <math.h>

class TestingPositionedLine
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
        Vec3D<GLfloat> start_position = Vec3D<GLfloat>(100, 100, 0);
        Vec3D<GLfloat> end_position = Vec3D<GLfloat>(200, 100, 0);
        PositionedLine *line = new PositionedLine(start_position, end_position, 5.0f);

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

#endif // TESTING_POSITIONED_LINE
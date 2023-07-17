#ifndef TESTING_CIRCLE
#define TESTING_CIRCLE

#include <windows.h>
#include <GLFW/glfw3.h>
#include <utils/vector3d.h>
#include <shapes/circle.h>
#include <window/window.h>
#include <testing/utils.h>
#include <utils/color.h>
#include <math.h>

class TestingCircle
{
public:
    static int start(void)
    {
        // Create a new window
        Window window = Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        if (!window.init())
        {
            return -1;
        }

        // Create a new circle
        Vec3D<GLfloat> position = Vec3D<GLfloat>(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0);
        Circle circle = Circle(position, 120, 128);
        circle.setColor(RED);

        // Loop until the user closes the window
        while (window.isOpen())
        {
            // Clear the window
            window.clear(BLACK);

            // Render OpenGL here
            circle.draw();

            // Display the window
            window.display();
        }

        // Close the window
        window.close();
        return 0;
    }
};

#endif // TESTING_CIRCLE
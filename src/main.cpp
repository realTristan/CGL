#ifndef MAIN
#define MAIN

#include <windows.h>
#include <GLFW/glfw3.h>
#include <utils/vector3d.h>
#include <shapes/circle.h>
#include <window/window.h>
#include <utils/color.h>
#include <math.h>

#define M_PI 3.14159265358979323846 /* pi */
#define M_PI_2 2.0f * M_PI

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "CGL Circle"

int main(void)
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

#endif // MAIN
#ifndef MAIN
#define MAIN

#include <windows.h>
#include <GLFW/glfw3.h>
#include <utils/vector3d.h>
#include <shapes/circle.h>
#include <math.h>

#define M_PI 3.14159265358979323846 /* pi */
#define M_PI_2 2.0f * M_PI

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void)
{
    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Circle", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glMatrixMode(GL_PROJECTION);
    // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    glLoadIdentity();
    // essentially set coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Create a new circle
    Vec3D<GLfloat> position = Vec3D<GLfloat>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
    Circle circle = Circle(position, 120, 128);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        // Render OpenGL here
        circle.draw();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}

#endif // MAIN
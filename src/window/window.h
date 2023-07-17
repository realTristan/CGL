#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <utils/color.h>
#include <iostream>

class Window
{
private:
    GLFWwindow *window;

public:
    int width;
    int height;
    char *title;

    Window(int width, int height, char *title)
    {
        this->width = width;
        this->height = height;
        this->title = title;
    }

    // Close the GL Window
    void close()
    {
        glfwTerminate();
    }

    // Initialize the GL Window
    int init()
    {
        if (!glfwInit())
        {
            return -1;
        }

        // Create a new window
        this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);
        if (!this->window)
        {
            this->close();
            return -1;
        }

        // Make the window's context current
        glfwMakeContextCurrent(this->window);
        glViewport(0.0f, 0.0f, this->width, this->height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, this->width, 0, this->height, 0, 1);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Print opengl version
        std::cout << "Running OpenGL " << glGetString(GL_VERSION) << std::endl;
        return 1;
    }

    bool isOpen()
    {
        return !glfwWindowShouldClose(this->window);
    }

    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void clear(Color color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        this->clear();
    }

    void display()
    {
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
};

#endif // WINDOW_H
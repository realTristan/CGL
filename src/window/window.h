#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <utils/color.h>
#include <iostream>

/**
 * @brief The Window class represents a GLFW window with OpenGL context.
 */
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

    /**
     * @brief Closes the GLFW window and terminates GLFW.
     */
    void close()
    {
        glfwTerminate();
    }

    /**
     * @brief Initializes GLFW and creates a new window with the specified width, height, and title.
     *
     * @return 1 if successful, -1 otherwise.
     */
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

    /**
     * @brief Checks if the window is open.
     *
     * @return true if the window is open, false otherwise.
     */
    bool is_open()
    {
        return !glfwWindowShouldClose(this->window);
    }

    /**
     * @brief Clears the color buffer.
     */
    void clear()
    {
        glClear(GL_COLOR_BUFFER_BIT);
    }

    /**
     * @brief Clears the color buffer with the specified color.
     *
     * @param color The color to clear the buffer with.
     */
    void clear(Color color)
    {
        glClearColor(color.r, color.g, color.b, color.a);
        this->clear();
    }

    /**
     * @brief Swaps the front and back buffers and polls for events.
     */
    void display()
    {
        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
};

#endif // WINDOW_H
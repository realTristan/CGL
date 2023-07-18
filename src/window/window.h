#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <utils/color.h>
#include <utils/vector2d.h>
#include <iostream>

/**
 * @brief The WindowSettings struct represents the settings for a GLFW window.
 */
typedef struct WindowSettings
{
    int width;
    int height;
    char *title;
} WindowSettings;

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

    Window(WindowSettings settings)
    {
        this->width = settings.width;
        this->height = settings.height;
        this->title = settings.title;
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
     * @brief Initializes GLFW and creates a new window with the specified settings. 
     * The window can be accessed by the provided function.
     *
     * @param settings The window settings.
     * @param func The lambda function to run after the window is initialized.
     * @return 1 if successful, -1 otherwise.
     */
    static void open_context(WindowSettings settings, void (*func)(Window *window))
    {
        // initialize a new window
        Window *window = new Window(settings);
        if (!window->init())
        {
            return;
        }

        // run the provided function
        func(window);

        // close the window
        window->close();
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

    /**
     * @brief Sets the framerate
     *
     * @param framerate The framerate
     */
    void set_framerate(int framerate)
    {
        glfwSwapInterval(framerate);
    }

    /**
     * @brief Sets the window's title.
     *
     * @param title The title
     */
    void set_title(char *title)
    {
        glfwSetWindowTitle(this->window, title);
    }

    /**
     * @brief Sets the window's width and height.
     *
     * @param width The width
     * @param height The height
     */
    void set_size(int width, int height)
    {
        this->width = width;
        this->height = height;
        glfwSetWindowSize(this->window, width, height);
    }

    /**
     * @brief Sets the window's width.
     *
     * @param width The width
     */
    void set_width(int width)
    {
        this->width = width;
        glfwSetWindowSize(this->window, width, this->height);
    }

    /**
     * @brief Sets the window's height.
     *
     * @param height The height
     */
    void set_height(int height)
    {
        this->height = height;
        glfwSetWindowSize(this->window, this->width, height);
    }

    /**
     * @brief Sets the window's position.
     *
     * @param x The x position
     * @param y The y position
     */
    void set_position(int x, int y)
    {
        glfwSetWindowPos(this->window, x, y);
    }

    /**
     * @brief Sets the window's x position.
     *
     * @param x The x position
     */
    void set_position_x(int x)
    {
        glfwSetWindowPos(this->window, x, this->height);
    }

    /**
     * @brief Sets the window's y position.
     *
     * @param y The y position
     */
    void set_position_y(int y)
    {
        glfwSetWindowPos(this->window, this->width, y);
    }

    /**
     * @brief Gets the window's width.
     *
     * @return The width
     */
    int get_width()
    {
        return this->width;
    }

    /**
     * @brief Gets the window's height.
     *
     * @return The height
     */
    int get_height()
    {
        return this->height;
    }

    /**
     * @brief Gets the window's title.
     *
     * @return The title
     */
    char *get_title()
    {
        return this->title;
    }

    /**
     * @brief Gets the window's position.
     *
     * @return The position
     */
    Vec2D<int> *get_position()
    {
        int *x = new int;
        int *y = new int;
        glfwGetWindowPos(this->window, x, y);
        return new Vec2D<int>(*x, *y);
    }

    /**
     * @brief Gets the position of the mouse relative to the window.
     *
     * @return the position of the mouse
     */
    Vec2D<double> *get_mouse_position()
    {
        double *x = new double;
        double *y = new double;
        glfwGetCursorPos(this->window, x, y);
        return new Vec2D<double>(*x, *y);
    }
};

#endif // WINDOW_H
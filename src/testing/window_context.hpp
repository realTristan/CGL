#ifndef TESTING_WINDOW_CONTEXT_HPP
#define TESTING_WINDOW_CONTEXT_HPP

#include <window/window.hpp>
#include <shapes/circle.hpp>
#include <testing/utils.hpp>

#include <utils/vector3d.hpp>
#include <utils/color.hpp>

class TestingWindowContext
{
public:
    static void start()
    {
        // Initialize the window settings
        WindowSettings settings = {
            800,
            600,
            "Testing Window Context"};

        // Open a new window context
        // WindowSettings settings, void (*func)(Window *window))
        Window::open_context(settings, [](Window *window)
                             {
            // Create a new circle
            Vec3D<GLfloat> position = Vec3D<GLfloat>(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0);
            Circle *circle = new Circle(position, 120, 128);
            circle->set_fill_color(RED);

            // Loop until the user closes the window
            while (window->is_open())
            {
                window->clear();

                circle->draw();
                
                window->display();

            } });
    }
};

#endif // TESTING_WINDOW_CONTEXT_HPP
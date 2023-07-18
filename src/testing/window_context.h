#ifndef TESTING_WINDOW_CONTEXT_H
#define TESTING_WINDOW_CONTEXT_H

#include <window/window.h>
#include <testing/utils.h>
#include <shapes/circle.h>
#include <utils/vector3d.h>
#include <utils/color.h>

class TestingWindowContext
{
public:
    static void start()
    {
        // Initialize the window settings
        WindowSettings settings = {
            800,
            600,
            "Testing Window Context"
        };

        // Open a new window context
        // WindowSettings settings, void (*func)(Window *window))
        Window::open_context(settings, [](Window *window) {
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

            }
        });
    }
};

#endif // TESTING_WINDOW_CONTEXT_H
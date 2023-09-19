#ifndef MAIN
#define MAIN

#include <testing/circle.hpp>
#include <testing/line_angled.hpp>
#include <testing/line_positioned.hpp>
#include <testing/window_context.hpp>

int main(void)
{
    /////////////////
    //    Tests    //
    /////////////////

    // TestingCircle::start();
    // TestingPositionedLine::start();
    // TestingAngledLine::start();
    TestingWindowContext::start();

    // Exit
    return 0;
}
#endif // MAIN
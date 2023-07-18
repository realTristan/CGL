#ifndef WINDOW_KEYS_H
#define WINDOW_KEYS_H

#include <GLFW/glfw3.h>

class Keys
{
public:
    static bool pressed(GLFWwindow *window, int key)
    {
        return glfwGetKey(window, key) == GLFW_PRESS;
    }

    static int get_glfw(GLFWwindow *window, int key = -1)
    {
        return glfwGetKey(window, key);
    }

    static const int MOUSE_BUTTON_LEFT = 0;
    static const int MOUSE_BUTTON_RIGHT = 1;
    static const int MOUSE_BUTTON_MIDDLE = 2;
    static const int SPACE = 32;
    static const int ZERO = 48;
    static const int ONE = 49;
    static const int TWO = 50;
    static const int THREE = 51;
    static const int FOUR = 52;
    static const int FIVE = 53;
    static const int SIX = 54;
    static const int SEVEN = 55;
    static const int EIGHT = 56;
    static const int NINE = 57;
    static const int A = 65;
    static const int B = 66;
    static const int C = 67;
    static const int D = 68;
    static const int E = 69;
    static const int F = 70;
    static const int G = 71;
    static const int H = 72;
    static const int I = 73;
    static const int J = 74;
    static const int K = 75;
    static const int L = 76;
    static const int M = 77;
    static const int N = 78;
    static const int O = 79;
    static const int P = 80;
    static const int Q = 81;
    static const int R = 82;
    static const int S = 83;
    static const int T = 84;
    static const int U = 85;
    static const int V = 86;
    static const int W = 87;
    static const int X = 88;
    static const int Y = 89;
    static const int Z = 90;
    static const int ESCAPE = 256;
    static const int ENTER = 257;
    static const int LEFT_SHIFT = 340;
    static const int LEFT_CONTROL = 341;
    static const int LEFT_ALT = 342;
    static const int LEFT_SUPER = 343;
    static const int RIGHT_SHIFT = 344;
    static const int RIGHT_CONTROL = 345;
    static const int RIGHT_ALT = 346;
    static const int RIGHT_SUPER = 347;
    static const int UP = 265;
    static const int DOWN = 264;
    static const int LEFT = 263;
    static const int RIGHT = 262;
    static const int BACKSPACE = 259;
    static const int DELETE = 261;
    static const int UNKNOWN = -1;
    static const int MENU = 348;
    static const int LEFT_BRACKET = 91;
    static const int RIGHT_BRACKET = 93;
    static const int SEMICOLON = 59;
    static const int APOSTROPHE = 39;
    static const int COMMA = 44;
    static const int PERIOD = 46;
    static const int SLASH = 47;
    static const int BACKSLASH = 92;
    static const int GRAVE_ACCENT = 96;
    static const int WORLD_1 = 161;
    static const int WORLD_2 = 162;
    static const int CAPS_LOCK = 280;
    static const int SCROLL_LOCK = 281;
    static const int NUM_LOCK = 282;
    static const int PRINT_SCREEN = 283;
    static const int PAUSE = 284;
    static const int F1 = 290;
    static const int F2 = 291;
    static const int F3 = 292;
    static const int F4 = 293;
    static const int F5 = 294;
    static const int F6 = 295;
    static const int F7 = 296;
    static const int F8 = 297;
    static const int F9 = 298;
    static const int F10 = 299;
    static const int F11 = 300;
    static const int F12 = 301;
    static const int F13 = 302;
    static const int F14 = 303;
    static const int F15 = 304;
    static const int F16 = 305;
    static const int F17 = 306;
    static const int F18 = 307;
    static const int F19 = 308;
    static const int F20 = 309;
    static const int F21 = 310;
    static const int F22 = 311;
    static const int F23 = 312;
    static const int F24 = 313;
    static const int F25 = 314;
    static const int KP_0 = 320;
    static const int KP_1 = 321;
    static const int KP_2 = 322;
    static const int KP_3 = 323;
    static const int KP_4 = 324;
    static const int KP_5 = 325;
    static const int KP_6 = 326;
    static const int KP_7 = 327;
    static const int KP_8 = 328;
    static const int KP_9 = 329;
    static const int KP_DECIMAL = 330;
    static const int KP_DIVIDE = 331;
    static const int KP_MULTIPLY = 332;
    static const int KP_SUBTRACT = 333;
    static const int KP_ADD = 334;
    static const int KP_ENTER = 335;
    static const int KP_EQUAL = 336;

};

#endif // WINDOW_KEYS_H
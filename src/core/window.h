#ifndef WINDOW_H
#define WINDOW_H

#include "globals.h"

class Window {
    public:
        bool init(const uint32_t width, const uint32_t height, const char* title);
        void cleanup();

        GLFWwindow* get() {
            return window;
        }

        bool shouldClose;
    
    private:
        GLFWwindow* window;
};

#endif // WINDOW_H
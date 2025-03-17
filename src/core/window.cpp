#include "window.h"

bool Window::init(const uint32_t width, const uint32_t height, const char* title) {
    // Initialize the window
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    shouldClose = GLFW_FALSE;

    return GLFW_TRUE;
}

void Window::cleanup() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
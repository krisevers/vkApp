#include "app.h"

#include <chrono>
#include <thread>

App::App()
{
}

void App::run()
{
    init();
    loop();
    cleanup();
}

void App::init()
{
    // Initialize the window
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(WIDTH, HEIGHT, "vkApp", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    // Initialize the Vulkan context
    if(initializeVulkanContext(m_context, window) != VK_SUCCESS) {
        throw std::runtime_error("Failed to initialize Vulkan context");
    }

    // Initialize the Renderer
    if(initializeRenderer(m_renderer, m_context) != VK_SUCCESS) {
        throw std::runtime_error("Failed to initialize Renderer");
    }

    // Create command pool
    // Create depth resources
    // Create framebuffers
    // Create texture image
    // Create texture image view
    // Create texture sampler
    // Load model
    // Create vertex buffer
    // Create index buffer
    // Create uniform buffers
    // Create descriptor pool
    // Create descriptor sets
    // Create command buffers
    // Create sync objects
}

void App::cleanup()
{
    cleanupVulkanContext(m_context);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void App::loop()
{
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        // draw();
        // update();
    }
}
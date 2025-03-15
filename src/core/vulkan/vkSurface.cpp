#include "vkSurface.h"

VkResult createSurface(VkInstance instance, GLFWwindow* window, VkSurfaceKHR& surface)
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create window surface!");
    }

    return VK_SUCCESS;
}

void cleanupSurface(VkInstance instance, VkSurfaceKHR surface)
{
    vkDestroySurfaceKHR(instance, surface, nullptr);
}
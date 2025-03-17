#ifndef CONTEXT_H
#define CONTEXT_H

#include "globals.h"

class Context {
public:
    VkResult init(GLFWwindow* window);
    void cleanup();

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkQueue computeQueue;

private:
    VkResult createInstance();
    VkResult setupDebugMessenger();
    VkResult createSurface(GLFWwindow* window);
    VkResult pickPhysicalDevice();
    VkResult createLogicalDevice();

    bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);
};

#endif // CONTEXT_H
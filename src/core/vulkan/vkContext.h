#ifndef VKCONTEXT_H
#define VKCONTEXT_H

#include "../globals.h"

#include <vector>

struct VulkanContext {
    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkSurfaceKHR surface;

    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;

    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkQueue computeQueue;

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;

    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;

    std::vector<VkFramebuffer> framebuffers;
    VkImage depthImage;
    VkImageView depthImageView;
    VkDeviceMemory depthImageMemory;
};

VkResult initializeVulkanContext(VulkanContext& context, GLFWwindow* window);
void cleanupVulkanContext(VulkanContext& context);

#endif // VKCONTEXT_H
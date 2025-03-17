#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include "globals.h"
#include "context.h"
#include "renderPass.h"
#include "image.h"

class SwapChain {
public:
    VkResult init(Context& context, GLFWwindow* window);
    void cleanup(Context& context);
    VkResult recreate(Context& context, GLFWwindow* window, VkRenderPass renderPass);

    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    VkResult createSwapChain(Context& context, GLFWwindow* window);
    VkResult createImageViews(Context& context);
    VkResult createDepthResources(Context& context);
    VkResult createFramebuffers(Context& context, VkRenderPass renderPass);
};

//----------------------------------------------------------------//

VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);

#endif // SWAPCHAIN_H
#ifndef VKSWAPCHAIN_H
#define VKSWAPCHAIN_H

#include "../globals.h"

VkResult createSwapChain(VkPhysicalDevice physicalDevice, VkDevice device, VkSurfaceKHR surface, GLFWwindow* window, 
                    VkSwapchainKHR& swapChain, std::vector<VkImage>& swapChainImages, std::vector<VkImageView>& swapChainImageViews, 
                    VkFormat& swapChainImageFormat, VkExtent2D& swapChainExtent);
void cleanupSwapChain(VkDevice device, VkSwapchainKHR swapChain, std::vector<VkImageView>& swapChainImageViews);
void recreateSwapChain(VkPhysicalDevice physicalDevice, VkDevice device, VkSurfaceKHR surface, GLFWwindow* window, 
                        VkSwapchainKHR& swapChain, std::vector<VkImage>& swapChainImages, std::vector<VkImageView>& swapChainImageViews, 
                        VkFormat& swapChainImageFormat, VkExtent2D& swapChainExtent);

//----------------------------------------------------------------//

VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities, GLFWwindow* window);

#endif // VKSWAPCHAIN_H
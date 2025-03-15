#ifndef RENDERPASS_H
#define RENDERPASS_H

#include "../globals.h"

VkResult createRenderPass(VkPhysicalDevice physicalDevice, VkDevice device, VkFormat swapChainImageFormat, VkRenderPass& renderPass);
void cleanupRenderPass(VkDevice device, VkRenderPass renderPass);

//----------------------------------------------------------------//

VkFormat findDepthFormat(VkPhysicalDevice physicalDevice);
VkFormat findSupportedFormat(VkPhysicalDevice physicalDevice, const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);

#endif // RENDERPASS_H
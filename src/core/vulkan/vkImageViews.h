#ifndef VKIMAGEVIEWS_H
#define VKIMAGEVIEWS_H

#include "../globals.h"

VkResult createImageViews(VkDevice device, std::vector<VkImageView> swapChainImageViews, std::vector<VkImage> swapChainImages, VkFormat swapChainImageFormat);
VkImageView createImageView(VkDevice device, VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);

#endif // VKIMAGEVIEWS_H
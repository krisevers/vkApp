#ifndef VKFRAMEBUFFER_H
#define VKFRAMEBUFFER_H

#include "../globals.h"

struct Framebuffer {
    VkImage colorImage;
    VkImageView colorImageView;
    VkImage depthImage;
    VkImageView depthImageView;
    VkFramebuffer framebuffer;
};

VkResult createFramebuffers(VkDevice device, VkRenderPass renderPass, VkExtent2D extent, VkImageView depthImageView, VkImageView imageView, VkFramebuffer* framebuffer);

#endif // VKFRAMEBUFFER_H
#include "vkFramebuffer.h"

VkResult createFramebuffers(VkDevice device, VkRenderPass renderPass, VkExtent2D extent, VkImageView depthImageView, VkImageView imageView, VkFramebuffer* framebuffer) 
{
    VkImageView attachments[2] = { imageView, depthImageView };

    VkFramebufferCreateInfo framebufferInfo = {};
    framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebufferInfo.renderPass = renderPass;
    framebufferInfo.attachmentCount = 2;
    framebufferInfo.pAttachments = attachments;
    framebufferInfo.width = extent.width;
    framebufferInfo.height = extent.height;
    framebufferInfo.layers = 1;

    return vkCreateFramebuffer(device, &framebufferInfo, nullptr, framebuffer);
}
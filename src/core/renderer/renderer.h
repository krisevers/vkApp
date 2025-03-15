#ifndef RENDERER_H
#define RENDERER_H

#include "../globals.h"
#include "../vulkan/vkContext.h"

#include "renderPass.h"
#include "descriptorSet.h"
#include "graphics.h"

struct Renderer {
    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;

    Graphics graphics;
};

VkResult initializeRenderer(Renderer& renderer, VulkanContext context);

void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

#endif // RENDERER_H
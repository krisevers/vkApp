#ifndef COMMAND_H
#define COMMAND_H

#include "globals.h"
#include "context.h"

class Command {
    public:
        VkResult createPool(Context& context);
        VkResult createBuffers(Context& context, uint32_t bufferCount);
        void cleanup(Context& context);

        VkCommandPool commandPool;
        std::vector<VkCommandBuffer> commandBuffers;

        VkCommandBuffer beginSingleTimeCommands(Context& context);
        void endSingleTimeCommands(Context& context, VkCommandBuffer commandBuffer);

    private:
        void recordCommandBuffer(Context& context, VkCommandBuffer commandBuffer, 
            uint32_t imageIndex, VkRenderPass renderPass, VkPipeline graphicsPipeline, 
            VkPipelineLayout pipelineLayout, VkBuffer vertexBuffer, 
            VkBuffer indexBuffer, std::vector<VkDescriptorSet>& descriptorSets, 
            VkExtent2D swapChainExtent, std::vector<VkFramebuffer>& swapChainFramebuffers);

};

#endif // COMMAND_H
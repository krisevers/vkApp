#include "renderer.h"

VkResult initializeRenderer(Renderer& renderer, VulkanContext context) {

    // initialize graphics
    if (createRenderPass(context.physicalDevice, context.device, context.swapChainImageFormat, renderer.graphics.renderPass) != VK_SUCCESS) 
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    std::vector<VkDescriptorSetLayoutBinding> bindings;
    bindings.push_back(createDescriptorSetLayoutBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, nullptr));
    bindings.push_back(createDescriptorSetLayoutBinding(1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, nullptr));

    if (createDescriptorSetLayout(context.device, bindings, renderer.graphics.descriptorSetLayout) != VK_SUCCESS) 
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    std::vector<std::string> shaderPaths = {"resources/shaders/vert.spv", "resources/shaders/frag.spv"};
    if (createGraphicsPipeline(context.device, renderer.graphics, shaderPaths) != VK_SUCCESS) 
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return VK_SUCCESS;
};

void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex) {

};
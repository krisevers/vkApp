#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../globals.h"

struct Graphics {
    VkPipelineLayout pipelineLayout{};
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipeline pipeline;
};

VkResult createGraphicsPipeline(VkDevice device, Graphics& graphics, const std::vector<std::string>& shaderPaths);
void cleanupGraphicsPipeline(VkDevice device, Graphics& graphics);


VkPipelineVertexInputStateCreateInfo getVertexInput();
VkPipelineInputAssemblyStateCreateInfo getInputAssembly();
VkPipelineViewportStateCreateInfo getViewportState();
VkPipelineRasterizationStateCreateInfo getRasterizer();
VkPipelineMultisampleStateCreateInfo getMultisampling();
VkPipelineColorBlendAttachmentState getColorBlendAttachment();
VkPipelineColorBlendStateCreateInfo getColorBlending();
VkPipelineDepthStencilStateCreateInfo getDepthStencil();
VkPipelineLayoutCreateInfo getPipelineLayoutInfo(VkDescriptorSetLayout& descriptorSetLayout);

//----------------------------------------------------------------//


#endif // GRAPHICS_H
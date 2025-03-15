#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "../globals.h"

struct Graphics {
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
    VkPipelineLayout pipelineLayout{};
    VkRenderPass renderPass;
    VkDescriptorSetLayout descriptorSetLayout;
    VkPipeline pipeline;
};

VkResult createGraphicsPipeline(VkDevice device, Graphics& graphics, const std::vector<std::string>& shaderPaths);

VkPipelineVertexInputStateCreateInfo getVertexInput();
VkPipelineInputAssemblyStateCreateInfo getInputAssembly();
VkPipelineViewportStateCreateInfo getViewportState();
VkPipelineRasterizationStateCreateInfo getRasterizer();
VkPipelineMultisampleStateCreateInfo getMultisampling();
VkPipelineColorBlendAttachmentState getColorBlendAttachment();
VkPipelineColorBlendStateCreateInfo getColorBlending();
VkPipelineDynamicStateCreateInfo getDynamicState();
VkPipelineDepthStencilStateCreateInfo getDepthStencil();
VkPipelineLayoutCreateInfo getPipelineLayoutInfo(VkDescriptorSetLayout& descriptorSetLayout);


#endif // GRAPHICS_H
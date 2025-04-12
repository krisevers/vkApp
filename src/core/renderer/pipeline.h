#ifndef PIPELINE_H
#define PIPELINE_H

#include "../globals.h"
#include "../context.h"
#include "renderPass.h"

enum PipelineType {
    GRAPHICS_PIPELINE,
    COMPUTE_PIPELINE
};

struct PipelineConfig {
    PipelineConfig(const PipelineConfig&) = delete;
    PipelineConfig& operator=(const PipelineConfig&) = delete;

    VkRenderPass renderPass;
    VkShaderModule vertShaderModule;
    VkShaderModule fragShaderModule;
    VkPipelineVertexInputStateCreateInfo vertexInput{};
    VkPipelineInputAssemblyStateCreateInfo inputAssembly{}; 
    VkPipelineViewportStateCreateInfo viewportState{};
    VkPipelineRasterizationStateCreateInfo rasterizer{};
    VkPipelineMultisampleStateCreateInfo multisampling{};
    VkPipelineColorBlendStateCreateInfo colorBlending{};
    VkPipelineDepthStencilStateCreateInfo depthStencil{};
};

class Pipeline{
    public:
        VkResult init(Context& context, PipelineType type, PipelineConfig& config);
        void cleanup(Context& context);

        VkDescriptorSetLayout descriptorSetLayout;
        VkPipeline pipeline;
        VkPipelineLayout pipelineLayout;

    private:
        VkResult createGraphicsPipeline(Context& context, PipelineConfig& config);
        VkResult createComputePipeline(Context& context, PipelineConfig& config);

};


VkPipelineVertexInputStateCreateInfo getVertexInput();
VkPipelineInputAssemblyStateCreateInfo getInputAssembly();
VkPipelineViewportStateCreateInfo getViewportState();
VkPipelineRasterizationStateCreateInfo getRasterizer();
VkPipelineMultisampleStateCreateInfo getMultisampling();
VkPipelineColorBlendStateCreateInfo getColorBlending();
VkPipelineDepthStencilStateCreateInfo getDepthStencil();
VkPipelineLayoutCreateInfo getPipelineLayoutInfo(VkDescriptorSetLayout& descriptorSetLayout);

#endif // PIPELINE_H
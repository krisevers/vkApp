#include "renderer.h"
#include "shader.h"
#include "pipeline.h"
#include "descriptorSetLayout.h"

VkResult Renderer::init(Context& context, GLFWwindow* window) {

    // setup swapchain and renderpass
    swapChain.init(context, window);
    renderPass.init(context, swapChain.swapChainImageFormat);
    swapChain.createDepthResources(context);
    swapChain.createFramebuffers(context, renderPass.get());

    // create descriptor set layout
    VkDescriptorSetLayoutBinding uboLayoutBinding = createDescriptorSetLayoutBinding(0, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, 1, VK_SHADER_STAGE_VERTEX_BIT, nullptr);
    VkDescriptorSetLayoutBinding samplerLayoutBinding = createDescriptorSetLayoutBinding(1, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1, VK_SHADER_STAGE_FRAGMENT_BIT, nullptr);
    std::vector<VkDescriptorSetLayoutBinding> bindings = {uboLayoutBinding, samplerLayoutBinding};
    createDescriptorSetLayout(context.device, bindings, pipeline.descriptorSetLayout);

    // create graphics pipeline
    auto vertShaderCode = readFile("resources/shaders/shader.vert");
    auto fragShaderCode = readFile("resources/shaders/shader.frag");
    PipelineConfig pipelineConfig = {};
    pipelineConfig.vertShaderModule = createShaderModule(vertShaderCode, context.device);
    pipelineConfig.fragShaderModule = createShaderModule(vertShaderCode, context.device);
    pipelineConfig.vertexInput = getVertexInput();
    pipelineConfig.inputAssembly = getInputAssembly();
    pipelineConfig.viewportState = getViewportState();
    pipelineConfig.rasterizer = getRasterizer();
    pipelineConfig.multisampling = getMultisampling();
    pipelineConfig.colorBlending = getColorBlending();
    pipelineConfig.depthStencil = getDepthStencil();
    pipelineConfig.renderPass = renderPass.get();
    pipeline.init(context, GRAPHICS_PIPELINE, pipelineConfig);

    return VK_SUCCESS;
}

void Renderer::cleanup(Context& context) {
    pipeline.cleanup(context);
    renderPass.cleanup(context);
    swapChain.cleanup(context);
}
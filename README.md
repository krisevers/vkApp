# vkApp

## Application Flow with Ownership in Mind

Here’s a high-level overview of how everything fits together:

1. Startup
    * VulkanContext is initialized (instance, device, swapchain, render pass, depth resources).
    * PipelineManager loads and compiles shaders into graphics & compute pipelines.
    * ResourceManager loads meshes & textures.
    * Renderer creates framebuffers, command buffers, and synchronization objects.

2. Per Frame
    * Acquire swapchain image.
    * Reset command buffer.
    * Record command buffer:
    * Bind render pass.
    * Bind descriptor sets (via DescriptorAllocator).
    * Draw meshes (via ResourceManager).
    * Submit command buffer to GPU.
    * Present swapchain image.

3. Shutdown
    * Destroy Vulkan resources in reverse order (first small objects like pipelines, then big ones like swapchain, device, instance).
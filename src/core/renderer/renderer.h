#ifndef RENDERER_H
#define RENDERER_H

#include "../globals.h"
#include "../context.h"

#include "renderPass.h"
#include "swapchain.h"
#include "pipeline.h"

class Renderer {
    public:
        VkResult init(Context& context, GLFWwindow* window);
        void cleanup(Context& context);
        void draw();


    private:
        SwapChain swapChain;
        RenderPass renderPass;
        Pipeline pipeline;
        
};

#endif // RENDERER_H
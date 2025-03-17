#ifndef RENDERPASS_H
#define RENDERPASS_H

#include "../globals.h"

#include "swapchain.h"

class RenderPass {
    public:
        VkResult init(Context& context, VkFormat swapChainImageFormat);
        void cleanup(Context& context);

        VkRenderPass get() {
            return renderPass;
        }

    private:
        VkRenderPass renderPass;
};


#endif // RENDERPASS_H
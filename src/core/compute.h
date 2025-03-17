#ifndef COMPUTE_H
#define COMPUTE_H

#include "globals.h"

class Compute {
    
    public:
        VkResult init();
        void cleanup();


    private:
        VkCommandPool commandPool;
        std::vector<VkCommandBuffer> commandBuffers;

        std::vector<VkBuffer> buffers;
        std::vector<VkDeviceMemory> bufferMemory;
        
};

#endif // COMPUTE_H
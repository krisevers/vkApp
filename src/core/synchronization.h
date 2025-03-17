#ifndef SYNCHRONIZATION_H
#define SYNCHRONIZATION_H

#include "globals.h"
#include "context.h"

class Synchronization {
    public:
        VkResult init(Context& context, uint32_t maxFramesInFlight);
        void cleanup(Context& context);
        
        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkSemaphore> computeFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        std::vector<VkFence> computeInFlightFences;

    private:
        uint32_t maxFramesInFlight;
    };

#endif // SYNCHRONIZATION_H
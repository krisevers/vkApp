#ifndef DESCRIPTORALLOCATOR_H
#define DESCRIPTORALLOCATOR_H

#include "globals.h"

struct DescriptorAllocator {
    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> allocatedSets;

    VkDescriptorSet allocateDescriptorSet(VkDescriptorSetLayout layout);
};

#endif // DESCRIPTORALLOCATOR_H
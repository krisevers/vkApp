#ifndef DESCRIPTORSETLAYOUT_H
#define DESCRIPTORSETLAYOUT_H

#include "../globals.h"

VkResult createDescriptorSetLayout(VkDevice device, std::vector<VkDescriptorSetLayoutBinding> bindings, VkDescriptorSetLayout& descriptorSetLayout);
void cleanupDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout);

VkDescriptorSetLayoutBinding createDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, uint32_t descriptorCount, VkShaderStageFlags stageFlags, VkSampler* pImmutableSamplers);

#endif // DESCRIPTORSETLAYOUT_H
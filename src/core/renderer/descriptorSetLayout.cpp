#include "descriptorSetLayout.h"

VkResult createDescriptorSetLayout(VkDevice device, std::vector<VkDescriptorSetLayoutBinding> bindings, VkDescriptorSetLayout& descriptorSetLayout) {

    VkDescriptorSetLayoutCreateInfo layoutInfo{};
    layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
    layoutInfo.pBindings = bindings.data();

    if (vkCreateDescriptorSetLayout(device, &layoutInfo, nullptr, &descriptorSetLayout) != VK_SUCCESS) {
        throw std::runtime_error("failed to create descriptor set layout!");
    }

    return VK_SUCCESS;
}

void cleanupDescriptorSetLayout(VkDevice device, VkDescriptorSetLayout descriptorSetLayout) {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
}

//----------------------------------------------------------------//

VkDescriptorSetLayoutBinding createDescriptorSetLayoutBinding(uint32_t binding, VkDescriptorType descriptorType, uint32_t descriptorCount, VkShaderStageFlags stageFlags, VkSampler* pImmutableSamplers)
{
    VkDescriptorSetLayoutBinding layoutBinding{};
    layoutBinding.binding = binding;
    layoutBinding.descriptorType = descriptorType;
    layoutBinding.descriptorCount = descriptorCount;
    layoutBinding.stageFlags = stageFlags;
    layoutBinding.pImmutableSamplers = nullptr;
    return layoutBinding;
}

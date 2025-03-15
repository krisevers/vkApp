#include "vkDebug.h"

VkResult setupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT& debugMessenger) {
    if (!enableValidationLayers) return VK_SUCCESS;

    VkDebugUtilsMessengerCreateInfoEXT createInfo;
    populateDebugMessengerCreateInfo(createInfo);

    if (CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
        throw std::runtime_error("failed to set up debug messenger!");
    }

    return VK_SUCCESS;
}

void cleanupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger) {
    if (!enableValidationLayers) return;

    DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
}
#include "vkContext.h"

#include "vkInstance.h"
#include "vkDebug.h"
#include "vkSurface.h"
#include "vkPhysicalDevice.h"
#include "vkDevice.h"
#include "vkSwapChain.h"
#include "vkImageViews.h"

VkResult initializeVulkanContext(VulkanContext& context, GLFWwindow* window)
{
    context.instance = VK_NULL_HANDLE;
    context.debugMessenger = VK_NULL_HANDLE;
    context.surface = VK_NULL_HANDLE;
    context.physicalDevice = VK_NULL_HANDLE;
    context.device = VK_NULL_HANDLE;
    context.graphicsQueue = VK_NULL_HANDLE;
    context.presentQueue = VK_NULL_HANDLE;
    context.computeQueue = VK_NULL_HANDLE;
    context.swapChain = VK_NULL_HANDLE;

    if (createInstance(context.instance) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (setupDebugMessenger(context.instance, context.debugMessenger) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (createSurface(context.instance, window, context.surface) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (pickPhysicalDevice(context.instance, context.surface, context.physicalDevice) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (createLogicalDevice(context.physicalDevice, context.surface, context.device, context.graphicsQueue, context.presentQueue, context.computeQueue) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (createSwapChain(context.physicalDevice, context.device, context.surface, window, 
                         context.swapChain, context.swapChainImages, context.swapChainImageViews, context.swapChainImageFormat, context.swapChainExtent) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    if (createImageViews(context.device, context.swapChainImageViews, context.swapChainImages, context.swapChainImageFormat) != VK_SUCCESS)
    {
        return VK_ERROR_INITIALIZATION_FAILED;
    }

    return VK_SUCCESS;
}

void cleanupVulkanContext(VulkanContext& context)
{
    cleanupSwapChain(context.device, context.swapChain, context.swapChainImageViews);
    cleanupLogicalDevice(context.device);
    cleanupDebugMessenger(context.instance, context.debugMessenger);
    cleanupSurface(context.instance, context.surface);
    cleanupInstance(context.instance);
}

//----------------------------------------------------------------//


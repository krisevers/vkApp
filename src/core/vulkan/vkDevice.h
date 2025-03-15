#ifndef VKDEVICE_H
#define VKDEVICE_H

#include "../globals.h"

VkResult createLogicalDevice(VkPhysicalDevice& physicalDevice, 
                        VkSurfaceKHR& surface,
                        VkDevice& device, 
                        VkQueue& graphicsQueue, 
                        VkQueue& presentQueue, 
                        VkQueue& computeQueue);
void cleanupLogicalDevice(VkDevice& device);

#endif // VKDEVICE_H
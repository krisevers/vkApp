#ifndef PHYSICALDEVICE_H
#define PHYSICALDEVICE_H

#include "../globals.h"

VkResult pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface, VkPhysicalDevice& physicalDevice);
bool isDeviceSuitable(VkPhysicalDevice device, VkSurfaceKHR surface);

#endif // PHYSICALDEVICE_H
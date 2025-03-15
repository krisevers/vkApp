#ifndef VKSURFACE_H
#define VKSURFACE_H

#include "../globals.h"

VkResult createSurface(VkInstance instance, GLFWwindow* window, VkSurfaceKHR& surface);
void cleanupSurface(VkInstance instance, VkSurfaceKHR surface);

#endif // VKSURFACE_H
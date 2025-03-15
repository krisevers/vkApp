#ifndef VKDEBUG_H
#define VKDEBUG_H

#include "../globals.h"

VkResult setupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT& debugMessenger);
void cleanupDebugMessenger(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger);

#endif // VKDEBUG_H
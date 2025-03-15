#ifndef VKINSTANCE_H
#define VKINSTANCE_H

#include "../globals.h"

VkResult createInstance(VkInstance& instance);
void cleanupInstance(VkInstance instance);

#endif // VKINSTANCE_H
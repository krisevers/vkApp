#ifndef SHADER_H
#define SHADER_H

#include "../globals.h"

#include <vector>

VkShaderModule createShaderModule(const std::vector<char>& code, VkDevice device);

#endif // SHADER_H
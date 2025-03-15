#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/hash.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

#include <iostream>
#include <vector>

const std::string OBJ_PATH = "../data/models/Ice Rock.obj";
const std::string MTL_PATH = "../data/materials/Ice Rock.mtl";

tinyobj::attrib_t attrib;
std::vector<tinyobj::shape_t> shapes;
std::vector<tinyobj::material_t> materials;

std::string warn;
std::string err;

void loadModel() {
    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, OBJ_PATH.c_str())) {
        throw std::runtime_error(warn + err);
    }
}

int main() {
    loadModel();
    return 0;
}
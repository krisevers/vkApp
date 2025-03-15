#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "globals.h"

struct Mesh {
    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;
};

struct Texture {
    VkImage image;
    VkImageView imageView;
    VkDeviceMemory memory;
    VkSampler sampler;
};

struct ResourceManager {
    std::vector<Mesh> meshes;
    std::vector<Texture> textures;

    Mesh loadMesh(std::string path);
    Texture loadTexture(std::string path);

};

#endif // RESOURCEMANAGER_H
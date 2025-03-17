#ifndef C_MESH_H
#define C_MESH_H

#include "../globals.h"

#include <vector>

struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;
};

#endif // C_MESH_H
#pragma once

#include "../Maths/maths.h"
#include <stdint.h>

class Mesh
{
public:

    enum Flags
    {
        Initialized = 1 << 0,
        HasVertices = 1 << 1,
        HasIndices = 1 << 2,
        Dirty = 1 << 3,
        Uploaded = 1 << 4,
        HasTexCoords = 1 << 5,
        HasNormals = 1 << 6,
        HasColors = 1 << 7
    };

    Mesh();
    ~Mesh();
    void copyVertices(const Vec3 *vertices, uint32_t count);
    void copyIndices(const uint16_t *indices, uint32_t count);
    void copyTexCoords(const Vec3 *coords, uint32_t count);
    void copyColors(const Vec4 *colors, uint32_t count);
    void calculateNormals();

    uint16_t flags;
    uint16_t numVertices;
    uint32_t numIndices;
    uintptr_t rendererHandle;
    // ugly IKR
    uintptr_t rendererHandle2;
    uintptr_t rendererHandle3;
    Vec3 *vertices;
    Vec3 *texCoords;
    Vec3 *normals;
    Vec4 *colors;
    uint16_t *indices;
};

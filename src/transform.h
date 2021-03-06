#pragma once

#include "Maths/maths.h"

class Transform
{
public:
    Transform();
    Mat4 getModelMatrix();
    Vec3 forward();
    Vec3 right();

    Vec3 position;
    Quaternion rotation;
    Vec3 scale;
};

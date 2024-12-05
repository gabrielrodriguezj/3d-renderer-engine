/*
 * Class that performs the perspective projection.
 */

#ifndef INC_3D_RENDERER_ENGINE_PERSPECTIVE_H
#define INC_3D_RENDERER_ENGINE_PERSPECTIVE_H


#include "../vector/vector2.h"
#include "../config.h"
#include "../vector/vector3.h"
#include "projection.h"

class Perspective: virtual public Projection{
public:
    Perspective(RenderConfiguration);
    vec2_t project(vec3_t);
};

#endif //INC_3D_RENDERER_ENGINE_PERSPECTIVE_H

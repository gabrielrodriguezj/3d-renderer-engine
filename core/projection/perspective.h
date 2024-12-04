/*
 * Class that performs the perspective projection.
 */

#ifndef INC_3D_RENDERER_ENGINE_PERSPECTIVE_H
#define INC_3D_RENDERER_ENGINE_PERSPECTIVE_H


#include "../vector/vector.h"
#include "../config.h"

class Perspective {
public:
    Perspective(RenderConfiguration);
    vec2_t project(vec3_t);
private:
    RenderConfiguration config;
};

#endif //INC_3D_RENDERER_ENGINE_PERSPECTIVE_H

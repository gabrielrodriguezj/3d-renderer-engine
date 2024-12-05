#ifndef INC_3D_RENDERER_ENGINE_VECTOR3_H
#define INC_3D_RENDERER_ENGINE_VECTOR3_H

#include "vector4.h"

struct vec3_t{
    float x;
    float y;
    float z;

    vec4_t toVec4(){
        vec4_t vec4 = {
                .x = x,
                .y = y,
                .z = z,
                .w = 1.0
        };
        return vec4;
    }

    void fromVec4(vec4_t vec4){
        x = vec4.x;
        y = vec4.y;
        z = vec4.z;
    }
};

#endif //INC_3D_RENDERER_ENGINE_VECTOR3_H

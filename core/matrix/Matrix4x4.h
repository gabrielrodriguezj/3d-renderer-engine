/*
 * Define the structure of a 4x4 matrix
 */

#ifndef INC_3D_RENDERER_ENGINE_MATRIX4X4_H
#define INC_3D_RENDERER_ENGINE_MATRIX4X4_H

#include "../vector/Vector.h"

struct mat4_t {
    float m[4][4];

    mat4_t(){}

    mat4_t& operator *(const mat4_t& o)
    {
        mat4_t result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = this->m[i][0] * o.m[0][j] + this->m[i][1] * o.m[1][j] + this->m[i][2] * o.m[2][j] + this->m[i][3] * o.m[3][j];
            }
        }
        return result;

    }

    vec4_t& operator *(const vec4_t & v){
        vec4_t result;
        result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
        result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
        result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
        result.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m|   [3][3] * v.w;
        return result;
    }
};

#endif //INC_3D_RENDERER_ENGINE_MATRIX4X4_H

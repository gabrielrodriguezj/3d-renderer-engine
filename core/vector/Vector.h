/*
 * Contains the different vectors used throughout the engine
 */

#ifndef INC_3D_RENDERER_ENGINE_VECTOR_H
#define INC_3D_RENDERER_ENGINE_VECTOR_H

typedef struct {
    float x;
    float y;
} vec2_t;

typedef struct {
    float x;
    float y;
    float z;
} vec3_t;

typedef struct {
    float x;
    float y;
    float z;
    float w;
} vec4_t;

#endif //INC_3D_RENDERER_ENGINE_VECTOR_H

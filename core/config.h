/*
 * This structure contains the global information for the rendering.
 * Size of the screen, fov, zfar, znear and FPS
 */
#ifndef INC_3D_RENDERER_ENGINE_CONFIG_H
#define INC_3D_RENDERER_ENGINE_CONFIG_H

typedef struct {
    int width;
    int height;
    float fov;
    float znear;
    float zfar;
    int fps;
} RenderConfiguration;

#endif //INC_3D_RENDERER_ENGINE_CONFIG_H

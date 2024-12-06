/*
 * This class allows draw the vertices of a 3D model as a cloud of points.
 * This is only for testing purpose. It helps to test the load model function, the
 * SDL window updating process, etc.
 */

#ifndef INC_3D_RENDERER_ENGINE_CLOUD_H
#define INC_3D_RENDERER_ENGINE_CLOUD_H


#include "renderer.h"

class Cloud: virtual public Renderer{
public:
    void render(Canvas, Model, Projection*) override;
};


#endif //INC_3D_RENDERER_ENGINE_CLOUD_H

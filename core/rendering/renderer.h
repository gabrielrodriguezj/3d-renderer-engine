/*
 * The base class for all the rendering techniques.
 */

#ifndef INC_3D_RENDERER_ENGINE_RENDERER_H
#define INC_3D_RENDERER_ENGINE_RENDERER_H


#include <iostream>
#include "../canvas.h"
#include "../model/model.h"
#include "../projection/projection.h"

class Renderer {
public:
    virtual void render(Canvas, Model, Projection*){}
};


#endif //INC_3D_RENDERER_ENGINE_RENDERER_H

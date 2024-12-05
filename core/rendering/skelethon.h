/*
 * Rendering techniques used to display the edges of a 3D model.
 */

#ifndef INC_3D_RENDERER_ENGINE_SKELETHON_H
#define INC_3D_RENDERER_ENGINE_SKELETHON_H


#include "renderer.h"

class Skelethon: virtual public Renderer{
public:
    void render(Canvas, Model, Projection*);
};


#endif //INC_3D_RENDERER_ENGINE_SKELETHON_H

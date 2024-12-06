/*
 * This class implements the scanline technique to draw triangles of a 3D model.
 */

#ifndef INC_3D_RENDERER_ENGINE_FLAT_H
#define INC_3D_RENDERER_ENGINE_FLAT_H


#include "renderer.h"
#include "../primitives/line/line.h"

class Flat: virtual public Renderer{
public:
    void render(Canvas, Model, Projection*);

private:
    Canvas canvas;
    void swap(int* a, int* b);
    void fillFlatBottomTriangle(int, int, int, int, int, int, color_t, Line*);
    void fillFlatTopTriangle(int, int, int, int, int, int, color_t, Line*);
    void drawFilledTriangle(int, int, int, int, int, int, color_t);
};


#endif //INC_3D_RENDERER_ENGINE_FLAT_H

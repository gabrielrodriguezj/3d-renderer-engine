/*
 * This class implements the scanline technique to draw triangles of a 3D model.
 */

#ifndef INC_3D_RENDERER_ENGINE_FLAT_H
#define INC_3D_RENDERER_ENGINE_FLAT_H


#include "renderer.h"
#include "../primitives/line/line.h"

class Flat: virtual public Renderer{
public:
    void render(Canvas, Model, Projection*) override;

private:
    static void swap(int* a, int* b);
    static void fillFlatBottomTriangle(Canvas, int, int, int, int, int, int, color_t, Line*);
    static void fillFlatTopTriangle(Canvas, int, int, int, int, int, int, color_t, Line*);
    static void drawFilledTriangle(Canvas, int, int, int, int, int, int, color_t);
};


#endif //INC_3D_RENDERER_ENGINE_FLAT_H

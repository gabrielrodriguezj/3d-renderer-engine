#ifndef INC_3D_RENDERER_ENGINE_BRESENHAM_H
#define INC_3D_RENDERER_ENGINE_BRESENHAM_H


#include "Line.h"

class Bresenham: virtual public Line {
public:
    void draw(Canvas, int, int, int, int, color_t);
};


#endif //INC_3D_RENDERER_ENGINE_BRESENHAM_H

/*
 * Implementation of Middle-Point algorithm for line drawing.
 */

#ifndef INC_3D_RENDERER_ENGINE_MIDPOINT_H
#define INC_3D_RENDERER_ENGINE_MIDPOINT_H


#include "Line.h"

class MidPoint: virtual public Line {
public:
    void draw(Canvas, int, int, int, int, color_t);
};


#endif //INC_3D_RENDERER_ENGINE_MIDPOINT_H

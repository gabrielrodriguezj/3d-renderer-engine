/*
 * Implementation of DDA algorithm for line drawing.
 */

#ifndef INC_3D_RENDERER_ENGINE_DDA_H
#define INC_3D_RENDERER_ENGINE_DDA_H


#include "Line.h"

class DDA: virtual public Line {
public:
    void draw(Canvas, int, int, int, int, color_t);
};


#endif //INC_3D_RENDERER_ENGINE_DDA_H

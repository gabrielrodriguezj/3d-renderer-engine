#ifndef INC_3D_RENDERER_ENGINE_LINE_H
#define INC_3D_RENDERER_ENGINE_LINE_H


#include "../../color.h"
#include "../../canvas.h"

class Line {
public:
    virtual void draw(Canvas, int, int, int, int, color_t){}
};


#endif //INC_3D_RENDERER_ENGINE_LINE_H

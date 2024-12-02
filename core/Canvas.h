#ifndef INC_3D_RENDERER_ENGINE_CANVAS_H
#define INC_3D_RENDERER_ENGINE_CANVAS_H


#include "Color.h"

class Canvas {

public:
    Canvas(int, int);
    void drawPixel(int, int, color_t);
private:
    color_t * color_buffer;
    int width;
    int height;
};


#endif //INC_3D_RENDERER_ENGINE_CANVAS_H

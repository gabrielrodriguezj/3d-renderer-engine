#ifndef INC_3D_RENDERER_ENGINE_CANVAS_H
#define INC_3D_RENDERER_ENGINE_CANVAS_H


#include "color.h"

class Canvas {

public:
    Canvas(int, int);
    void drawPixel(int, int, color_t);
    void drawRect(int, int, int, int, color_t);
    void drawGrid(void);
    color_t *getBuffer(void);
    void clear(color_t);
private:
    color_t * color_buffer;
    int width;
    int height;
};


#endif //INC_3D_RENDERER_ENGINE_CANVAS_H

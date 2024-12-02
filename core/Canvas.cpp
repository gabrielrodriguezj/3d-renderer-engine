#include <cstdlib>
#include "Canvas.h"
Canvas::Canvas(int width, int height) {
    this->width = width;
    this->height = height;

    // Allocate the required memory in bytes to hold the color buffer
    color_buffer = (uint32_t*) malloc(sizeof (color_t) * this->width * this->height);
}

void Canvas::drawPixel(int x, int y, color_t color) {
    if(x>=0 && x<this->width && y>=0 && y<this->height){
        color_buffer[(this->width * y) + x] = color;
    }
}


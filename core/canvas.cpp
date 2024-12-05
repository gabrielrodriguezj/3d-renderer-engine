#include <cstdlib>
#include "canvas.h"
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

void Canvas::drawRect(int x, int y, int width, int height, color_t color){
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int current_x = x + i;
            int current_y = y + j;
            drawPixel(current_x, current_y, color);
        }
    }
}

void Canvas::drawGrid(void) {
    for (int y = 0; y < this->height; y++) {
        for (int x = 0; x < this->width; x++) {
            if (x % 10 == 0 || y % 10 == 0) {
                color_buffer[(this->width * y) + x] = 0xFF444444;
            }
        }
    }
}

color_t *Canvas::getBuffer(void){
    return this->color_buffer;
}

void Canvas::clear(color_t color) {
    for(int i = 0; i < this->width * this->height; i++){
        color_buffer[i] = color;
    }
}

void clear_color_buffer(uint32_t color){


}

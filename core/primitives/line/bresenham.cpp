#include "bresenham.h"

void Bresenham::draw(Canvas canvas, int x0, int y0, int x1, int y1, color_t color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = 2 * (dy - dx); // initial value of decision parameter

    int x = x0;
    int y = y0;

    for (; x <= x1; x++) {

        // the East pixel is chosen
        if(d < 0){
            d = d + 2*dy;
        }
        // the NEast pixel is chosen
        else{
            y = y+1;
            d = d + 2*dy - 2*dx;
        }
        canvas.drawPixel(x, y, color);
    }
}
#include "middle_point.h"


void MidPoint::draw(Canvas canvas, int x0, int y0, int x1, int y1, color_t color) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int d = dy - (dx / 2.0); // initial value of decision parameter

    int x = x0;
    int y = y0;

    for (; x <= x1; x++) {

        // the East pixel is chosen
        if(d < 0){
            d += dy;
        }
        // the NEast pixel is chosen
        else{
            d += (dy - dx);
            y++;
        }
        canvas.drawPixel(x, y, color);
    }
}

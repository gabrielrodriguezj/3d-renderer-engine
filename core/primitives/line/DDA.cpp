#include "DDA.h"
#include "math.h"

void DDA::draw(Canvas canvas, int x0, int y0, int x1, int y1, color_t color) {
    int delta_x = (x1 - x0);
    int delta_y = (y1 - y0);

    int longest_side_length = (abs(delta_x) >= abs(delta_y)) ? abs(delta_x) : abs(delta_y);

    float x_inc = delta_x / (float)longest_side_length;
    float y_inc = delta_y / (float)longest_side_length;

    float current_x = x0;
    float current_y = y0;
    for (int i = 0; i <= longest_side_length; i++) {
        canvas.drawPixel(round(current_x), round(current_y), color);
        current_x += x_inc;
        current_y += y_inc;
    }
}

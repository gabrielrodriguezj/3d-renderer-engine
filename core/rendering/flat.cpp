#include "flat.h"
#include "../primitives/line/dda.h"

void Flat::render(Canvas canvas, Model model, Projection *projecter) {

    std::vector<vec2_t> projectedPoints;

    for (vec3_t vertex: model.getVertices()) {
        vec2_t projectedPoint = projecter->project(vertex);
        projectedPoints.push_back(projectedPoint);
    }

    this->canvas = canvas;
}

void Flat::swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
 * Draw a filled triangle with the flat-top/flat-bottom method
 * We split the original triangle in two, half flat-bottom and half flat-top
 *
 *          (x0,y0)
 *            / \
 *           /   \
 *          /     \
 *         /       \
 *        /         \
 *   (x1,y1)------(Mx,My)
 *       \_           \
 *          \_         \
 *             \_       \
 *                \_     \
 *                   \    \
 *                     \_  \
 *                        \_\
 *                           \
 *                         (x2,y2)
 *
 */
void Flat::drawFilledTriangle(int x0, int y0, int x1, int y1, int x2, int y2, color_t color) {
    Line *line = new DDA();

    // We need to sort the vertices by y-coordinate ascending (y0 < y1 < y2)
    if (y0 > y1) {
        swap(&y0, &y1);
        swap(&x0, &x1);
    }
    if (y1 > y2) {
        swap(&y1, &y2);
        swap(&x1, &x2);
    }
    if (y0 > y1) {
        swap(&y0, &y1);
        swap(&x0, &x1);
    }

    if (y1 == y2) {
        // Draw flat-bottom triangle
        fillFlatBottomTriangle(x0, y0, x1, y1, x2, y2, color, line);
    } else if (y0 == y1) {
        // Draw flat-top triangle
        fillFlatTopTriangle(x0, y0, x1, y1, x2, y2, color, line);
    } else {
        // Calculate the new vertex (Mx,My) using triangle similarity
        int My = y1;
        int Mx = (((x2 - x0) * (y1 - y0)) / (y2 - y0)) + x0;

        // Draw flat-bottom triangle
        fillFlatBottomTriangle(x0, y0, x1, y1, Mx, My, color, line);

        // Draw flat-top triangle
        fillFlatTopTriangle(x1, y1, Mx, My, x2, y2, color, line);
    }



}

/*
 * Draw a filled a triangle with a flat bottom
 *
 *        (x0,y0)
 *          / \
 *         /   \
 *        /     \
 *       /       \
 *      /         \
 *  (x1,y1)------(x2,y2) = (Mx, My)
 *
 */
void Flat::fillFlatBottomTriangle(int x0, int y0, int x1, int y1, int x2, int y2, color_t color, Line *line) {
    // Find the two slopes (two triangle legs)
    float invSlope1 = (float)(x1 - x0) / (float) (y1 - y0);
    float invSlope2 = (float)(x2 - x0) / (float) (y2 - y0);

    // Start x_start and x_end from the top vertex (x0,y0)
    auto xStart = (float)x0;
    auto xEnd = (float)x0;

    // Loop all the scanlines from top to bottom
    for (int y = y0; y <= y2; y++) {
        line->draw(canvas, (int)xStart, y, (int)xEnd, y, color);
        xStart += invSlope1;
        xEnd += invSlope2;
    }
}

/*
 * Draw a filled a triangle with a flat top
 *
 *   (x1,y1)------(Mx,My)
 *       \_           \
 *          \_         \
 *             \_       \
 *                \_     \
 *                   \    \
 *                     \_  \
 *                        \_\
 *                           \
 *                         (x2,y2)
 */
void Flat::fillFlatTopTriangle(int x0, int y0, int x1, int y1, int x2, int y2, color_t color, Line *line) {
    // Find the two slopes (two triangle legs)
    float invSlope1 = (float)(x2 - x0) / (float)(y2 - y0);
    float invSlope2 = (float)(x2 - x1) / (float)(y2 - y1);

    // Start x_start and x_end from the bottom vertex (x2,y2)
    auto xStart = (float)x2;
    auto xEnd = (float)x2;

    // Loop all the scanlines from bottom to top
    for (int y = y2; y >= y0; y--) {
        line->draw(canvas, (int)xStart, y, (int)xEnd, y, color);
        xStart -= invSlope1;
        xEnd -= invSlope2;
    }
}

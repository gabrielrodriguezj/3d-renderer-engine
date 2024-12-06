#include "cloud.h"

void Cloud::render(Canvas canvas, Model model, Projection *projector) {

    for (vec3_t vertex: model.getVertices()) {
        vec2_t projectedPoint = projector->project(vertex);

        canvas.drawRect((int)projectedPoint.x - 3, (int)projectedPoint.y - 3, 6, 6, 0xFF00FFFF);
    }
}

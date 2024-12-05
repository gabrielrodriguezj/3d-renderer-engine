#include "cloud.h"

void Cloud::render(Canvas canvas, Model model, Projection *projecter) {

    for (vec3_t vertex: model.getVertices()) {
        vec2_t projectedPoint = projecter->project(vertex);

        canvas.drawRect(projectedPoint.x - 3, projectedPoint.y - 3, 6, 6, 0xFF00FFFF);
    }
}

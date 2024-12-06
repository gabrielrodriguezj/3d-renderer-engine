#include "skelethon.h"
#include "../primitives/line/bresenham.h"
#include "../primitives/line/dda.h"

void Skelethon::render(Canvas canvas, Model model, Projection *projector) {

    std::vector<vec2_t> projectedPoints;

    for (vec3_t vertex: model.getVertices()) {
        vec2_t projectedPoint = projector->project(vertex);
        projectedPoints.push_back(projectedPoint);
    }

    Line *line = new DDA();

    for(face_t face: model.getFaces()){
        vec2_t vertex1 = projectedPoints.at(face.a);
        vec2_t vertex2 = projectedPoints.at(face.b);
        vec2_t vertex3 = projectedPoints.at(face.c);

        line->draw(canvas, vertex1.x, vertex1.y, vertex2.x, vertex2.y, 0xFFFFFFFF);
        line->draw(canvas, vertex2.x, vertex2.y, vertex3.x, vertex3.y, 0xFFFFFFFF);
        line->draw(canvas, vertex3.x, vertex3.y, vertex1.x, vertex1.y, 0xFFFFFFFF);
    }
}
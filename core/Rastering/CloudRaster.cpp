#include "CloudRaster.h"
#include "../projection/PerspectiveProjection.h"

void CloudRaster::raster(Canvas canvas, Model model){
    //std::vector<vec2_t> projectedPoints;

    PerspectiveProjection projecter;

    for (vec3_t & vertex : model.getVertices()) {
        vec2_t projectedPoint = projecter.project(vertex);

        //projectedPoints.push_back(projectedPoint);
        canvas.drawRect(projectedPoint.x - 3, projectedPoint.y - 3, 6, 6, 0xFFFF0000);
    }







}

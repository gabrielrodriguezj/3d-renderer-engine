/*
 * This class allows draw the vertices of a 3D model as a cloud of points.
 */

#ifndef INC_3D_RENDERER_ENGINE_CLOUDRASTER_H
#define INC_3D_RENDERER_ENGINE_CLOUDRASTER_H


#include "../model/Model.h"
#include "../Canvas.h"

class CloudRaster {
public:
    void raster(Canvas, Model);
};


#endif //INC_3D_RENDERER_ENGINE_CLOUDRASTER_H

/*
 * This class allows draw the vertices of a 3D model as a cloud of points.
 * This is only for testing purpose. It helps to test the load model function, the
 * SDL window updating process, etc.
 */

#ifndef INC_3D_RENDERER_ENGINE_CLOUD_H
#define INC_3D_RENDERER_ENGINE_CLOUD_H


#include "../model/model.h"
#include "../canvas.h"
#include "../projection/perspective.h"

class Cloud {
public:
    void raster(Canvas, Model, Perspective);
};


#endif //INC_3D_RENDERER_ENGINE_CLOUD_H

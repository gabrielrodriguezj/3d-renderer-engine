/*
 * The base class for the different projection approaches.
 */

#ifndef INC_3D_RENDERER_ENGINE_PROJECTION_H
#define INC_3D_RENDERER_ENGINE_PROJECTION_H

#include "../config.h"
#include "../vector/vector3.h"
#include "../vector/vector2.h"

class Projection {
public:
    Projection(RenderConfiguration renderConfiguration){
        this->renderConfiguration = renderConfiguration;
    }
    virtual vec2_t project(vec3_t){ vec2_t v; return v;}

protected:
    RenderConfiguration renderConfiguration;
};


#endif //INC_3D_RENDERER_ENGINE_PROJECTION_H

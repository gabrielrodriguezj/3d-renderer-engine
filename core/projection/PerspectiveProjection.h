/*
 * Class involved in the perspective projection.
 */

#ifndef INC_3D_RENDERER_ENGINE_PERSPECTIVEPROJECTION_H
#define INC_3D_RENDERER_ENGINE_PERSPECTIVEPROJECTION_H


#include "../vector/Vector.h"

class PerspectiveProjection {
public:
    vec2_t project(vec3_t);
};

#endif //INC_3D_RENDERER_ENGINE_PERSPECTIVEPROJECTION_H

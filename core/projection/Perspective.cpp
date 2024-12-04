#include "Perspective.h"

Perspective::Perspective(RenderConfiguration configuration): config(configuration){}

vec2_t Perspective::project(vec3_t point) {

    vec2_t projectedPoint = {
            .x = (config.fov * point.x) / point.z,
            .y = (config.fov * point.y) / point.z
    };

    projectedPoint.x += (config.width / 2);
    projectedPoint.y += (config.height / 2);
    return projectedPoint;
}
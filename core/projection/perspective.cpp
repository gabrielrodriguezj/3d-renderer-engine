#include "perspective.h"

Perspective::Perspective(RenderConfiguration renderConfiguration) : Projection(renderConfiguration) {}

vec2_t Perspective::project(vec3_t point) {

    vec2_t projectedPoint = {
            .x = (renderConfiguration.fov * point.x) / point.z,
            .y = (renderConfiguration.fov * point.y) / point.z
    };

    projectedPoint.x += (renderConfiguration.width / 2);
    projectedPoint.y += (renderConfiguration.height / 2);
    return projectedPoint;
}
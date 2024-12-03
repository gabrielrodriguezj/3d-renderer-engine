#include "PerspectiveProjection.h"

vec2_t PerspectiveProjection::project(vec3_t point) {
    float fov_factor = 720;

    vec2_t projected_point = {
            .x = (fov_factor * point.x) / point.z,
            .y = (fov_factor * point.y) / point.z
    };

    return projected_point;
}
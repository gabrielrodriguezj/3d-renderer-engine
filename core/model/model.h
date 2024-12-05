/*
 * Class that represents the internal structure of a 3D model
 */

#ifndef INC_3D_RENDERER_ENGINE_MODEL_H
#define INC_3D_RENDERER_ENGINE_MODEL_H


#include <vector>
#include "Face.h"
#include "../vector/vector3.h"

class Model {
public:
    Model(void);
    Model(std::vector<vec3_t> vertices, std::vector<face_t> faces);
    std::vector<vec3_t> getVertices();
    std::vector<face_t> getFaces();
private:
    std::vector<vec3_t> *vertices;
    std::vector<face_t> *faces;
};


#endif //INC_3D_RENDERER_ENGINE_MODEL_H

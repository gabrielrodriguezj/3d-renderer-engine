/*
 * Class that represents the internal structure of a 3D model
 */

#ifndef INC_3D_RENDERER_ENGINE_MODEL_H
#define INC_3D_RENDERER_ENGINE_MODEL_H


#include <vector>
#include "../vector/Vector.h"
#include "Face.h"

class Model {
public:
    void addVertice(vec3_t);
    void addFace(face_t);

private:
    std::vector<vec3_t> vertices;
    std::vector<face_t> faces;
};


#endif //INC_3D_RENDERER_ENGINE_MODEL_H

#include "Model.h"

void Model::addFace(face_t face) {
    faces->push_back(face);
}

void Model::addVertice(vec3_t vertex) {
    vertices->push_back(vertex);
}

std::vector<vec3_t>* Model::getVertices(){
    return vertices;
}
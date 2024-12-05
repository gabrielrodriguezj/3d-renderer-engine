#include "Model.h"

Model::Model(void){
    vertices = new std::vector<vec3_t>();
    faces = new std::vector<face_t>();
}

Model::Model(std::vector<vec3_t> v, std::vector<face_t> f) {
    vertices = new std::vector<vec3_t>();
    faces = new std::vector<face_t>();

    //copy vertices
    for(vec3_t vertex: v){
        vertices->push_back(vertex);
    }

    //copy faces
    for(face_t face: f){
        faces->push_back(face);
    }
}

std::vector<vec3_t> Model::getVertices(){
    std::vector<vec3_t> v;
    for(vec3_t vertex : *vertices){
        v.push_back(vertex);
    }

    return v;
}

std::vector<face_t> Model::getFaces() {
    std::vector<face_t> f;
    for(face_t face : *faces){
        f.push_back(face);
    }

    return f;
}
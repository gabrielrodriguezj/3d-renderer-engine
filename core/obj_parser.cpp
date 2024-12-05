#include "obj_parser.h"

#include <fstream>
#include <iostream>
#include <sstream>

Model ObjParser::readFile(char* filename) {

    std::ifstream file(filename); // input file stream object named
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        // return -1;
    }

    std::vector<vec3_t> vertices; // = new std::vector<vec3_t>();
    std::vector<face_t> faces; //= new std::vector<face_t>();

    while (getline(file, line)) {
        // Vertex information
        if (line.compare(0, 2, "v ") == 0) {
            vec3_t vertex;

            // Scan the line with the vertex information. Starts with letter v
            std::istringstream iss(line);
            std::string flag;
            iss >> flag >> vertex.x >> vertex.y >> vertex.z;

            vertices.push_back(vertex);
        }

        // Face information
        if (line.compare(0, 2, "f ") == 0) {
            int vertex_indices[3];
            int texture_indices[3];
            int normal_indices[3];

            std::istringstream iss(line);
            std::string flag;
            char slash;
            iss >> flag >> vertex_indices[0] >> slash >> texture_indices[0] >> slash >> normal_indices[0]
                        >> vertex_indices[1] >> slash >> texture_indices[1] >> slash >> normal_indices[1]
                        >> vertex_indices[2] >> slash >> texture_indices[2] >> slash >> normal_indices[2];

            // The obj model file uses index that start in 1, but C++ starts with 0
            face_t face = {
                    .a = vertex_indices[0] - 1,
                    .b = vertex_indices[1] - 1,
                    .c = vertex_indices[2] - 1,
            };
            faces.push_back(face);
        }
    }
    file.close();

    Model model(vertices, faces);
    return model;
}
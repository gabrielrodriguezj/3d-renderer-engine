#include "ObjParser.h"

#include <fstream>
#include <iostream>
#include <sstream>

int ObjParser::readFile(char* filename, Model model) {

    std::ifstream file(filename); // input file stream object named
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return -1;
    }

    while (getline(file, line)) {
        // Vertex information
        if (line.compare(0, 2, "v ") == 0) {
            vec3_t vertex;

            // Scan the line with the vertex information. Starts with letter v
            std::istringstream iss(line);
            std::string flag;
            iss >> flag >> vertex.x >> vertex.y >> vertex.z;

            model.addVertice(vertex);
        }

        // Face information
        if (line.compare(0, 2, "f ") == 0) {
            int vertex_indices[3];
            int texture_indices[3];
            int normal_indices[3];

            std::istringstream iss(line);
            std::string flag;
            iss >> flag >> vertex_indices[0] >> texture_indices[0] >> normal_indices[0]
                >> vertex_indices[1] >> texture_indices[1] >> normal_indices[1]
                >> vertex_indices[2] >> texture_indices[2] >> normal_indices[2];

            face_t face = {
                    .a = vertex_indices[0],
                    .b = vertex_indices[1],
                    .c = vertex_indices[2],
            };
            model.addFace(face);
        }
    }

    file.close();
    return 0;
}
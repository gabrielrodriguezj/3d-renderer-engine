#include "ObjParser.h"

#include <fstream>
#include <iostream>

int ObjParser::readFile(char* filename) {

    std::ifstream file(filename); // input file stream object named
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return -1;
    }

    while (getline(file, line)) {
        std::cout << line << std::endl;

        /*

         // Vertex information
        if (strncmp(line, "v ", 2) == 0) {
            vec3_t vertex;
            sscanf(line, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
            array_push(mesh.vertices, vertex);
        }
        // Face information
        if (strncmp(line, "f ", 2) == 0) {
            int vertex_indices[3];
            int texture_indices[3];
            int normal_indices[3];
            sscanf(
                    line, "f %d/%d/%d %d/%d/%d %d/%d/%d",
                    &vertex_indices[0], &texture_indices[0], &normal_indices[0],
                    &vertex_indices[1], &texture_indices[1], &normal_indices[1],
                    &vertex_indices[2], &texture_indices[2], &normal_indices[2]
            );
            face_t face = {
                    .a = vertex_indices[0],
                    .b = vertex_indices[1],
                    .c = vertex_indices[2],
                    .color = 0xFFFFFFFF
            };
            array_push(mesh.faces, face);


         */
    }

    file.close();
    return 0;
}
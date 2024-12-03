/*
 * Implementation of an obj file parser.
 */

#ifndef INC_3D_RENDERER_ENGINE_OBJPARSER_H
#define INC_3D_RENDERER_ENGINE_OBJPARSER_H


#include "model/Model.h"

class ObjParser {
public:
    int readFile(char* filename, Model);
};


#endif //INC_3D_RENDERER_ENGINE_OBJPARSER_H

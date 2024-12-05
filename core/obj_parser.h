/*
 * Implementation of an obj file parser.
 */

#ifndef INC_3D_RENDERER_ENGINE_OBJ_PARSER_H
#define INC_3D_RENDERER_ENGINE_OBJ_PARSER_H


#include "model/model.h"

class ObjParser {
public:
    Model readFile(char* filename);
};


#endif //INC_3D_RENDERER_ENGINE_OBJ_PARSER_H

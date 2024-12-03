/*
 * The structure face contains the information tha represents every face (triangle) of a 3D model.
 * Contains:
 *      - Index of the vertices.
 *      - UV coordinates
 */

#ifndef INC_3D_RENDERER_ENGINE_FACE_H
#define INC_3D_RENDERER_ENGINE_FACE_H


typedef struct {
    int a;
    int b;
    int c;
    // tex2_t a_uv;
    // tex2_t b_uv;
    // tex2_t c_uv;
} face_t;


#endif //INC_3D_RENDERER_ENGINE_FACE_H

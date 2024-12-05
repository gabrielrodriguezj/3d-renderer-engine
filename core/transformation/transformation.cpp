#include <cmath>
#include "transformation.h"

Model Transformation::transformModel(Model model, TransformationCoefficients transformationCoefficients) {
    std::vector<vec3_t> transformedVertices;// = new std::vector<vec4_t>;

    // Create scale, rotation, and translation matrices that will be used to multiply the mesh vertices
    mat4_t scaleMatrix = makeScaleMatrix(transformationCoefficients.escalationX,
                                         transformationCoefficients.escalationY,
                                         transformationCoefficients.escalationZ);
    mat4_t rotationXMatrix = makeRotationXMatrix(transformationCoefficients.rotationX);
    mat4_t rotationYMatrix = makeRotationYMatrix(transformationCoefficients.rotationY);
    mat4_t rotationZMatrix = makeRotationYMatrix(transformationCoefficients.rotationZ);
    mat4_t translationMatrix = makeTranslationMatrix(transformationCoefficients.translationX,
                                                     transformationCoefficients.translationY,
                                                     transformationCoefficients.translationZ);

    // Create a World Matrix combining scale, rotation, and translation matrices
    mat4_t worldMatrix = makeIdentityMatrix();

    // Order matters: First scale, then rotate, then translate. [T]*[R]*[S]*v
    worldMatrix = scaleMatrix * worldMatrix; //mat4_mul_mat4(scale_matrix, world_matrix);
    worldMatrix = rotationZMatrix* worldMatrix; //mat4_mul_mat4(rotation_matrix_z, world_matrix);
    worldMatrix = rotationYMatrix * worldMatrix; //mat4_mul_mat4(rotation_matrix_y, world_matrix);
    worldMatrix = rotationXMatrix * worldMatrix; //mat4_mul_mat4(rotation_matrix_x, world_matrix);
    worldMatrix = translationMatrix * worldMatrix; //mat4_mul_mat4(translation_matrix, world_matrix);

    for (vec3_t vertex: model.getVertices()) {
        vec4_t transformedVertex = vertex.toVec4();

        // Multiply the world matrix by the original vector
        transformedVertex = worldMatrix * transformedVertex; //mat4_mul_vec4(world_matrix, transformed_vertex)

        vec3_t vec3Transformed;
        vec3Transformed.fromVec4(transformedVertex);
        transformedVertices.push_back(vec3Transformed);
    }

    Model transformedModel(transformedVertices, model.getFaces());

    return transformedModel;
}

/*
 * | 1 0 0 0 |
 * | 0 1 0 0 |
 * | 0 0 1 0 |
 * | 0 0 0 1 |
 */
mat4_t Transformation::makeIdentityMatrix(void){
    mat4_t m = {{
                        {1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {0, 0, 0, 1}
                }};
    return m;
}

/*
 * | sx  0  0  0 |
 * |  0 sy  0  0 |
 * |  0  0 sz  0 |
 * |  0  0  0  1 |
 */
mat4_t Transformation::makeScaleMatrix(float sx, float sy, float sz){
    mat4_t m = makeIdentityMatrix();
    m.m[0][0] = sx;
    m.m[1][1] = sy;
    m.m[2][2] = sz;
    return m;
}

/*
 * | 1  0  0  tx |
 * | 0  1  0  ty |
 * | 0  0  1  tz |
 * | 0  0  0  1  |
 */
mat4_t Transformation::makeTranslationMatrix(float tx, float ty, float tz){
    mat4_t m = makeIdentityMatrix();
    m.m[0][3] = tx;
    m.m[1][3] = ty;
    m.m[2][3] = tz;
    return m;
}

/*
 * | 1  0  0  0 |
 * | 0  c -s  0 |
 * | 0  s  c  0 |
 * | 0  0  0  1 |
 */
mat4_t Transformation::makeRotationXMatrix(float angle){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = makeIdentityMatrix();
    m.m[1][1] = c;
    m.m[1][2] = -s;
    m.m[2][1] = s;
    m.m[2][2] = c;
    return m;
}

/*
 * |  c  0  s  0 |
 * |  0  1  0  0 |
 * | -s  0  c  0 |
 * |  0  0  0  1 |
 */
mat4_t Transformation::makeRotationYMatrix(float angle){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = makeIdentityMatrix();
    m.m[0][0] = c;
    m.m[0][2] = s;
    m.m[2][0] = -s;
    m.m[2][2] = c;
    return m;
}

/*
 * | c -s  0  0 |
 * | s  c  0  0 |
 * | 0  0  1  0 |
 * | 0  0  0  1 |
 */
mat4_t Transformation::makeRotationZMatrix(float angle){
    float c = cos(angle);
    float s = sin(angle);

    mat4_t m = makeIdentityMatrix();
    m.m[0][0] = c;
    m.m[0][1] = -s;
    m.m[1][0] = s;
    m.m[1][1] = c;
    return m;
}

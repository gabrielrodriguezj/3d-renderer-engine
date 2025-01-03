/*
 * Implementing the operations involved in the transformation process.
 */

#ifndef INC_3D_RENDERER_ENGINE_TRANSFORMATION_H
#define INC_3D_RENDERER_ENGINE_TRANSFORMATION_H

#include "../matrix/matrix.h"
#include "../model/model.h"

struct TransformationCoefficients {
    float escalationX = 1, escalationY = 1, escalationZ = 1;
    float translationX = 0, translationY = 0, translationZ = 0;
    float rotationX = 0, rotationY = 0, rotationZ = 0;
};

class Transformation {
public:
    Model transformModel(Model, TransformationCoefficients);
private:
    mat4_t makeIdentityMatrix(void);
    mat4_t makeScaleMatrix(float, float, float);
    mat4_t makeTranslationMatrix(float, float, float);
    mat4_t makeRotationXMatrix(float);
    mat4_t makeRotationYMatrix(float);
    mat4_t makeRotationZMatrix(float);
};

#endif //INC_3D_RENDERER_ENGINE_TRANSFORMATION_H

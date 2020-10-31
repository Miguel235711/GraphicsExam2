#ifndef CAR_H
#define CAR_H

#include "Operators3D.h"
#include "Drawable.h"
#include "CircularPrism.h"
#include "Cuboid.h"

class Car : public Drawable
{
    public:
        Car(GLfloat xSize, GLfloat ySize, GLfloat zSize, int partitions, Operators3D * opGlobal);
        virtual ~Car();

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
        void lowLevelDraw();

    private:
};

#endif // CAR_H

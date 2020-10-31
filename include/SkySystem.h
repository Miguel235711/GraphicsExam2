#ifndef SKYSYSTEM_H
#define SKYSYSTEM_H

#include "Operators3D.h"
#include "Drawable.h"
#include "Sphere.h"
#include "Planet.h"


class SkySystem : public Drawable
{
    public:
        SkySystem(GLfloat x, GLfloat y, GLfloat z,GLfloat r, int partitions, Operators3D * opGlobal);
        virtual ~SkySystem();

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
        void lowLevelDraw();

    private:
};

#endif // SKYSYSTEM_H

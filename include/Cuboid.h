#ifndef CUBOID_H
#define CUBOID_H

#include<iostream>

#include "Rectangle.h"
#include "Drawable.h"

class Cuboid: public Drawable
{
    public:
        Cuboid(int x,int y,int z, Operators3D * opGlobal);
        virtual ~Cuboid();

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void lowLevelDraw();
        void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);

    private:
};

#endif // CUBOID_H

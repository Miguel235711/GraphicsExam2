#ifndef CIRCULARPRISM_H
#define CIRCULARPRISM_H

#include "Drawable.h"
#include "Operators3D.h"
#include "Circle.h"

class CircularPrism : public Drawable
{
    public:
        ///in plane x,y with height y
        CircularPrism(GLfloat x,GLfloat y,GLfloat z,GLfloat r,int partitions,Operators3D * opGlobal);
        virtual ~CircularPrism();

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void lowLevelDraw();
    private:
};

#endif // CIRCULARPRISM_H

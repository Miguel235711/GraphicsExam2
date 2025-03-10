#ifndef PYRAMID_H
#define PYRAMID_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"
#include "Triangle.h"
#include "Line.h"
#include "math.h"


class Pyramid : public Drawable
{
    public:
        ///x, y stand for the coordinates in the xy plane of the pyramid peak
        Pyramid(Point peak, GLfloat height,GLfloat sideLength, Operators3D * opGlobal);
        virtual ~Pyramid();

    protected:
            void applyGlobalMatrixToPoints();
            void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
            void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
            void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
            void lowLevelDraw();
            void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
    private:
};

#endif // PYRAMID_H

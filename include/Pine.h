#ifndef PINE_H
#define PINE_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"
#include "Pyramid.h"
#include "Cuboid.h"
#include "Line.h"

class Pine : public Drawable
{
    public:
        ///x, y stand for the coordinates in the xy plane of the pyramid peak
        Pine(Point peak, GLfloat height,GLfloat sideLength, Operators3D * opGlobal);
        virtual ~Pine();

    protected:
            void applyGlobalMatrixToPoints();
            void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
            void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
            void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
            void lowLevelDraw();
            void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
    private:
};

#endif // PINE_H

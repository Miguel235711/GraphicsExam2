#ifndef BUILDING_H
#define BUILDING_H
#include "Cuboid.h"
#include "Rectangle.h"
class Building : public Drawable
{
    public:
        ///x, y stand for the coordinates in the xy plane of the pyramid peak
        Building( GLfloat height,GLfloat width, GLfloat length,  Operators3D * opGlobal);
        virtual ~Building();

    protected:
            void applyGlobalMatrixToPoints();
            void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
            void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
            void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
            void lowLevelDraw();
            void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
    private:
};


#endif // BUILDING_H

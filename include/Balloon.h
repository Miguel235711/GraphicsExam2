#ifndef BALLOON_H
#define BALLOON_H

#include "Sphere.h"
#include "CircularPrism.h"

class Balloon : public Drawable
{
    public:
        ///x, y stand for the coordinates in the xy plane of the pyramid peak
        Balloon(GLfloat x, GLfloat y, GLfloat z, GLfloat r, int partitions, Operators3D * opGlobal);
        virtual ~Balloon();

    protected:
            void applyGlobalMatrixToPoints();
            void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
            void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
            void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
            void lowLevelDraw();
    private:
};
#endif // BALLOON_H

#ifndef PLANET_H
#define PLANET_H

#include "Operators3D.h"
#include "Sphere.h"
#include "Line.h"

class Planet : public Sphere
{
    public:
        Planet(GLfloat x, GLfloat y, GLfloat z,GLfloat r, int partitions, Operators3D * opGlobal);
        virtual ~Planet();
        Planet & addSatellite(Drawable * satellite,GLfloat theta);

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void lowLevelDraw();
        void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);

    private:
        Point * forSatelliteP1Ref, * forSatelliteP2Ref;
};

#endif // PLANET_H

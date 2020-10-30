#ifndef SPHERE_H
#define SPHERE_H

#include "Operators3D.h"
#include "Drawable.h"
#include "Circle.h"

class Sphere : public Drawable
{
    public:
        Sphere(GLfloat x, GLfloat y, GLfloat z, GLfloat r, int partitions, Operators3D * opGlobal);
        virtual ~Sphere();

    protected:
        void applyGlobalMatrixToPoints();
        void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
        void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
        void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
        void lowLevelDraw();
    private:
        Circle *createCircle(GLfloat rSquared,GLfloat denominatorRa,GLfloat dif,GLfloat r,GLfloat yH, GLfloat height,GLfloat x,GLfloat y, GLfloat z);
};

#endif // SPHERE_H

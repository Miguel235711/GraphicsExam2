#ifndef PYRAMID_H
#define PYRAMID_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"



class Pyramid : Drawable
{
    public:
        ///x, y stand for the coordinates in the xy plane of the pyramid peak
        Pyramid(GLfloat x, GLfloat y, GLfloat height, Operators3D opGlobal);
        virtual ~Pyramid();

    protected:

    private:
};

#endif // PYRAMID_H

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"

class Triangle : public Exam2::Polygon
{
    public:
        Triangle(Point p1, Point p2, Point p3, Operators3D * opGlobal);
        virtual ~Triangle();
    protected:

    private:
};

#endif // TRIANGLE_H

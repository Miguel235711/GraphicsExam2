#ifndef CIRCLE_H
#define CIRCLE_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"

class Circle : public Exam2::Polygon
{
    public:
        Circle(int x, int y, int r, int partitions,Operators3D * opGlobal);
        virtual ~Circle();

    protected:

    private:
        std::vector<Point> init(int x,int y,int r,int partitions);
};

#endif // CIRCLE_H

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"

class Circle : public Exam2::Polygon
{
    public:
        Circle(GLfloat x, GLfloat y, GLfloat r, int partitions,Operators3D * opGlobal);
        virtual ~Circle();

    protected:

    private:
        std::vector<Point> init(GLfloat x,GLfloat y,GLfloat r,int partitions);
};

#endif // CIRCLE_H

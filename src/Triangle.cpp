#include "Triangle.h"


Triangle::Triangle(Point p1, Point p2, Point p3, Operators3D * opGlobal):Exam2::Polygon(opGlobal,{p1,p2,p3})
{

    //ctor
}

Triangle::~Triangle()
{
    //dtor
}

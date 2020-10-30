#include "Line.h"
namespace Exam2{
 Line::Line(Point p1, Point p2,Operators3D * opGlobal):
        Exam2::Polygon(opGlobal,{p1,p2})
    {
        //ctor
    }

    Line::~Line()
    {
        //dtor
    }
}

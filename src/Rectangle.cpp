#include "Rectangle.h"

namespace Exam2{
    Rectangle::Rectangle(int x,int y,Operators3D * opGlobal):
        Exam2::Polygon(opGlobal,init(x,y))
    {
        //ctor
    }

    Rectangle::~Rectangle()
    {
        //dtor
    }

    std::vector<Point> Rectangle::init(int x, int y){

        /*auto dist = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2)+pow(p2.z-p1.y,2));
        if(p2.x<p1.x)
            std::swap(p1,p2);
        ///here, p1.x < p2.x
        auto cathetusWithX = p2.x-p1.x;
        return {p1,Point(p1.x+cathetusWithX,p1.y),p2,Point(p2.x-cathetusWithX,p2.y)};*/
        return {Point(0,0,0),Point(x,0,0),Point(x,y,0),Point(0,y,0)};
    }
}

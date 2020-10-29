#include "Circle.h"

Circle::Circle(GLfloat x, GLfloat y, GLfloat r,int partitions,Operators3D * opGlobal):Exam2::Polygon(opGlobal,init(x,y,r,partitions)){

}

Circle::~Circle()
{
    //dtor
}

std::vector<Point> Circle::init(GLfloat x, GLfloat y, GLfloat r,int partitions){
    auto difRad = pi2/partitions;
    std::vector<Point> ans;
    for(GLfloat theta = 0; theta < pi2 ; theta += difRad){
        ans.push_back(Point(r*cos(theta)+x,r*sin(theta)+y,0));
    }
    return ans;
}

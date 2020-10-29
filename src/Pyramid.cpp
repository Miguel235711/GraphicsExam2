#include "Pyramid.h"

Pyramid::Pyramid(GLfloat x, GLfloat y, GLfloat height,GLfloat sideLength, Operators3D * opGlobal):Drawable(opGlobal)
{
    ///instantiate and add corresponding children
    Triangle triangle1 = Triangle (Point (x,y,height), Point (x-height*sqrt(2), y-height*sqrt(2), -height),Point (x+height*sqrt(2), y+height*sqrt(2), -height), opGlobal);
    addChild (triangle1);

}

Pyramid::~Pyramid()
{
    //dtor
}
void Pyramid::applyGlobalMatrixToPoints(){}
void Pyramid::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){}
void Pyramid::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){}
void Pyramid::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){}
void Pyramid::lowLevelDraw(){}

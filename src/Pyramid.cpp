#include "Pyramid.h"

Pyramid::Pyramid(Point peak, GLfloat height,GLfloat sideLength, Operators3D * opGlobal):Drawable(opGlobal)
{
        //ctor
    ///instantiate children and add them to this
    //auto * triangle1 = new Triangle (peak, Point (peak.x-sideLength*sqrt(2),peak.y-height,peak.z),Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z+sideLength*sqrt(2)), opGlobal);
    //auto * triangle2 = new Triangle (peak, Point (peak.x-sideLength*sqrt(2),peak.y-height,peak.z),Point (peak.x-sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)), opGlobal);
    //auto * triangle3 = new Triangle (peak, Point (peak.x+sideLength*sqrt(2),peak.y-height,peak.z),Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z+sideLength*sqrt(2)), opGlobal);
    //auto * triangle4 = new Triangle (peak, Point (peak.x+sideLength*sqrt(2),peak.y-height,peak.z),Point (peak.x-sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)), opGlobal);
    auto * triangle1 = new Triangle (peak, Point (peak.x-sideLength*sqrt(2),peak.y-height,peak.z+sideLength*sqrt(2)),Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z+sideLength*sqrt(2)), opGlobal);
    auto * triangle2 = new Triangle (peak, Point (peak.x-sideLength*sqrt(2),peak.y-height, peak.z+sideLength*sqrt(2)),Point (peak.x-sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)), opGlobal);
    auto * triangle3 = new Triangle (peak, Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)),Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z+sideLength*sqrt(2)), opGlobal);
    auto * triangle4 = new Triangle (peak, Point (peak.x+sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)),Point (peak.x-sideLength*sqrt(2),peak.y-height, peak.z-sideLength*sqrt(2)), opGlobal);
    addChild (triangle1);
    addChild (triangle1);
    addChild (triangle2);
    addChild (triangle3);
    addChild (triangle4);
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
void Pyramid::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

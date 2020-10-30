#include "Balloon.h"

Balloon::Balloon(GLfloat x, GLfloat y, GLfloat z, GLfloat r, int partitions, Operators3D * opGlobal):Drawable(opGlobal)
{
        //ctor
    ///instantiate children and add them to this
    auto * sphere = new Sphere (x,y,z,r,partitions, opGlobal);
    auto * base = new CircularPrism (x/2,y/2,z/2,r/3, partitions, opGlobal);
    base->rotate(Point(0,0,0),Point(0,0,0),-90);
    base -> translate (0,-r,r/2);
//auto balloon = Balloon (2,2,2,2,60,opInstance);
    //cuboid-> escale(sideLength, height*0.5, sideLength);
    addChild (sphere);
    addChild (base);
}

Balloon::~Balloon()
{
    //dtor
}
void Balloon::applyGlobalMatrixToPoints(){}
void Balloon::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){}
void Balloon::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){}
void Balloon::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){}
void Balloon::lowLevelDraw(){}

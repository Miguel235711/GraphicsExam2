#include "CircularPrism.h"

CircularPrism::CircularPrism(GLfloat x,GLfloat y,GLfloat z,GLfloat r,int partitions,Operators3D * opGlobal): Drawable(opGlobal)
{

    auto * circle1 = new Circle(x,y,r,partitions,opGlobal);
    addChild(circle1);
    auto * circle2 = new Circle(x,y,r,partitions,opGlobal);
    circle2->translate(0,0,z);
    addChild(circle2);
    //ctor
}

CircularPrism::~CircularPrism()
{
    //dtor
}
void CircularPrism::applyGlobalMatrixToPoints(){
}
void CircularPrism::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void CircularPrism::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void CircularPrism::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
}
void CircularPrism::lowLevelDraw(){

}

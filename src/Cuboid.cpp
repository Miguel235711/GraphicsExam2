#include "Cuboid.h"



Cuboid::Cuboid(int x,int y,int z, Operators3D * opGlobal) : Drawable(opGlobal)
{
    //ctor
    ///instantiate children and add them to this
    auto * rectangle = new Exam2::Rectangle(x,y,opGlobal);
    addChild(rectangle);
    std::cout << "****after adding rectangle";
}

Cuboid::~Cuboid()
{
    //dtor
}

void Cuboid::applyGlobalMatrixToPoints(){
}
void Cuboid::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void Cuboid::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void Cuboid::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
}
void Cuboid::lowLevelDraw(){

}

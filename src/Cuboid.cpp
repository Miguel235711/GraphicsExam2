#include "Cuboid.h"



Cuboid::Cuboid(int x,int y,int z, Operators3D * opGlobal) : Drawable(opGlobal)
{
    //ctor
    ///instantiate children and add them to this
    auto * rectangle = new Exam2::Rectangle(x,y,opGlobal);
    addChild(rectangle);
    auto * rectangle2 = new Exam2::Rectangle(x,y,opGlobal);
    rectangle2->translate(0,0,z);
    addChild(rectangle2);
    auto * rectangle3 = new Exam2::Rectangle(z,y,opGlobal);
    rectangle3->rotate(Point(0,0,0),Point(0,1,0),-90);
    addChild(rectangle3);
    auto * rectangle4 = new Exam2::Rectangle(z,y,opGlobal);
    rectangle4->rotate(Point(0,0,0),Point(0,1,0),-90).translate(x,0,0);
    addChild(rectangle4);

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

#include "Car.h"

Car::Car(GLfloat xSize, GLfloat ySize, GLfloat zSize, int partitions, Operators3D * opGlobal) : Drawable(opGlobal)
{
    /*auto * pivotWheel  = new CircularPrism(x,y,log(xSize+ySize+zSize)/3,log(xSize+ySize+zSize)/2,partitions,opGlobal);
    //pivotWheel->addRotation(Point(x,y,0),Point(x,y,1),0.1);
    //auto * pivotWheel = new  CircularPrism(0,0,2,6,25,opGlobal);
    //pivotWheel->translate(0,0,2);
    pivotWheel->rotate(Point(0,0,0),Point(0,1,0),90);
    pivotWheel->addRotation(Point(0,0,0),Point(1,0,0),0.1);
    addChild(pivotWheel);
    auto * pivotWheel2  = new CircularPrism(x+xSize,y,log(xSize+ySize+zSize)/3,log(xSize+ySize+zSize)/2,partitions,opGlobal);
    pivotWheel2->rotate(Point(0,0,0),Point(0,1,0),90);
    pivotWheel2->addRotation(Point(0,0,xSize),Point(1,0,xSize),0.1);
    addChild(pivotWheel2);*/
    //std::cout << children.size() << "\n";
    auto radius = log(xSize+ySize+zSize)/xSize,wide = log(xSize+ySize+zSize)/xSize;
    auto * pivotWheel1  = new CircularPrism(0,0,wide,radius,partitions,opGlobal);
    pivotWheel1->translate(0,0,-wide);
    addChild(pivotWheel1);
    auto * pivotWheel2  = new CircularPrism(xSize,0,wide,radius,partitions,opGlobal);
    pivotWheel2->translate(0,0,-wide);
    addChild(pivotWheel2);
    auto * cabin = new Cuboid(xSize,ySize,zSize,opGlobal);
    auto * pivotWheel3  = new CircularPrism(0,0,wide,radius,partitions,opGlobal);
    pivotWheel3->translate(0,0,ySize);
    addChild(pivotWheel3);
    auto * pivotWheel4  = new CircularPrism(0+xSize,0,wide,radius,partitions,opGlobal);
    pivotWheel4->translate(0,0,ySize);
    addChild(pivotWheel4);

    //cabin->translate(xSize,radius*2,zSize);
    addChild(cabin);
    //ctor
}

Car::~Car()
{
    //dtor
}

void Car::applyGlobalMatrixToPoints(){
}
void Car::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void Car::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void Car::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
}
void Car::lowLevelDraw(){

}
void Car::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

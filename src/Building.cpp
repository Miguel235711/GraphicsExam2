#include "Building.h"

Building::Building(GLfloat height,GLfloat width, GLfloat length,  Operators3D * opGlobal):Drawable(opGlobal)
{
    //ctor
    ///instantiate children and add them to this
    auto * cuboid = new Cuboid (width,height,length,opGlobal);
    addChild (cuboid);


    auto * cuboid2 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid2 -> translate (width/5, height - height/4, length);
    addChild (cuboid2);
    auto * cuboid3 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid3 -> translate (width/5*2, height - height/4, length);
    addChild (cuboid3);
    auto * cuboid4 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid4 -> translate (width/5*3, height - height/4, length);
    addChild (cuboid4);
    auto * cuboid5 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid5 -> translate (width/5*4, height - height/4, length);
    addChild (cuboid5);

    auto * cuboid6 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid6 -> translate (width/5, height - height/2, length);
    addChild (cuboid6);
    auto * cuboid7 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid7 -> translate (width/5*2, height - height/2, length);
    addChild (cuboid7);
    auto * cuboid8 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid8 -> translate (width/5*3, height - height/2, length);
    addChild (cuboid8);
    auto * cuboid9 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid9 -> translate (width/5*4, height - height/2, length);
    addChild (cuboid9);

    auto * cuboid14 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid14 -> translate (width/5, height - height/4*3, length);
    addChild (cuboid14);
    auto * cuboid15 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid15 -> translate (width/5*2, height - height/4*3, length);
    addChild (cuboid15);
    auto * cuboid16 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid16 -> translate (width/5*3, height - height/4*3, length);
    addChild (cuboid16);
    auto * cuboid17 = new Cuboid (width/6,height/4,0.01,opGlobal);
    cuboid17 -> translate (width/5*4, height - height/4*3, length);
    addChild (cuboid17);


    auto * cuboid10 = new Cuboid (width/3,height/4,0.01,opGlobal);
    cuboid10 -> translate (width/5, height - height, length);
    addChild (cuboid10);

    auto * cuboid11 = new Cuboid (0.01,height/4,length/3,opGlobal);
    cuboid11 -> translate (width, height - height/4, length/3);
    addChild (cuboid11);

     auto * cuboid12 = new Cuboid (0.01,height/4,length/3,opGlobal);
    cuboid12 -> translate (width, height - height/4*2, length/3);
    addChild (cuboid12);

     auto * cuboid13 = new Cuboid (0.01,height/4,length/3,opGlobal);
    cuboid13 -> translate (width, height - height/4*3, length/3);
    addChild (cuboid13);
}

Building::~Building()
{
    //dtor
}
void Building::applyGlobalMatrixToPoints(){}
void Building::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){}
void Building::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){}
void Building::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){}
void Building::lowLevelDraw(){}
void Building::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

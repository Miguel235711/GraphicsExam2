#include "Pine.h"


Pine::Pine(Point peak, GLfloat height,GLfloat sideLength, Operators3D * opGlobal):Drawable(opGlobal)
{
        //ctor
    ///instantiate children and add them to this
    //auto * cuboid = new Cuboid (peak.x-sideLength*sqrt(2),peak.y-height*0.6, peak.z-sideLength*sqrt(2),opGlobal);
    auto * cuboid = new Cuboid (1,1,1,opGlobal);
    cuboid-> escale(sideLength, height*0.5, sideLength);
    cuboid-> translate(peak.x-sideLength*sqrt(2)/4,peak.y-height,peak.z-sideLength*sqrt(2)/4);
    auto * pyramid = new Pyramid (peak, height*0.50, sideLength, opGlobal);
    addChild (cuboid);
    addChild (pyramid);
}

Pine::~Pine()
{
    //dtor
}
void Pine::applyGlobalMatrixToPoints(){}
void Pine::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){}
void Pine::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){}
void Pine::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){}
void Pine::lowLevelDraw(){}
void Pine::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

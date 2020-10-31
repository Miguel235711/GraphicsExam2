#include "Sphere.h"

Sphere::Sphere(GLfloat x, GLfloat y, GLfloat z, GLfloat r, int partitions, Operators3D * opGlobal) : Drawable(opGlobal)
{
    //ctor
    auto denominatorRa = partitions*10;///fix later
    auto difA = r / partitions * 2, rSquared = r*r;
    auto limYH1 = y + r;
    for(GLfloat yH = y; yH <= limYH1; yH+=difA){
        //std::cout << "adding circle\n";
        addChild(createCircle(rSquared,denominatorRa,limYH1-yH,r,yH,yH-y,x,y,z));
    }
    auto limYH2 = y - r;
    for(GLfloat yH = y - difA ; yH >= limYH2; yH -=difA){
        addChild(createCircle(rSquared,denominatorRa,yH-limYH2,r,yH,y-yH,x,y,z));
    }

}

Sphere::~Sphere()
{
    //dtor
}

Circle * Sphere::createCircle(GLfloat rSquared,GLfloat denominatorRa,GLfloat dif,GLfloat r,GLfloat yH, GLfloat height,GLfloat x,GLfloat y, GLfloat z){
    auto ri = sqrt(rSquared-pow(height,2));
    //std::cout << "ri: " << ri << "\n" << "partitions: " << dif*denominatorRa << "\n";
    auto circle = new Circle(0,0,ri,dif/r*denominatorRa,opGlobal); /// optimize partitions
    circle->rotate(Point(0,0,0),Point(1,0,0),90);
    circle->translate(x,yH,z);
    return circle;
}


void Sphere::applyGlobalMatrixToPoints(){
}
void Sphere::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void Sphere::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void Sphere::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
    //std::cout  <<"callledfklfjlskfjdaskfjfds\n";
    /*for(auto & child: children){
        child->rotate(P1,P2,theta);
    }*/

}
void Sphere::lowLevelDraw(){

}
void Sphere::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

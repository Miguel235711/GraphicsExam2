#include "Planet.h"

Planet::Planet(GLfloat x, GLfloat y, GLfloat z,GLfloat r, int partitions, Operators3D * opGlobal) : Sphere(x,y,z,r,partitions,opGlobal)
{
    //ctor
    forSatelliteP1Ref = new Point(x,0,z);
    forSatelliteP2Ref = new Point(x,1,z);
}

Planet::~Planet()
{
    //dtor
}
void Planet::applyGlobalMatrixToPoints(){
    if(forSatelliteP1Ref&&forSatelliteP2Ref){
        //std::cout << "applyGlobalMatrixToPoints in planet:\n";
        auto toModifyPs = std::vector<std::vector<GLfloat>>{{forSatelliteP1Ref->x,forSatelliteP1Ref->y,forSatelliteP1Ref->z,1},
        {forSatelliteP2Ref->x,forSatelliteP2Ref->y,forSatelliteP2Ref->z,1}};
        auto & m = opGlobal->A.top();
        opGlobal->MatPoint(m,toModifyPs[0]);
        opGlobal->MatPoint(m,toModifyPs[1]);
        //std::cout << "Before modifying: x-> " << forSatelliteP1Ref->x << " y-> " << forSatelliteP1Ref->y << " z-> " << forSatelliteP1Ref->z << "\n";
        forSatelliteP1Ref->x=toModifyPs[0][0];
        forSatelliteP1Ref->y=toModifyPs[0][1];
        forSatelliteP1Ref->z=toModifyPs[0][2];
        forSatelliteP2Ref->x=toModifyPs[1][0];
        forSatelliteP2Ref->y=toModifyPs[1][1];
        forSatelliteP2Ref->z=toModifyPs[1][2];
        //std::cout << "After modifying: x-> " << forSatelliteP1Ref->x << " y-> " << forSatelliteP1Ref->y << " z-> " << forSatelliteP1Ref->z << "\n";
        //addChild(new Exam2::Line(*forSatelliteP1Ref,*forSatelliteP2Ref,opGlobal));
    }
}
void Planet::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void Planet::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void Planet::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
}
void Planet::lowLevelDraw(){

}
void Planet::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}
Planet & Planet::addSatellite(Drawable * satellite,GLfloat theta){
    //std::cout << "-----------------addSatellite\n";
    addChild(satellite);
    //std::cout << "************forSatelliteP1Ref->x " << forSatelliteP1Ref->x << " ->y " << forSatelliteP1Ref->y << " ->z " << forSatelliteP1Ref->z << "\n";
    //satellite->addRotation(*forSatelliteP1Ref,*forSatelliteP2Ref,0.1);
    //std::cout << "%%%%%%%%%%%%%%%%%%%%%%%forSatelliteP1Ref->x " << forSatelliteP1Ref->x << " ->y " << forSatelliteP1Ref->y << " ->z " << forSatelliteP1Ref->z << "\n";
    if(theta)
        satellite->setDynamicRotation(forSatelliteP1Ref,forSatelliteP2Ref,theta);
    return *this;
}

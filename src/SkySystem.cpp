#include "SkySystem.h"

SkySystem::SkySystem(GLfloat x, GLfloat y, GLfloat z,GLfloat r, int partitions, Operators3D * opGlobal) : Drawable(opGlobal)
{
    //ctor
    auto * sun = new Sphere(x,y,z,r,partitions,opGlobal);
    addChild(sun);
    auto * planet1 = new Planet(x+r*1.5,y,z,r/10,partitions/3.5,opGlobal);
    planet1->addRotation(Point(x,0,z),Point(x,1,z),0.5);
    addChild(planet1);
    auto * planet2 = new Planet(x+r*1.8,y,z,r/8,partitions/3.2,opGlobal);
    planet2->addRotation(Point(x,0,z),Point(x,1,z),0.4);
    addChild(planet2);
    auto * planet3 = new Planet(x+r*2.1,y,z,r/6,partitions/3,opGlobal);
    //std::cout << "#$&Y%$&%$&%%%&%&%#%$ of planet 3: " << x+r*2.1 << "\n";
    auto * moonForPlanet3 = new Sphere(x+r*2.4,y,z,r/12,partitions/6,opGlobal);
    planet3->addRotation(Point(x,0,z),Point(x,1,z),0.3);
    //moonForPlanet3->addRotation(Point(x,0,z),Point(x,1,z),0.3);
    planet3->addSatellite(moonForPlanet3,0);///Error
    //planet3->translate(1,1,1);
    addChild(planet3);
    auto xPlanet4 = x+r*2.5;
    auto * planet4 = new Planet(xPlanet4,y,z,r/3,partitions/2,opGlobal);
    addChild(planet4);
    planet4->addRotation(Point(x,0,z),Point(x,1,z),0.2);
    auto * ringForPlanet4 = new Circle(xPlanet4,y,r/3,partitions,opGlobal);
    ringForPlanet4->rotate(Point(0,0,0),Point(1,0,0),90);
    ringForPlanet4->rotate(Point(xPlanet4,y,0),Point(xPlanet4,y,1),45);
    ringForPlanet4->translate(0,0,z);
    ringForPlanet4->escaleWithPivot(2.2,1,1.3,Point(xPlanet4,y,z));
    auto * ring2ForPlanet4 =  new Circle(xPlanet4,y,r/3,partitions,opGlobal);
    ring2ForPlanet4->rotate(Point(0,0,0),Point(1,0,0),90);
    ring2ForPlanet4->rotate(Point(xPlanet4,y,0),Point(xPlanet4,y,1),45);
    ring2ForPlanet4->translate(0,0,z);
    ring2ForPlanet4->escaleWithPivot(2.4,1,1.5,Point(xPlanet4,y,z));
    planet4->addChild(ringForPlanet4);
    planet4->addChild(ring2ForPlanet4);

}

SkySystem::~SkySystem()
{
    //dtor
}
void SkySystem::applyGlobalMatrixToPoints(){
}
void SkySystem::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
}
void SkySystem::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
}
void SkySystem::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
}
void SkySystem::lowLevelDraw(){

}
void SkySystem::applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot){}

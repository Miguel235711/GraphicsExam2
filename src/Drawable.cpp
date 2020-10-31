#include "Drawable.h"

typedef std::vector<GLfloat> v;
typedef std::vector<v> vv;

Drawable::Drawable(Operators3D * opGlobal): opGlobal(opGlobal)
{
    //ctor
    A.resize(4);
    for(size_t i = 0 ; i < A.size() ; i ++)
        A[i].resize(A.size());
    opGlobal->LoadIdentity(A);
    //std::cout << "Drawable(Operators3D *opGlobal):\n";
}

Drawable::~Drawable()
{
    //dtor
}
Drawable & Drawable::update(){
    ///push change to global matrix
    //std::cout << "children.size(): " << children.size() << "\n";
    opGlobal->push();
    opGlobal->MultM(A,opGlobal->A.top(),opGlobal->A.top());
    applyGlobalMatrixToPoints(); ///call method that MUST be implemented by extended classes
    if(p1&&p2){ ///apply dynamic rotation to this and all children if defined
        //std::cout << "variable rotation activated!!!: ";
        //std::cout << "b:: x: " << p1->x << " y: " << p1->y << " z: " << p1->z << "\n";
        //std::cout << "b:: x: " << p2->x << " y: " << p2->y << " z: " << p2->z << "\n";
        rotate(*p1,*p2,theta);
        //std::cout << "AAAA x: " << p1->x << " y: " << p1->y << " z: " << p1->z << "\n";
    }
    ///call recursively children
    for(auto *child: children){
        child->update();
    }
    ///pop change of global matrix
    opGlobal->pop();
    return *this;
}
Drawable & Drawable::addChild(Drawable * child){
    children.push_back(child);
    return *this;
}
///Applied in every update
Drawable & Drawable::addTranslation(GLfloat dx,GLfloat dy,GLfloat dz){
    ///multiply matrices T by A
    //std::cout << "before adding translation -> " << " dx: " << dx << " dy: " << dy << " dz: " << dz << "\n";
    print();
    opGlobal->translate(dx,dy,dz,A);
    //std::cout << "after adding translation\n";
    print();
    ///opGlobal->MultM(T,A->top(),A->top());
    return *this;
}
Drawable & Drawable::addEscalation(GLfloat dx,GLfloat dy, GLfloat dz){
    ///TODO
    opGlobal->escale(dx,dy,dz,A);
    return *this;
}
Drawable & Drawable::addRotation(Point p1, Point p2, GLfloat theta){
    /*std::cout << "before adding rotation\n";
    std::cout << "theta = " << theta << "\n";*/
    print();
    //std::cout << "after adding rotation\n";
    opGlobal->RotacionLibre(theta,{p1.x,p1.y,p1.z},{p2.x,p2.y,p2.z},A);

    print();
    return *this;
}
Drawable & Drawable::setDynamicRotation(Point * p1, Point * p2, GLfloat theta){
    /*std::cout << "before adding pointed rotation\n";
    std::cout << "theta = " << theta << "\n";
    std::cout << "after adding dynamic rotation\n";*/
    ///add rotation pointer to dynamic rotation
    this->p1 = p1, this->p2 = p2;
    this->theta = theta;
    return *this;
}
///Applied once to this an its children
Drawable & Drawable::translate(GLfloat x,GLfloat y,GLfloat z){
    applyUniqueTransToPoints(x,y,z);
    for(auto * child: children)
        child->translate(x,y,z);
    return *this;
}
Drawable & Drawable::rotate(Point p1, Point p2, GLfloat theta){
    applyUniqueRotationToPoints(theta,p1,p2);
    /*if(this->p1&&this->p2){
        std::cout << "aplying special rotation: x->" << p1.x << " y-> " << p1.y << " z-> "  << p1.z << "\n";
    }*/
    for(auto * child: children)
        child->rotate(p1,p2,theta);
    return *this;
}
Drawable & Drawable::escale(GLfloat x,GLfloat y,GLfloat z){
    applyUniqueEscaltionToPoints(x,y,z);
    for(auto * child: children)
        child->escale(x,y,z);
    return *this;
}
Drawable & Drawable::escaleWithPivot(GLfloat x,GLfloat y, GLfloat z, Point pivot){
    applyUniqueEscalationWithPivotToPoints(x,y,z,pivot);
    for(auto * child:children)
        child->escaleWithPivot(x,y,z,pivot);
    return *this;
}
Drawable & Drawable::draw(){
    lowLevelDraw();
    ///draw children
    for(auto * child:children)
        child->draw();
    return *this;
}

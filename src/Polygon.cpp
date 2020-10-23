#include "Polygon.h"

namespace Exam2{
    Polygon::Polygon(Operators3D * opGlobal,std::vector<Point> points):Drawable(opGlobal),points(points)
    {
        //ctor
    }

    Polygon::~Polygon()
    {
        //dtor
    }

    void Polygon::applyGlobalMatrixToPoints(){
        /*std::cout << "applyGlobalMatrixToPoints()\n";
        for(size_t i = 0 ; i < A.size() ; i ++){
            for(size_t j = 0 ; j < A[i].size() ; j++){
                std::cout << A[i][j] << " ";
            }
            std::cout << "\n";
        }*/
        ///apply global matrix to points
        applyMatrixToPoints(opGlobal->A.top());
    }
    void Polygon::applyMatrixToPoints(vv & m){
        for(auto & point : points){
            auto toModifyP = std::vector<GLfloat>{point.x,point.y,point.z,1};
            opGlobal->MatPoint(m,toModifyP);
            point.x = toModifyP[0], point.y = toModifyP[1] , point.z = toModifyP[2];
        }
    }
    void Polygon::applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z){
        for(auto & point: points){
            point.x +=x;
            point.y +=y;
            point.z +=z;
        }
    }
    void Polygon::applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z){
        auto first = points[0];
        for(auto & point: points){
            point.x = (point.x-first.x)*x+first.x;
            point.y = (point.y-first.y)*y+first.y;
            point.z = (point.z-first.z)*z+first.z;
        }
    }
    void Polygon::applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2){
        ///
        auto m = vv(4,v(4));
        opGlobal->LoadIdentity(m);
        opGlobal->RotacionLibre(theta,v{P1.x,P1.y,P1.z},v{P2.x,P2.y,P2.z},m);
        applyMatrixToPoints(m);
    }
    void Polygon::lowLevelDraw(){
        ///modify color later, for now, use white
        //std::cout << "lowLevelDraw is being called\n";
        //glShadeModel(GL_SMOOTH);
        glColor3f(1,1,1);
        glBegin(GL_LINES);
        for(size_t i = 1 ; i < points.size() ; i ++ ){
                glVertex3f(points[i].x,points[i].y,points[i].z);
                auto beforeI = i-1;
                glVertex3f(points[beforeI].x,points[beforeI].y,points[beforeI].z);
        }
        auto lastIndex = points.size()-1;
        //glBegin(GL_LINES);
            glVertex3f(points[lastIndex].x,points[lastIndex].y,points[lastIndex].z);
            glVertex3f(points[0].x,points[0].y,points[0].z);
        glEnd();
        //glFlush();
        //glutSwapBuffers();
    }
}

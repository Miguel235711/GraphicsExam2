#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "Point.h"
#include "Operators3D.h"

#include<vector>
#include<iostream>

class Drawable
{
    public:
        Drawable(Operators3D * opGlobal);
        virtual ~Drawable();
        Drawable & draw();
        Drawable & update();
        Drawable & addChild(Drawable & child);
        ///Applied in every update
        Drawable & addTranslation(GLfloat dx,GLfloat dy,GLfloat dz);
        Drawable & addEscalation(GLfloat dx,GLfloat dy, GLfloat dz);
        Drawable & addRotation(Point p1, Point p2, GLfloat theta);
        ///Applied once
        Drawable & translate(GLfloat x,GLfloat y,GLfloat z);
        Drawable & rotate(Point p1, Point p2, GLfloat theta);
        Drawable & escale(GLfloat x,GLfloat y,GLfloat z);

    protected:
        ///to be implemented by child classes
        virtual void applyGlobalMatrixToPoints() = 0;
        virtual void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z) = 0;
        virtual void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z) = 0;
        virtual void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2) = 0;
        virtual void lowLevelDraw() = 0;
        Operators3D * opGlobal;
        vv A;
    private:
        std::vector<Drawable*> children;
        void print(){
            std::cout << "print()\n";
            for(size_t i = 0 ; i < A.size() ; i ++){
                for(size_t j = 0 ; j < A[i].size() ; j ++){
                    std::cout << A[i][j] << " ";
                }
                std::cout << "\n";
            }
        }


};

#endif // DRAWABLE_H

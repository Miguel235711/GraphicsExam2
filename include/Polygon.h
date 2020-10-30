#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include "Drawable.h"
#include "Operators3D.h"

#include <vector>
#include <iostream>

namespace Exam2{

    class Polygon : public Drawable
    {
        public:
            Polygon(Operators3D * opGlobal,std::vector<Point> points);
            virtual ~Polygon();

        protected:
            void applyGlobalMatrixToPoints();
            void applyUniqueTransToPoints(GLfloat x, GLfloat y, GLfloat z);
            void applyUniqueEscaltionToPoints(GLfloat x,GLfloat y,GLfloat z);
            void applyUniqueRotationToPoints(GLfloat theta, Point P1, Point P2);
            void applyUniqueEscalationWithPivotToPoints(GLfloat x,GLfloat y,GLfloat z,Point pivot);
            void lowLevelDraw();

        private:
            std::vector<Point> points;
            void applyMatrixToPoints(vv & m);
    };
}


#endif // POLYGON_H

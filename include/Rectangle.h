#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"

/// The user will be responsible for transforming this shape
namespace Exam2{

    class Rectangle : public Exam2::Polygon
    {
        public:
            Rectangle(int x,int y,Operators3D * opGlobal);
            virtual ~Rectangle();

        protected:

        private:
            std::vector<Point> init(int x, int y);
    };
}

#endif // RECTANGLE_H

#ifndef LINE_H
#define LINE_H
#include "Polygon.h"
#include "Point.h"
#include "Operators3D.h"
namespace Exam2{

    class Line : public Exam2::Polygon
    {
        public:
           Line(Point p1,Point p2, Operators3D * opGlobal);
            virtual ~Line ();

        protected:

        private:
    };
}

#endif // LINE_H

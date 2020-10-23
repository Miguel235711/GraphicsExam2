#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

struct Point{
    GLfloat x,y,z;
    Point(GLfloat x, GLfloat y, GLfloat z):x(x),y(y),z(z){}
};



#endif // POINT_H_INCLUDED

#ifndef OPERATORS3D_H
#define OPERATORS3D_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include<math.h>
#include<stack>
#include<vector>

typedef std::vector<GLfloat> v;
typedef std::vector<v> vv;

class Operators3D
{
    public:
        Operators3D();
        virtual ~Operators3D();
        Operators3D & RotacionLibre(GLfloat theta, v p1, v p2, vv & ans);
        Operators3D & translate(GLfloat x, GLfloat y, GLfloat z, vv & ans);
        Operators3D & MultM(vv & M1, vv & M2, vv & ans);
        GLfloat RadToDeg(GLfloat r);
        GLfloat DegToRad(GLfloat g);
        Operators3D & LoadIdentity(vv & M);
        Operators3D & push();
        Operators3D & pop();
        std::stack<vv> A;
        Operators3D & MatPoint(vv & m, v & p);

    protected:
        constexpr static GLfloat pi=2*acos(0);


        Operators3D & MatObject(vv & m, int size, vv & p);
        Operators3D & RotacionParalela(char eje, GLfloat theta, GLfloat distA, GLfloat distB,vv & ans);

    private:
        vv PreC1,PreC2;

        GLfloat lastA, lastB, lastC, lastD; /// initialization in 0 could cause problems!!!!!!
        //Funcion que define la matriz de rotacion con rspecto al eje X
        Operators3D & rotateX(GLfloat deg,vv & ans);
        //Funcion que define la matriz de rotacion con rspecto al eje Y
        Operators3D & rotateY(GLfloat deg, vv & ans);
        //Funcion que define la matriz de rotacion con rspecto al eje Z
        Operators3D & rotateZ(GLfloat deg, vv & ans);
};

#endif // OPERATORS3D_H

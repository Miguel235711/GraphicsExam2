#include "Operators3D.h"
#include <iostream>

///probably with a LOT of bugs

Operators3D::Operators3D(){
    PreC1.resize(4);
    for(size_t i = 0 ; i < PreC1.size() ; i ++)
        PreC1[i].resize(PreC1.size());
    LoadIdentity(PreC1);
    vv initA;
    initA = PreC2 = PreC1;
    A.push(initA);
}
Operators3D::~Operators3D(){}
//recordar que (pi/180 = r/g) donde "r" son radianes y "g" grados
//se aplica la formula r
GLfloat Operators3D::RadToDeg(GLfloat r)
{
      return ((180*r)/pi);
}

GLfloat Operators3D::DegToRad(GLfloat g)
{
      return ((g*pi)/180);
}

Operators3D & Operators3D::LoadIdentity(vv & M)
{
    /*for(int i = 0 ; i < 4 ; i ++)
    for(int j = 0 ; j < 4 ; j ++)
        M[i][j]=i==j?1:0;*/
    for(size_t i = 0 ; i < M.size() ; i ++){
        for(size_t j = 0 ; j < M[i].size() ; j++){
            M[i][j] = i==j;
        }
    }
    return *this;
}

Operators3D & Operators3D::translate(GLfloat x, GLfloat y, GLfloat z,vv & ans) /// ans => null for local
{
    auto tmp = vv(4,v(4));
    std::cout << "going to translate by " << " x = " << x << " y = " << y << " z = " << z << "\n";
    LoadIdentity(tmp);
    tmp[0][3]=x;
    tmp[1][3]=y;
    tmp[2][3]=z;
    MultM(tmp,ans,ans);
    return *this;
}

Operators3D & Operators3D::rotateX(GLfloat deg, vv & ans)
{
    auto tmp = vv(4,v(4));
    LoadIdentity(tmp);
    tmp[1][1] = cos(deg);
    tmp[1][2] = -1*sin(deg);
    tmp[2][1] = sin(deg);
    tmp[2][2] = cos(deg);
    MultM(tmp,ans,ans);
    return *this;
}

Operators3D & Operators3D::rotateY(GLfloat deg, vv & ans)
{
    auto tmp = vv(4,v(4));
    LoadIdentity(tmp);
    tmp[0][0] = cos(deg);
    tmp[0][2] = sin(deg);
    tmp[2][0] = -1*sin(deg);
    tmp[2][2] = cos(deg);
    MultM(tmp,ans,ans);
    return *this;
 }

Operators3D & Operators3D::rotateZ(GLfloat deg, vv & ans)
{
    auto tmp = vv(4,v(4));
    LoadIdentity(tmp);
    tmp[0][0] = cos(deg);
    tmp[0][1] = -1*sin(deg);
    tmp[1][0] = sin(deg);
    tmp[1][1] = cos(deg);
    MultM(tmp,ans,ans);
    return *this;
}

Operators3D & Operators3D::MultM(vv & M1, vv & M2, vv & ans)
{
    auto tmp = vv(4,v(4));
    size_t i,j,k;
    for(i=0; i<tmp.size();i++){
        for(j=0;j<tmp[i].size();j++){
            tmp[i][j]=0;
            for(k=0;k<4;k++){
                tmp[i][j]+=M1[i][k]*M2[k][j];
            }
        }
    }
    ans = tmp;
    return *this;
}

//multiplica la matriz m por el punto p y regresa el resultado en el punto p
Operators3D & Operators3D::MatPoint(vv & m, v & p) /// p MUST be of size 4
{
    /*std::cout << "--------------\n";
    std::cout << "MatPoint(): ";
    std::cout << "m:\n";
    for(int i = 0 ; i < m.size() ; i ++){
        for(int j = 0 ; j < m[i].size() ; j ++){
            std::cout << m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "p:\n";
    for(int i = 0 ; i < p.size() ; i ++){
        std::cout << p[i] << " ";
    }
    std::cout << "\n";
    std::cout << "--------------\n";*/
    auto tmp = v(4);
    int i,j;
    p.resize(4);
    p[3]=1;
    for(i=0; i<3; i++){
        tmp[i] = p[i];
        p[i] = 0;
    }
    tmp[3]=1;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            p[i] += m[i][j]*tmp[j];
        }
    }
    return *this;
}

//multiplica la matriz m por cada punto del objeto definido por la matriz p de size x 3
Operators3D & Operators3D::MatObject( vv & m, int size, vv & p) /// p must be of size 3
{
    int i;
    for(i=0; i<size; i++)
        MatPoint(m,p[i]);
    return *this;
}

//rotacion paralela a uno de los ejes
//theta: angulo de rotacion;
//distA,distB: vector (distA,distB) que separa al eje de rotacion del objeto
//con respecto a uno de los ejes del sistema carteciano. Si el eje es:
//X: (distA,distB) es el vector (0,distA,distB)
//Y: (distA,distB) es el vector (distA,0,distB)
//Z: (distA,distB) es el vector (distA,distB,0)
Operators3D & Operators3D::RotacionParalela(char eje, GLfloat theta, GLfloat distA, GLfloat distB, vv & ans)
{
    auto t = vv(4,v(4));
    LoadIdentity(t);
    auto r = vv(4,v(4));
    LoadIdentity(r);
     switch(eje){
        case 'X':
             //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(0,-distA,-distB,t);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateX(DegToRad(theta),r);
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(r,t,ans);
             //se agrega la matriz de traslacion inversa a A
             translate(0,distA,distB,t);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(t,ans,ans);
             break;
        case 'Y':
	     //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(-distA,0,-distB,t);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateY(DegToRad(theta),r);
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(r,t,ans);
             //se agrega la matriz de traslacion inversa a A
             translate(distA,0,distB,t);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(t,ans,ans);
             break;
        case 'Z':
	     //se actualiza la matriz de traslacion para mover el objeto en el espacio
             translate(-distA,-distB,0,t);
             //se actualiza la matriz de rotacion con el angulo especificado
             rotateZ(DegToRad(theta),r);
             //se multiplica la matriz de rotacion por la de traslacion actual
             //el resultado queda en la matriz A
             MultM(r,t,ans);
             //se agrega la matriz de traslacion inversa a A
             translate(distA,distB,0,t);
             //se multiplica la matriz de traslacion por la matriz A y se deja el resultado en A
             MultM(t,ans,ans);
             break;
     }
     return *this;
}

Operators3D & Operators3D::RotacionLibre(GLfloat theta, v p1, v p2, vv & ans)
{
    std::cout << "Rotacion Libre()\n";
    auto difB = p2[1]-p1[1], difC = p2[2]-p1[2],thetaRad=DegToRad(theta);
    if(!difB&&!difC){
        ///special case of line parallel to X-axis
        //std::cout << "especial case";
        auto t = vv(4,v(4));
        LoadIdentity(t);
        translate(-p1[0],-p1[1],-p1[2],t);
        auto r = vv(4,v(4));
        LoadIdentity(r);
        rotateX(thetaRad,r);
        MultM(r,t,r);
        MultM(r,ans,ans);
        t[0][3]=p1[0],t[1][3]=p1[1],t[2][3]=p1[2];
        MultM(t,ans,ans);
        return *this;
    }
    auto difA = p2[0]-p1[0], V = (GLfloat)sqrt(difA*difA+difB*difB+difC*difC),
    a = difA/V, b = difB/V, c = difC/V, d = (GLfloat)sqrt(b*b+c*c); ///problem when d is 0
    if(a==lastA&&b==lastB&&c==lastC&&d==lastD){
        ///use precalculus
        std::cout << "using precalculus";
        auto r = vv(4,v(4));
        LoadIdentity(r);
        r[0][0]=r[1][1]=cos(thetaRad),r[1][0]=sin(thetaRad),r[0][1]=-r[1][0];
        MultM(r,PreC1,r);
        MultM(r,ans,ans);
        MultM(PreC2,ans,ans);
        return *this;
    }
    std::cout << "...\n";
    lastA = a,lastB = b , lastC = c, lastD = d;
    //LoadIdentity(R);
    ///translate(-x,-y,-z)
    auto t = vv(4,v(4));
    LoadIdentity(t);
    translate(-p1[0],-p1[1],-p1[2],t);
    ///rotate(alpha)
    auto r = vv(4,v(4));
    LoadIdentity(r);
    r[1][1]=c/d,r[1][2]=-b/d,r[2][1]=b/d,r[2][2]=c/d;
    MultM(r,t,PreC1);
    ///rotate(betha)
    r[1][1]=1,r[1][2]=r[2][1]=0;
    r[0][0]=d,r[0][2]=a,r[2][0]=-a,r[2][2]=d;
    MultM(r,PreC1,PreC1);
    ///rotate(theta)
    r[0][2]=r[2][0]=0,r[2][2]=1;
    r[0][0]=r[1][1]=cos(thetaRad),r[1][0]=sin(thetaRad),r[0][1]=-r[1][0];
    auto aux = vv(4,v(4));
    LoadIdentity(aux);
    MultM(r,PreC1,aux);
    MultM(aux,ans,ans);
    ///rotate(-betha)
    LoadIdentity(PreC2);
    r[0][1]=r[1][0]=0,r[1][1]=1;
    r[0][0]=d,r[0][2]=-a,r[2][0]=a,r[2][2]=d;
    PreC2 = r;
    //memcpy(PreC2,R,sizeof(GLfloat)*16);
    ///rotate(-alpha)
    r[0][0]=1,r[0][2]=r[2][0]=0;
    r[1][1]=c/d,r[1][2]=b/d,r[2][1]=-b/d,r[2][2]=c/d;
    MultM(r,PreC2,PreC2);
    ///translate(x,y,z)
    t[0][3]=p1[0],t[1][3]=p1[1],t[2][3]=p1[2];
    MultM(t,PreC2,PreC2);
    MultM(PreC2,ans,ans);
    return *this;
}

Operators3D & Operators3D::push(){
    A.push(A.top());
    return *this;
}
Operators3D & Operators3D::pop(){
    A.pop();
    return *this;
}

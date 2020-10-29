
#include <vector>
#include <iostream>
#include "Operators3D.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

//Variables dimensiones de la pantalla
int WIDTH=500;
int HEIGTH=500;
//Variables para establecer los valores de gluPerspective
float FOVY=60.0;
float ZNEAR=0.01;
float ZFAR=100.0;
//Variables para definir la posicion del observador
//gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z)
float EYE_X=10.0;
float EYE_Y=5.0;
float EYE_Z=10.0;
float CENTER_X=0;
float CENTER_Y=0;
float CENTER_Z=0;
float UP_X=0;
float UP_Y=1;
float UP_Z=0;
//Variables para dibujar los ejes del sistema
float X_MIN=-20;
float X_MAX=20;
float Y_MIN=-20;
float Y_MAX=20;
float Z_MIN=-100;
float Z_MAX=20;

float Theta=0;
//Variables para la definicion de objetos
//float P1[3]={0.0,0.0,0.0};


//rota a la piramide theta grados, donde el eje de rotacion se encuentra
//a una distancia distA-distB del eje seleccionado (ejeXYZ)

//-------------------------------------------------------------------------
//funciones callbacks
void idle(void)
{
    glutPostRedisplay();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}

/*void keys(unsigned char key, int x, int y)
{
    switch(key){
                case 'u':
                     Theta=1;
                     break;
                case 'd':
                     Theta=-1;
                     break;
                default:
                     Theta = 0;
                     break;
    }
}*/
void drawAxis()
{
     glShadeModel(GL_SMOOTH);
     glLineWidth(3.0);
     //X axis in red
     glBegin(GL_LINES);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex3f(X_MIN,0.0,0.0);
       glColor3f(0.5f,0.0f,0.0f);
       glVertex3f(X_MAX,0.0,0.0);
     glEnd();
     //Y axis in green
     glColor3f(0.0f,1.0f,0.0f);
     glBegin(GL_LINES);
       glColor3f(0.0f,1.0f,0.0f);
       glVertex3f(0.0,Y_MIN,0.0);
       glColor3f(0.0f,0.5f,0.0f);
       glVertex3f(0.0,Y_MAX,0.0);
     glEnd();
     //Z axis in blue
     glBegin(GL_LINES);
       glColor3f(0.0f,0.0f,1.0f);
       glVertex3f(0.0,0.0,Z_MIN);
       glColor3f(0.0f,0.0f,0.5f);
       glVertex3f(0.0,0.0,Z_MAX);
     glEnd();
     glLineWidth(1.0);
 }
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(FOVY, (GLfloat)WIDTH/HEIGTH, ZNEAR, ZFAR);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(EYE_X,EYE_Y,EYE_Z,CENTER_X,CENTER_Y,CENTER_Z,UP_X,UP_Y,UP_Z);
    ///white
    glClearColor(0,0,0,1);
}

auto * opInstance = new Operators3D();
auto triangle = Triangle(Point(0,0,0),Point(2,0,0),Point(2,2,0),opInstance);
auto triangle2 = Triangle(Point(0,2,5),Point(0,0,0),Point(0,0,-5),opInstance);
auto triangle3 = Triangle(Point(0,0,0),Point(2,0,0),Point(2,2,0),opInstance);
auto triangle4 = Triangle(Point(0,0,0),Point(2,0,0),Point(2,2,0),opInstance);
auto triangle5 = Triangle(Point(0,0,0),Point(2,0,0),Point(2,2,0),opInstance);
auto triangle6 = Triangle(Point(0,0,0),Point(2,0,0),Point(2,2,0),opInstance);
auto rectangle = Exam2::Rectangle(2,2,opInstance);
auto rectangle2 = Exam2::Rectangle(-2,-2,opInstance);
auto circle = Circle(0,0,3,30,opInstance);


int main(int argc, char **argv)
{

    //opInstance.translate(3,1,5);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 50);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow("Examen 2");
    init();
    triangle.translate(1,3,5).addTranslation(0,0,-0.001).addRotation(Point(0,0,0),Point(0,0,1),0.1);
    triangle2.addRotation(Point(0,0,0),Point(0,0,1),0.1);
    triangle3.addRotation(Point(0,0,0),Point(0,1,0),0.1);
    triangle4.translate(1,1,0).addTranslation(0.001,0,0).addRotation(Point(0,0,0),Point(1,1,0),0.1);
    triangle5.translate(0,0,-15).escale(1.5,1.5,1.5).rotate(Point(0,0,0),Point(0,0,1),130);
    triangle6.addTranslation(0,0,-0.0001).addEscalation(1.00001,1.00001,1.00001).addRotation(Point(0,0,0),Point(0,0,1),0.1);
    rectangle.translate(0,0,5).addTranslation(0,0,0.0001).addRotation(Point(0,0,0),Point(1,1,0),0.1);
    circle.addEscalation(1.00001,1.00001,1.00001);
    glutDisplayFunc([](){
        //std::cout << "glutDisplayFunc\n";
        glClear(GL_COLOR_BUFFER_BIT);
        drawAxis();
        triangle.draw();
        triangle2.draw();
        triangle3.draw();
        triangle4.draw();
        triangle5.draw();
        triangle6.draw();
        rectangle.draw();
        rectangle2.draw();
        circle.draw();
        glFlush();
    });
    glutIdleFunc([](){
        glClear(GL_COLOR_BUFFER_BIT);
        drawAxis();
        triangle.update().draw();
        triangle2.update().draw();
        triangle3.update().draw();
        triangle4.update().draw();
        triangle5.update().draw();
        triangle6.update().draw();
        rectangle.update().draw();
        rectangle2.update().draw();
        circle.update().draw();
        glFlush();
    });
    //glutKeyboardFunc(keys);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>



void Ejes (int width)
{   
    glLineWidth(width);
    glBegin(GL_LINES);
       glColor3f(1.0,0.0,0.0);
       glVertex3f(-2.0,0.0,0.0);
       glVertex3f(2.0,0.0,0.0);
       glColor3f(0.0,1.0,0.0);
       glVertex3f(0.0,-2.0,0.0);
       glColor3f(0.0,0.0,1.0);
       glVertex3f(0.0,2.0,0.0);   
    glEnd();
   
       
}

void Circle (GLfloat radio, GLfloat cx, GLfloat cy, GLint n, GLenum modo)
{
int i;
if (modo==GL_LINE) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
else if (modo==GL_FILL) glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
else glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
glBegin( GL_POLYGON );
for (i=0;i<n;i++)
glVertex2f( cx+radio*cos(2.0*M_PI*i/n), cy+radio*sin(2.0*M_PI*i/n));
glEnd();
}


void Monigote ()
{
  
 
// cara
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.4,0.0,0.0);
      glVertex3f(0.4,0.0,0.0);
      glVertex3f(0.4,1.1,0.0);
      glVertex3f(-0.4,1.1,0.0);
   glEnd(); 

   glColor3f(0.0,0.0,0.);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(-0.4,0.0,0.0);
      glVertex3f(0.4,0.0,0.0);
      glVertex3f(0.4,1.1,0.0);
      glVertex3f(-0.4,1.1,0.0);
   glEnd(); 

   //ojos
   glColor3f(0.3,0.3,1.0);
   Circle (0.1, 0.2, 0.8, 20, GL_FILL);
   Circle (0.1, -0.2, 0.8, 20, GL_FILL);


   //Nariz
   glColor3f(1.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_TRIANGLES);
      glVertex3f(-0.15,0.4,0.0);
      glVertex3f(0.15,0.4,0.0);
      glVertex3f(0.0,0.6,0.0);
   glEnd();



   //Boca
   glColor3f(1.0,0.3,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.2,0.1,0.0);
      glVertex3f(0.2,0.1,0.0);
      glVertex3f(0.2,0.20,0.0);
      glVertex3f(-0.2,0.20,0.0);
   glEnd();

   Circle(0.05,0.19, 0.15, 40, GL_FILL);
   Circle(0.05,-0.19, 0.15, 40, GL_FILL);

   //Oreja derecha
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(0.4,0.35,0.0);
      glVertex3f(0.55,0.35,0.0);
      glVertex3f(0.55,0.8,0.0);
      glVertex3f(0.4,0.8,0.0);
   glEnd(); 

   glColor3f(0.0,0.0,0.);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(0.4,0.35,0.0);
      glVertex3f(0.55,0.35,0.0);
      glVertex3f(0.55,0.8,0.0);
      glVertex3f(0.4,0.8,0.0);
   glEnd(); 


   
   //Oreja izquierda
   glLineWidth(1);
   glColor3f(1.0,0.8,0.6);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.4,0.35,0.0);
      glVertex3f(-0.55,0.35,0.0);
      glVertex3f(-0.55,0.8,0.0);
      glVertex3f(-0.4,0.8,0.0);
   glEnd(); 

   glColor3f(0.0,0.0,0.);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(-0.4,0.35,0.0);
      glVertex3f(-0.55,0.35,0.0);
      glVertex3f(-0.55,0.8,0.0);
      glVertex3f(-0.4,0.8,0.0);
   glEnd(); 


   //Ala sombrero
   glColor3f(0.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.7,1.1,0.0);
      glVertex3f(0.7,1.1,0.0);
      glVertex3f(0.7,1.4,0.0);
      glVertex3f(-0.7,1.4,0.0);
   glEnd(); 

   //Copa sombrero
   glColor3f(0.0,0.0,0.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.4,1.4,0.0);
      glVertex3f(0.4,1.4,0.0);
      glVertex3f(0.4,2.1,0.0);
      glVertex3f(-0.4,2.1,0.0);
   glEnd(); 

}


void logo()
{

   //cuadrado rosa
   glColor3f(1.0,0.0,0.7);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      glVertex3f(-0.5,0.0,0.0);
      glVertex3f(0.5,0.0,0.0);
      glVertex3f(0.5,1.0,0.0);
      glVertex3f(-0.5,1.0,0.0);
   glEnd(); 

   //cuadrado blanco

   glLineWidth(8);
   glColor3f(1.0,1.0,1.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   glBegin(GL_POLYGON);
      glVertex3f(-0.35,0.1,0.0);
      glVertex3f(0.35,0.1,0.0);
      glVertex3f(0.35,0.9,0.0);
      glVertex3f(-0.35,0.9,0.0);
   glEnd(); 


   //Circulo vacio

   glLineWidth(8);
   glColor3f(1.0,1.0,1.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
   Circle(0.17,0.0,0.5,200,GL_LINE);   
   
   //Circulo lleno

   glColor3f(1.0,1.0,1.0);
   glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
   glBegin(GL_POLYGON);
      Circle(0.05,0.25,0.75,200,GL_LINE);   
   glEnd(); 


}

static void Init( )
{

   glShadeModel( GL_SMOOTH);
}


static void Reshape( int width, int height )
{

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glViewport(0, 0, (GLint)width, (GLint)height);
   glOrtho (-2.0, 2.0,-2.0, 2.0, -20, 20.0);
}

static void Display( )
{

  glClearColor(0.5,0.5,0.5,0.0);
  glClear( GL_COLOR_BUFFER_BIT );
   

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   
   Ejes(6);
   Monigote();
   //logo();

   glFlush();
}


static void Keyboard(unsigned char key, int x, int y )
{
 
  if (key==27)
      exit(0);

}


int main( int argc, char **argv )
{
   glutInit(&argc,argv);
   glutInitDisplayMode( GLUT_RGB );

   glutInitWindowPosition( 300, 300 );
   glutInitWindowSize(1000, 1000 );
   glutCreateWindow("Practica 0 IG");


   Init();

   glutReshapeFunc(Reshape);
   glutDisplayFunc(Display);
   glutKeyboardFunc(Keyboard);
  
   glutMainLoop( );

   return 0;
}


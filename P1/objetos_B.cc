//**************************************************************************
// Práctica 1 usando objetos
//**************************************************************************

#include "objetos_B.h"


//*************************************************************************
// _puntos3D
//*************************************************************************


_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}



//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}




//*************************************************************************
// asignar colores random
//*************************************************************************
void _triangulos3D::asignar_colores_random()
{

	for(int i = 0; i < colores_caras.size(); i++){
		colores_caras[i].r = rand() % 1000 / 1000.0;
		colores_caras[i].g = rand() % 1000 / 1000.0;
		colores_caras[i].b = rand() % 1000 / 1000.0;
	}



}




//*************************************************************************
// asignar colores graduales
//*************************************************************************
void _triangulos3D::asignar_colores_graduales()
{

	float inicio_r = 1.0;
	float inicio_b = 0.5;
	for(int i = 0; i < colores_caras.size(); i++){
		colores_caras[i].r = inicio_r;
		colores_caras[i].g = rand() % 1000 / 1000.0;
		colores_caras[i].b = inicio_b;

		if(inicio_r > 0.5){
			inicio_r -= 1.0/colores_caras.size();
		}
		else if(inicio_b <= 0.8){
			inicio_b += 1.0/colores_caras.size();
		}

		if(inicio_b > 1.0){
			inicio_b = 1.0;
		}

	}




}




//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}



//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{

	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(r,g,b);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();

}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores( )
{

	int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();
}



//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
	//vertices
	vertices.resize(8);
	vertices[0].x=-tam/2;vertices[0].y=-tam/2;vertices[0].z=-tam/2;
	vertices[1].x=tam/2;vertices[1].y=-tam/2;vertices[1].z=-tam/2;
	vertices[2].x=-tam/2;vertices[2].y=tam/2;vertices[2].z=-tam/2;
	vertices[3].x=tam/2;vertices[3].y=tam/2;vertices[3].z=-tam/2;
	vertices[4].x=-tam/2;vertices[4].y=-tam/2;vertices[4].z=tam/2;
	vertices[5].x=tam/2;vertices[5].y=-tam/2;vertices[5].z=tam/2;
	vertices[6].x=-tam/2;vertices[6].y=tam/2;vertices[6].z=tam/2;
	vertices[7].x=tam/2;vertices[7].y=tam/2;vertices[7].z=tam/2;


	// triangulos
	caras.resize(12);
	caras[0]._0=3,caras[0]._1=1,caras[0]._2=0;
	caras[1]._0=0,caras[1]._1=2,caras[1]._2=3;
	caras[2]._0=7,caras[2]._1=5,caras[2]._2=1;
	caras[3]._0=1,caras[3]._1=3,caras[3]._2=7;
	caras[4]._0=6,caras[4]._1=4,caras[4]._2=5;
	caras[5]._0=5,caras[5]._1=7,caras[5]._2=6;
	caras[6]._0=2,caras[6]._1=0,caras[6]._2=4;
	caras[7]._0=4,caras[7]._1=6,caras[7]._2=2;
	caras[8]._0=7,caras[8]._1=3,caras[8]._2=2;
	caras[9]._0=2,caras[9]._1=6,caras[9]._2=7;
	caras[10]._0=0,caras[10]._1=1,caras[10]._2=5;
	caras[11]._0=5,caras[11]._1=4,caras[11]._2=0;

	colores_caras.resize(12);
	asignar_colores_random();
}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

	//vertices 
	vertices.resize(5); 
	vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
	vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
	vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

	caras.resize(6);
	caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
	caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
	caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
	caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
	caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
	caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

	
	colores_caras.resize(6);
	//asignar_colores_random();
	asignar_colores_graduales();
}




//*************************************************************************
// clase rombo
//*************************************************************************

_rombo::_rombo(float tam, float al)
{

	//vertices 
	vertices.resize(6); 
	vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
	vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
	vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
	vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
	vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;
	vertices[5].x=0;vertices[5].y=-al;vertices[5].z=0;


	caras.resize(8);
	caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
	caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
	caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
	caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
	caras[4]._0=0;caras[4]._1=1;caras[4]._2=5;
	caras[5]._0=1;caras[5]._1=2;caras[5]._2=5;
	caras[6]._0=2;caras[6]._1=3;caras[6]._2=5;
	caras[7]._0=3;caras[7]._1=0;caras[7]._2=5;

	colores_caras.resize(6);
	asignar_colores_random();
}


//visto en CLASE
//Clase basica es la clase puntos3D y en esa clase almacenamos el array de los vertices basicObject3D Tiene el metodo de pintar puntos
//Se declara clase caras que es el conjunto de 3 vertices en este caso triangulos3D object3D Restos de métodos para pintar
//Cada solido va a ser hijo de la clase triangulos3D



//**************************************************************************
// Práctica 2 
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


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


void _triangulos3D::asignar_colores_graduales_azul()
{

	float inicio_r = 1.0;
	float inicio_b = 0.5;
	for(int i = 0; i < colores_caras.size(); i++){
		colores_caras[i].r = 0.0;
		colores_caras[i].g = 0.0;
		colores_caras[i].b = inicio_b;

		inicio_b += 1.0/colores_caras.size();


		if(inicio_b > 1.0){
			inicio_b = 1.0;
		}

	}




}



void _triangulos3D::asignar_colores_graduales_rojo()
{

	float inicio_r = 1.0;
	float inicio_b = 0.5;
	for(int i = 0; i < colores_caras.size(); i++){
		colores_caras[i].r = inicio_r;
		colores_caras[i].g = 0.0;
		colores_caras[i].b = 0.0;

		inicio_r -= 1.0/colores_caras.size();


		if(inicio_r < 0.2){
			inicio_r = 0.2;
		}

	}




}


void _triangulos3D::asignar_colores_examen()
{

	float num;
	float umbral = 0.4;
	for(int i = 0; i < colores_caras.size(); i++){

		num = rand() % 1000 / 1000.0;
		
		if(num < umbral){
			
			colores_caras[i].r = 0.00392156863;
			colores_caras[i].g = 0.180392157;
			colores_caras[i].b = 0.403921569;

		}

		if( num >= umbral){

			colores_caras[i].r = 0.403921569;
			colores_caras[i].g = 0.443137255;
			colores_caras[i].b = 0.474509804;

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
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
	}
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

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



void _objeto_ply::parametros(char *archivo)
{
	int n_ver,n_car;

	vector<float> ver_ply ;
	vector<int>   car_ply ;
	
	_file_ply::read(archivo, ver_ply, car_ply );

	n_ver=ver_ply.size()/3;
	n_car=car_ply.size()/3;

	printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

	vertices.resize(n_ver);
	caras.resize(n_car);
	colores_caras.resize(n_car);
	asignar_colores_random();

	//Vertices
	for(int i = 0; i < n_ver; i++){
		vertices[i].x = ver_ply[i * 3];
		vertices[i].y = ver_ply[i * 3 + 1];
		vertices[i].z = ver_ply[i * 3 + 2];
	}


	//Caras
	for(int i = 0; i < n_car; i++){
		caras[i]._0 = car_ply[i * 3];
		caras[i]._1 = car_ply[i * 3 + 1];
		caras[i]._2 = car_ply[i * 3 + 2];
	}

}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num , int tapa_inf, int tapa_sup, int tipo)
{
	int i,j;
	_vertex3f vertice_aux;
	_vertex3i cara_aux;
	int num_aux;

	// tratamiento de los vértice


	num_aux=perfil.size();
	if(tipo > 1)
		num_aux = 1;
	vertices.resize(num_aux*num);
	for (j=0;j<num;j++)
	{for (i=0;i<num_aux;i++)
		{
		vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
						perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
		vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
						perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
		vertice_aux.y=perfil[i].y;
		vertices[i+j*num_aux]=vertice_aux;
		}
	}

	// tratamiento de las caras 

	if(tipo != 2){
		for(j = 0; j < num ; j ++){
			for(i = 0; i < num_aux - 1; i++){

				cara_aux._0 = i + j * num_aux;
				cara_aux._1 = i + ((j + 1) % num) * num_aux ;
				cara_aux._2 = i +1 + j * num_aux;
				caras.push_back(cara_aux);



				cara_aux._0 = i + ((j + 1) % num )* num_aux;
				cara_aux._1 = i + 1 + ((j + 1) % num)  * num_aux;
				cara_aux._2 = i + 1 + j * num_aux;
				caras.push_back(cara_aux);
					
			}
		}
	}
	
	// tapa inferior
	if(tapa_inf == 1){
		vertice_aux.x = 0.0;
		vertice_aux.y = perfil[0].y;
		vertice_aux.z = 0.0;
		vertices.push_back(vertice_aux);
	}


	for(j = 0; j < num; j++){

		cara_aux._0 = num_aux * num;
		cara_aux._1 = ((j +1 ) % num ) * num_aux;
		cara_aux._2 = j* num_aux;
		caras.push_back(cara_aux);
		
	}
	// tapa superior
 
	if(tapa_sup == 1){
		vertice_aux._0 = 0.0;
		vertice_aux._1 = perfil[num_aux - 1].y;
		if(tipo == 2)
			vertice_aux._1 = perfil[1].y;

		vertice_aux._2 = 0.0;
		vertices.push_back(vertice_aux);
		
	}


	
	for(j = 0; j < num; j++){

		if(tapa_inf == 1)
			cara_aux._0 = num_aux * num + 1;
		else
			cara_aux._0 = num_aux * num; 

		cara_aux._1 = j * num_aux + num_aux - 1;
		cara_aux._2 = ((j+1) % num ) * num_aux + num_aux - 1;
		caras.push_back(cara_aux);


	}

	colores_caras.resize(caras.size());
	if(tipo == 0)
		asignar_colores_examen();
	else if(tipo == 1)
		asignar_colores_graduales_azul();
	else if(tipo == 2)
		asignar_colores_graduales_rojo();
}




//*************************************************************************
// clase objeto ply revolucion
//*************************************************************************


_rotacion_Ply::_rotacion_Ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices

}



void _rotacion_Ply::parametros_Ply(char *archivo, int num)
{
	int n_ver,n_car;

	vector<float> ver_ply ;
	vector<int>   car_ply ;
	
	_file_ply::read(archivo, ver_ply, car_ply );

	n_ver=ver_ply.size()/3;
	n_car=car_ply.size()/3;

	printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

	vertices.resize(n_ver);
	caras.resize(n_car);
	colores_caras.resize(n_car);
	asignar_colores_random();

	//Vertices
	for(int i = 0; i < n_ver; i++){
		vertices[i].x = ver_ply[i * 3];
		vertices[i].y = ver_ply[i * 3 + 1];
		vertices[i].z = ver_ply[i * 3 + 2];
	}


	//Caras
	for(int i = 0; i < n_car; i++){
		caras[i]._0 = car_ply[i * 3];
		caras[i]._1 = car_ply[i * 3 + 1];
		caras[i]._2 = car_ply[i * 3 + 2];
	}

	//ply_miembro.parametros(archivo);

/*	vertices.resize(ply_miembro.vertices.size());
	cout << "COrrecto resize vertices" << endl;
	caras.resize(ply_miembro.caras.size());

	for(int i = 0; i < vertices.size(); i++){
		vertices[i].x = ply_miembro.vertices[i].x;
		vertices[i].y = ply_miembro.vertices[i].y;
		vertices[i].z = ply_miembro.vertices[i].z;
	}


	for(int i = 0; i < caras.size(); i++){
		caras[i]._0 = ply_miembro.caras[i]._0;
		caras[i]._1 = ply_miembro.caras[i]._1;
		caras[i]._2 = ply_miembro.caras[i]._2;
	}

*/
	parametros(vertices, num, 1, 1, 0);
}






//************************************************************************
// objeto cilindro
//************************************************************************
_cilindro::_cilindro(float radio, float altura, int lados)
{

	vector<_vertex3f> perfil;
	_vertex3f aux;

	aux.x = radio;
	aux.y = -altura / 2.0;
	aux.z = 0.0;
	perfil.push_back(aux);
	
	aux.x = radio;
	aux.y = altura / 2.0;
	aux.z = 0.0;
	perfil.push_back(aux);
	parametros(perfil, lados, 1, 1, 0);
}





//************************************************************************
// objeto cono
//************************************************************************

_cono::_cono(float radio, float altura, int lados)
{

	vector<_vertex3f> perfil;
	_vertex3f aux;

	aux.x = radio;
	aux.y = 0;
	aux.z = 0.0;
	perfil.push_back(aux);
	
	aux.x = 0;
	aux.y = altura;
	aux.z = 0.0;
	perfil.push_back(aux);
	parametros(perfil, lados, 1, 1, 2);
}




//************************************************************************
// objeto esfera
//************************************************************************


_esfera_examen::_esfera_examen(float radio,  int latitud, int longitud)
{

	vector<_vertex3f> perfil;
	_vertex3f aux;
	float angulo;

/*
	aux.x = 0.0;
	aux.y = radio;
	aux.z = 0.0;
	perfil.push_back(aux);

*/
	for (int i=1;i<latitud / 2;i++){
		aux.x = radio * cos(M_PI * i / (latitud * 1.0) - M_PI /2.0);
		aux.y = radio*sin(M_PI  * i / (latitud * 1.0) - M_PI /2.0);
		aux.z = 0.0;
		perfil.push_back(aux);
	}
/*
	aux.x = 0.0;
	aux.y = -radio;
	aux.z = 0.0;
	perfil.push_back(aux);

*/
	parametros(perfil, 1, 1, 1, 1);

}

//************************************************************************
// objeto esfera
//************************************************************************

_esfera::_esfera(float radio,  int latitud, int longitud)
{

	vector<_vertex3f> perfil;
	_vertex3f aux;
	float angulo;

/*
	aux.x = 0.0;
	aux.y = radio;
	aux.z = 0.0;
	perfil.push_back(aux);

*/
	for (int i=1;i<latitud;i++){
	aux.x = radio * cos(M_PI * i / (latitud * 1.0) - M_PI /2.0);
	aux.y = radio*sin(M_PI * i / (latitud * 1.0) - M_PI /2.0);
	aux.z = 0.0;
	perfil.push_back(aux);
	}
/*
	aux.x = 0.0;
	aux.y = -radio;
	aux.z = 0.0;
	perfil.push_back(aux);

*/
	parametros(perfil, longitud, 1, 1, 1);

}

//************************************************************************
// objeto por extrusión
//************************************************************************


_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
int i;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=poligono.size();
vertices.resize(num_aux*2);
for (i=0;i<num_aux;i++)
    {
      vertices[2*i]=poligono[i];
      vertices[2*i+1].x=poligono[i].x+x;
      vertices[2*i+1].y=poligono[i].y+y;
      vertices[2*i+1].z=poligono[i].z+z;
    }
    
// tratamiento de las caras 

caras.resize(num_aux*2);
int c=0;
for (i=0;i<num_aux;i++)         
  {
   caras[c]._0=i*2;
   caras[c]._1=(i*2+2)%(num_aux*2);
   caras[c]._2=i*2+1;    
   c=c+1;
   caras[c]._0=(i*2+2)%(num_aux*2);
   caras[c]._1=(i*2+2)%(num_aux*2)+1;
   caras[c]._2=i*2+1;    
   c=c+1;    
      
   }   
}



//************************************************************************
// MODELO JERARQUICO PRACTICA3
//************************************************************************


//************************************************************************
// clase rueda
//************************************************************************
_rueda::_rueda(){

}

void _rueda::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glRotatef(90, 0, 0, 1);


		//Neumatico parte negra
		glPushMatrix();
			glScalef(1.8, 0.79, 1.8);
			neumatico.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Llanta parte gris
		glPushMatrix();
			glScalef(1.5, 0.8, 1.5);
			llanta.draw(modo, 0.5, 0.5, 0.5, grosor);
		glPopMatrix();

		glPushMatrix();

			glTranslated(0, 0.4, 0);

			//Radio 1 el vertical
			glPushMatrix();
				glRotatef(90,0,0,1);
				glScalef(0.05, 1.5, 0.05),
				neumatico.draw(modo, r, g, b, grosor);
			glPopMatrix();
			
			//Radio 2 el horizontal
			glPushMatrix();
				glRotatef(90,1,0,0);
				glScalef(0.05, 1.5, 0.05),
				neumatico.draw(modo, r, g, b, grosor);
			glPopMatrix();

			//Radio 3 inclinado hacia la izquierda
			glPushMatrix();
				glRotatef(45,0,1,0);
				glRotatef(90,0,0,1);
				glScalef(0.05, 1.5, 0.05),
				neumatico.draw(modo, r, g, b, grosor);
			glPopMatrix();

			//Radio 4 inclinado hacia la derecha
			glPushMatrix();
				glRotatef(-45,0,1,0);
				glRotatef(90,0,0,1);
				glScalef(0.05, 1.5, 0.05),
				neumatico.draw(modo, r, g, b, grosor);
			glPopMatrix();


		glPopMatrix();

	glPopMatrix();
}



//************************************************************************
// CLASE PUERTA
//************************************************************************
_puerta::_puerta(){

}

void _puerta::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

	
		//Panel principal
		glPushMatrix();
			glTranslated(0.5, 0.0, 0.0);
			glScalef(2, 1.5, 0.2);
			panel.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Pilar 1
		glPushMatrix();
			glTranslated(0.05, 0.65, 0);
			glScalef(0.2, 1.2, 0.2);
			pilar1.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Pilar 2
		glPushMatrix();
			glTranslated(0.89, 0.62, 0);
			glRotated(13, 0, 0, 1);
			glScalef(0.2, 1.2, 0.199);
			pilar2.draw(modo, r, g, b, grosor);	
		glPopMatrix();

		//Parte superior
		glPushMatrix();
			glTranslated(0.445, 0.95, 0);
			glScalef(1.75, 0.2, 0.2);
			superior.draw(modo, r, g, b, grosor);
		glPopMatrix();

	glPopMatrix();
}


//************************************************************************
// CLASE ASIENTO
//************************************************************************
_asiento::_asiento(){

}

void _asiento::draw(_modo modo, float r, float g, float b, float grosor){

		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();

			//Sujeccion parte mas abajo
			glPushMatrix();
				glTranslated(0, -0.12, 0);
				glScalef(0.7, 0.25, 0.7);
				sujeccion.draw(modo, r, g, b, grosor);
			glPopMatrix();

			//Base o asiento
			glPushMatrix();
				glScalef(1, 0.25, 1);
				base.draw(modo, r, g, b, grosor);
			glPopMatrix();

			//Respaldo
			glPushMatrix();
				glTranslated(0, 0.42, -0.21);
				glRotatef(-4 ,1 ,0, 0);
				glScalef(0.99, 1.5, 0.25);
				respaldo.draw(modo, r, g, b, grosor);
			glPopMatrix();


			//Sujetacabezas
			glPushMatrix();

				glTranslated(0, 1.04, -0.18);
				glPushMatrix();
					glRotatef(90, 0, 0, 1);
					glScalef(0.1, 0.35, 0.1);
					reposa_cabezas.draw(modo, r, g, b, grosor);
				glPopMatrix();

				glPushMatrix();
					glTranslated(-0.05, -0.15, 0);
					glScalef(0.05, 0.2, 0.05);
					sujeta_repos_1.draw(modo, r, g, b, grosor);
				glPopMatrix();

				glPushMatrix();
					glTranslated(0.05, -0.15, 0);
					glScalef(0.05, 0.2, 0.05);
					sujeta_repos_2.draw(modo, r, g, b, grosor);
				glPopMatrix();

			glPopMatrix();

		glPopMatrix();

}





//************************************************************************
// CLASE PARED VENTANA
//************************************************************************

_pared_ventana::_pared_ventana(){

}


void _pared_ventana::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//Parte vertical grande de a puerta
		glPushMatrix();
			glTranslated(0, 0.425, -2.5);
			glScalef(0.2, 2.7, 2);
			tabiqueIT.draw(modo, r, g, b, grosor);
		glPopMatrix();


		//Parte horizontal inferior
		glPushMatrix();
			glTranslated(0, 0, -1);
			glScalef(0.2, 1, 4);
			panelII.draw(modo, r, g, b, 8);
		glPopMatrix();

		//Parte horizontal superior
		glPushMatrix();
			glTranslated(0, 0.85, -1);
			glScalef(0.2, 1, 4);
			panelIS.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Parte vertical pequeña
		glPushMatrix();
			glTranslated(0, 0.4, -0.475);
			glScalef(0.2, 0.8, 1.9);
			panelIC.draw(modo, r, g, b, grosor);
		glPopMatrix();

	glPopMatrix();
}

//************************************************************************
// CLASE EJE RUEDAS
//************************************************************************
_eje_ruedas::_eje_ruedas(){

}

void _eje_ruedas::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glPushMatrix();
			glRotatef(90, 0, 0, 1);
			glScalef(0.25, 8, 0.25);
			eje.draw(modo, 0.5, 0.5, 0.5, 8);
		glPopMatrix();

		//Rueda dcha
		glPushMatrix();
			glTranslated(4, 0, 0);
			glRotatef(180, 0, 0, 1);
			rueda1.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Rueda izda
		glPushMatrix();
			glTranslated(-4, 0, 0);
			rueda2.draw(modo, r, g, b, grosor);
		glPopMatrix();

	glPopMatrix();
}


//************************************************************************
// CLASE PLATAFORMA
//************************************************************************
_plataforma::_plataforma(){

	posicion_asiento = 1.5;
	posicion_asiento_min = 1.5;
	posicion_asiento_max = 0;
}

void _plataforma:: draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//Base
		glPushMatrix();
			glScalef(14.4, 1, 20);
			base.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Eje delantero
		glPushMatrix();
			glTranslated(0, -0.4, 3);
			eje_delantero.draw(modo, 0.0, 0.0, 0.0, grosor);
		glPopMatrix();

		//Eje trasero
		glPushMatrix();
			glTranslated(0, -0.4, -3);
			eje_trasero.draw(modo, 0.0, 0.0, 0.0, grosor);
		glPopMatrix();

		//asiento derecha
		glPushMatrix();
			glTranslated(1.5, 0.4, posicion_asiento);
			asientoDcha.draw(modo, 0.0, 1.0, 0.0, grosor);
		glPopMatrix();	

		//asiento izquierda
		glPushMatrix();
			glTranslated(-1.5, 0.4, posicion_asiento);
			asientoIzda.draw(modo, 0.0, 1.0, 0.0, grosor);
		glPopMatrix();

	glPopMatrix();

}



//************************************************************************
// CLASE CHASIS
//************************************************************************
_coche::_coche(){

	angulo_puertas = 0.0;
	angulo_puertas_max = 90.0;
	tam_luz = 0.5;
	tam_luz_min = 0.2;
	tam_luz_max = 1;
	mov_techo_y = 1.65;
	mov_techo_y_max = 1.65;
	mov_techo_y_min = 1;
	mov_techo_z = -0.03;
	mov_techo_z_max = -3;
	mov_techo_z_min = -0.03;

}



void _coche::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glPushMatrix();
			plataforma.draw(modo, 0.5, 0.0, 0.5, 8);
		glPopMatrix();

		//Puerta derecha
		glPushMatrix();
			glTranslated(3.65, 0.6, 2);
			glTranslated(-0.1, 0, -1);
			glRotatef(angulo_puertas, 0, 1, 0);
			glRotatef(-90, 0, 1, 0);
			puertaD.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Puerta izquierda
		glPushMatrix();
			glTranslated(-3.44, 0.6, 2);
			glTranslated(-0.1, 0, -1);
			glRotatef(-angulo_puertas, 0, 1, 0);
			glRotatef(-90, 0, 1, 0);
			puertaI.draw(modo, r, g, b, grosor);	
		glPopMatrix();

		//Motor
		glPushMatrix();
			glTranslated(0, 0.6, 3.5);
			glScalef(14.4, 1.45, 6);
			motor.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Tabique derecho delantero
		glPushMatrix();
			glTranslated(3.55, 1.28, 1.98);
			glRotatef(-13, 1, 0, 0);
			glScalef(0.201, 1.3, 0.201);
			tabiqueDD.draw(modo, 0.0, 0.0, 0.5, grosor);
		glPopMatrix();

		//Tabique izquierdo delantero
		glPushMatrix();
			glTranslated(-3.55, 1.28, 1.98);
			glRotatef(-13, 1, 0, 0);
			glScalef(0.201, 1.3, 0.201);
			tabiqueID.draw(modo, 0.0, 0.0, 0.5, grosor);
		glPopMatrix();

		//Ventana izquierda
		glPushMatrix();
			glTranslated(-3.55, 0.5, 1.0);
			paredI.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Ventana derecha
		glPushMatrix();
			glTranslated(3.55, 0.5, 1.0);
			paredD.draw(modo, r, g, b, grosor);
		glPopMatrix();

		//Techo
		glPushMatrix();
			glTranslated(0, mov_techo_y, mov_techo_z);
			glScalef(14.4, 0.2, 7.9);
			techo.draw(modo, 0.0, 0.0, 0.0, grosor);
		glPopMatrix();

	

		//Maletero
		glPushMatrix();
			glTranslated(0, 0.6, -3.5);
			glScalef(14.4, 1.45, 6);
			maletero.draw(modo, r, g, b, grosor);
		glPopMatrix();

				
		//Luz derecha
		glPushMatrix();
			glTranslatef(2, 0.5, 5);
			glRotated(90, 1, 0, 0);
			glScalef(tam_luz, 0.2, tam_luz);
			luzD.draw(modo, 1.0, 1.0, 0.0, grosor);
		glPopMatrix();


		//Luz izquierda
		glPushMatrix();
			glTranslatef(-2, 0.5, 5);
			glRotated(90, 1, 0, 0);
			glScalef(tam_luz, 0.2, tam_luz);
			luzI.draw(modo, 1.0, 1.0, 0.0, grosor);
		glPopMatrix();


		//Matricula
		glPushMatrix();
			glTranslatef(0, 0.4, 5);
			glScalef(2, 0.5, 0.2);
			matricula.draw(modo, 1.0, 1.0, 1.0, grosor);
		glPopMatrix();


	glPopMatrix();
}


//************************************************************************
// CLASE COCHE
//************************************************************************
/*_coche::_coche(){

}

void _coche::draw(_modo modo, float r, float g, float b, float grosor){
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		//Principal
		glPushMatrix();
			chasis.draw(modo, r, g, b, grosor);
		glPopMatrix();

		
		//Luz derecha
		glPushMatrix();
			glTranslatef(2, 0.5, 5);
			glRotated(90, 1, 0, 0);
			glScalef(0.5, 0.2, 0.5);
			luzD.draw(modo, 1.0, 1.0, 0.0, grosor);
		glPopMatrix();


		//Luz izquierda
		glPushMatrix();
			glTranslatef(-2, 0.5, 5);
			glRotated(90, 1, 0, 0);
			glScalef(0.5, 0.2, 0.5);
			luzI.draw(modo, 1.0, 1.0, 0.0, grosor);
		glPopMatrix();


		//Matricula
		glPushMatrix();
			glTranslatef(0, 0.4, 5);
			glScalef(2, 0.5, 0.2);
			matricula.draw(modo, 1.0, 1.0, 1.0, grosor);
		glPopMatrix();

	glPopMatrix();
}*/


_brazo::_brazo(){
	giro_aspa = 0;
}


void _brazo::draw(_modo modo, float r, float g, float b, float grosor){
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glPushMatrix();
			glScalef(4, 1, 1);
			soporte.draw(modo, r, g, b, grosor);
		glPopMatrix();
	
		glPushMatrix();
			glTranslated(-1.1, 0.0, 0.0);
			glRotated(giro_aspa, 1, 0, 0);
			glRotated(90, 0, 1, 0);
			glScalef(4, 0.2, 0.2);
			aspa.draw(modo, 0.5, 0.0, 0.5, grosor);
		glPopMatrix();

	glPopMatrix();
}


_molino::_molino(){
	tam_molino = 2.0;
}

void _molino::draw(_modo modo, float r, float g, float b, float grosor){

	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();

		glPushMatrix();
			glTranslated(0.0, tam_molino/2, 0.0);
			glScalef(0.3, tam_molino, 0.3);
			base.draw(modo, 1.0, 0.0, 0.0, grosor);
		glPopMatrix();

		glPushMatrix();
			glTranslated(0.0, tam_molino, 0.0);
			brazo.draw(modo, 0.0, 0.0, 1.0, grosor);
		glPopMatrix();

	glPopMatrix();

}


_copa::_copa(){

}

void _copa:: parametros_copa(vector<_vertex3f> perfil){

	_esfera_examen esfera;
	for(int i = 0; i < esfera.vertices.size(); i++){
			esfera.vertices[i].x += 0.5;
			esfera.vertices[i].y += 0.5 + 1.5; 
			perfil.push_back(esfera.vertices[i]);
	}

	parametros(perfil, 10, 1, 1, 0);
}
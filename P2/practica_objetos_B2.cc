//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include "objetos_B2.h"


using namespace std;

// tipos
typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, ROTACION, EXTRUSION, CILINDRO, CONO, ESFERA, ROTACION_PLY, RUEDA, PUERTA, ASIENTO, 
PARED_VENTANA, EJE_RUEDAS, PLATAFORMA, CHASIS, COCHE} _tipo_objeto;
_tipo_objeto t_objeto=CUBO;
_modo   modo=POINTS;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Size_x,Size_y,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int Window_x=50,Window_y=50,Window_width=650,Window_high=650;


// objetos
_cubo cubo;
_piramide piramide(0.85,1.3);
_objeto_ply  ply; 
_rotacion rotacion; 
_extrusion *extrusion;
_cilindro cilindro (0.5, 1, 12);
_cono cono (1, 2, 20);
_esfera esfera(2, 40, 40);
_rotacion_Ply rotacion_ply;
_rueda rueda;
_puerta puerta;
_asiento asiento;
_pared_ventana pared_ventana;
_eje_ruedas eje_ruedas;
_plataforma plataforma;
//_chasis chasis;
_coche coche;
// _objeto_ply *ply;


int pulsar = 0; 
int paso = 0;
float mov_y = 0; 
float mov_z = 0;
int alfa = 0;
bool pulsada = true;

/***************************************************************************/
int EstadoRaton;
int xc;
int yc;
int cambio = 0;
float factor = 1.0;
int alto;
int ancho;

//**************************************************************************
//
//***************************************************************************

void clean_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,plano_delantero, plano_traser)
//  plano_delantero>0  plano_trasero>PlanoDelantero)
glFrustum(-Size_x,Size_x,-Size_y,Size_y,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación*ply1 de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
	
glDisable(GL_LIGHTING);
glLineWidth(2);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//****************************2***********************************************

void draw_objects()
{

switch (t_objeto){
	case CUBO: cubo.draw(modo,1.0,0.0,0.0,8);break;
	case PIRAMIDE: piramide.draw(modo,1.0,0.0,0.0,8);break;
        case OBJETO_PLY: ply.draw(modo,1.0,0.6,0.0,8);break;
        case ROTACION: rotacion.draw(modo,1.0,0.0,0.0,8);break;
        case EXTRUSION: extrusion->draw(modo,1.0,0.0,0.0,8);break;
		case CILINDRO: cilindro.draw(modo,1.0,0.0,0.0,8);break;
		case CONO: cono.draw(modo,1.0,0.0,0.0,8);break;
		case ESFERA: esfera.draw(modo,1.0,0.0,0.0,8);break;
		case ROTACION_PLY: rotacion_ply.draw(modo,1.0,0.0,0.0,8);break;
		case RUEDA: rueda.draw(modo, 0.0, 0.0, 0.0, 8);break;
		case PUERTA: puerta.draw(modo, 0.0, 0.0, 1.0, 8);break;
		case ASIENTO: asiento.draw(modo, 0.0, 1.0, 0.0, 8);break;
		case PARED_VENTANA: pared_ventana.draw(modo, 0.0, 0.0, 1.0, 8);break;
		case EJE_RUEDAS: eje_ruedas.draw(modo, 0.0, 0.0, 0.0, 8);break;
		case PLATAFORMA: plataforma.draw(modo, 0.5, 0.0, 0.5, 8); break;
		//case CHASIS: chasis.draw(modo, 0.0, 0.0, 1.0, 8); break;
		case COCHE: coche.draw(modo, 0.0, 0.0, 1.0, 8); break;
	}

}

//**************************************************************************
//
//***************************************************************************


void enceder_luz(){
	if(pulsada)
		pulsada = false;
	else
		pulsada = true;
}

void draw_lights(){

    GLfloat luz_ambiente [] = {0.1, 0.1, 0.1, 1.0},
            luz_difusa [] = {1.0, 1.0, 1.0, 1.0},
            luz_especular [] = {1.0, 1.0, 1.0, 1.0},
            luz_posicion [] = {20.0, 20.0, 20.0, 1};


    GLfloat luz_ambiente2 [] = {0.0, 0.1, 0.0, 1.0},
            luz_difusa2 [] = {0.0, 1.0, 0.0, 1.0},
            luz_especular2 [] = {0.0, 1.0, 0.0, 1.0},
            luz_posicion2 [] = {0.0, 10.0, 20.0, 1};
        
        
    glLightfv(GL_LIGHT1, GL_AMBIENT, luz_ambiente);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, luz_difusa);
    glLightfv(GL_LIGHT1, GL_SPECULAR, luz_difusa);
    
    glLightfv(GL_LIGHT1, GL_POSITION, luz_posicion);


    glLightfv(GL_LIGHT2, GL_AMBIENT, luz_ambiente2);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, luz_difusa2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, luz_especular2);
    
   	glPushMatrix();
        glRotatef(alfa, 0, 1, 0);
		glLightfv(GL_LIGHT2, GL_POSITION, luz_posicion2);
    glPopMatrix();




    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
	if(pulsada)
		glEnable(GL_LIGHT2);
	else
		glDisable(GL_LIGHT2);


}


void vistaOrtogonal(){

	glMatrixMode(GL_PROJECTION); //perfil
	glLoadIdentity();
	glViewport(ancho/2, alto/2, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor , 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	draw_objects();

	glMatrixMode(GL_PROJECTION); // alzado
	glLoadIdentity();
	glViewport(0, alto/2, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor, 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	draw_objects();

	glMatrixMode(GL_PROJECTION); // planta
	glLoadIdentity();
	glViewport(ancho/2, 0, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor, 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	draw_objects();

	glMatrixMode(GL_PROJECTION); // perspectiva
	glLoadIdentity();
	glViewport(0, 0, ancho/2, alto/2);
	glFrustum (-1.0 * factor, 1.0 * factor, -1.0 * factor, 0.5 * factor,2.0,80.0);
	glTranslatef(0.0,0.0,-2.0);
	glRotatef(-35.0,1,0,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	draw_objects();
	glFlush();

}



void vistaOrtogonal_seleccion(){

	glMatrixMode(GL_PROJECTION); //perfil
	glLoadIdentity();
	glViewport(ancho/2, alto/2, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor , 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	coche.seleccion();



	glMatrixMode(GL_PROJECTION); // alzado
	glLoadIdentity();
	glViewport(0, alto/2, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor, 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,0.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	coche.seleccion();


	glMatrixMode(GL_PROJECTION); // planta
	glLoadIdentity();
	glViewport(ancho/2, 0, ancho/2, alto/2);
	glOrtho(-5.0 * factor, 5.0 * factor, -5.0 * factor, 5.0 * factor,-15.0,15.0);
	glRotatef(90.0,1.0,0.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	coche.seleccion();


	glMatrixMode(GL_PROJECTION); // perspectiva
	glLoadIdentity();
	glViewport(0, 0, ancho/2, alto/2);
	glFrustum (-1.0 * factor, 1.0 * factor, -1.0 * factor, 0.5 * factor,2.0,80.0);
	glTranslatef(0.0,0.0,-2.0);
	glRotatef(-35.0,1,0,0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw_axis();
	coche.seleccion();
	glFlush();

}


//**************************************************************************
//
//***************************************************************************

void draw(void)
{
glDrawBuffer(GL_FRONT);
clean_window();

//change_observer();
//draw_lights();
//draw_axis();
//draw_objects();
//glutSwapBuffers();


	if(cambio == 0){
		glViewport(0, 0, ancho, alto);
		change_projection();
		change_observer();
		draw_lights();
		draw_axis();
		draw_objects();
	}else{
		vistaOrtogonal();
		draw_lights();
		glutPostRedisplay();
	}

	if(t_objeto == COCHE){
		glDrawBuffer(GL_BACK);
   		clean_window();

		if(cambio == 0){
			glViewport(0, 0, ancho, alto);
			change_projection();
			change_observer();
			coche.seleccion();
		}else{
			vistaOrtogonal_seleccion();

		}

	}

	glFlush();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************
void change_window_size(int Ancho1,int Alto1)
{
float Aspect_ratio;

Aspect_ratio=(float) Alto1/(float )Ancho1;
Size_y=Size_x*Aspect_ratio;
change_projection();
glViewport(Ancho1,Alto1,Ancho1,Alto1);
ancho = Ancho1;
alto = Alto1;
glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_key(unsigned char Tecla1,int x,int y)
{
switch (toupper(Tecla1)){
	case 'Q':exit(0);
	case '1':modo=POINTS;break;
	case '2':modo=EDGES;break;
	case '3':modo=SOLID;break;
	case '4':modo=SOLID_COLORS;break;
	case '5':modo=SOLID_COLORS_GOUROUD;break;
    case '6':modo=SOLID_PHONG_FLAT;break;
    case '7':modo=SOLID_PHONG_GOUROUD;break;
        case 'P':t_objeto=PIRAMIDE;break;
        case 'C':t_objeto=CUBO;break;
        case 'O':t_objeto=OBJETO_PLY;break;	
        case 'R':t_objeto=ROTACION;break;
        case 'X':t_objeto=EXTRUSION;break;
		case 'L':t_objeto=CILINDRO;break;
		case 'Z':t_objeto=CONO;break;
		case 'E':t_objeto=ESFERA;break;
		case 'A':t_objeto=ROTACION_PLY;break;
		case 'J':t_objeto=COCHE;break;
		case 'M':if(pulsar == 0){
					mov_y = 0.001;
					mov_z = 0.003;
					pulsar = 1;
				 }
				break;
		case ',':cambio = 0;break;
		case ';':cambio = 1;break;
		case '9':factor *= 0.9;break;
		case '0':factor *= 1.1;break;
	}
glutPostRedisplay();
}

//***************************************************************************
// Funcion l-olamada cuando se aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton-
// posicion y del raton

//***************************************************************************

void special_key(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;

	case GLUT_KEY_F1:
		coche.angulo_puertas += 5;
		if(coche.angulo_puertas >= coche.angulo_puertas_max)
			coche.angulo_puertas = coche.angulo_puertas_max;
		break;
	case GLUT_KEY_F2:
		coche.angulo_puertas -= 5;
		if(coche.angulo_puertas <= 0)
			coche.angulo_puertas = 0;
		break;

	case GLUT_KEY_F3:
		coche.plataforma.posicion_asiento -= 0.05;
		if(coche.plataforma.posicion_asiento <= coche.plataforma.posicion_asiento_max)
			coche.plataforma.posicion_asiento = coche.plataforma.posicion_asiento_max;
		break;

	case GLUT_KEY_F4:
		coche.plataforma.posicion_asiento += 0.05;
		if(coche.plataforma.posicion_asiento >= coche.plataforma.posicion_asiento_min)
			coche.plataforma.posicion_asiento = coche.plataforma.posicion_asiento_min;
		break;
	case GLUT_KEY_F5:
		coche.tam_luz += 0.05;
		if(coche.tam_luz >= coche.tam_luz_max)
			coche.tam_luz = coche.tam_luz_max;
		break;
	case GLUT_KEY_F6:
		coche.tam_luz -= 0.05;
		if(coche.tam_luz <= coche.tam_luz_min)
			coche.tam_luz = coche.tam_luz_min;
		break;
	case GLUT_KEY_F7:
		alfa += 20;
		if(alfa >= 360)
			alfa = 0;
		break;
	case GLUT_KEY_F8:
		enceder_luz();
		break;
	}
glutPostRedisplay();
}


//***************************************************************************
// Movimiento automatico
//***************************************************************************
void animacion()
{

	switch(paso){
		case 0:
				coche.mov_techo_z -= mov_z;

				if(coche.mov_techo_z < coche.mov_techo_z_max){
					paso = 1;
				}
		break;
		case 1:
				coche.mov_techo_y -= mov_y;
			
				if(coche.mov_techo_y < coche.mov_techo_y_min ){
					paso = 0;
					coche.mov_techo_y = 1.65;
					coche.mov_techo_z = -0.03;
				}
		break;
	}
glutPostRedisplay();
}

//***************************************************************************
// Funcion para la seleccion
//***************************************************************************
void procesar_color(unsigned char color[3])
{
	int i;

	for (i=0;i<coche.piezas;i++){
		if (color[0]==coche.color_select[i].r && color[1]==coche.color_select[i].g && color[2]==coche.color_select[i].r){
			if (coche.activo[i] == 0){
				coche.activo[i] = 1;
            }else {
				coche.activo[i] = 0;
            }
         glutPostRedisplay();
        }
    }                
}



void pick_color(int x, int y){
	GLint viewport[4];
	unsigned char pixel[3];

	
	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadBuffer(GL_BACK);
	glReadPixels(x,viewport[3]-y,1,1,GL_RGB,GL_UNSIGNED_BYTE,(GLubyte *) &pixel[0]);
	printf(" valor x %d, valor y %d, color %d, %d, %d \n",x,y,pixel[0],pixel[1],pixel[2]);

	procesar_color(pixel);
}


//***************************************************************************
// Funcion de raton
//***************************************************************************
void clickRaton(int boton, int estado, int x, int y){

	if(boton == GLUT_RIGHT_BUTTON){
		if(estado == GLUT_DOWN){
			EstadoRaton = 1;
			xc = x;
			yc = y;
		}else {
			EstadoRaton = 0;
		}
	}
	if(boton == GLUT_LEFT_BUTTON){
		if(estado == GLUT_DOWN){
			EstadoRaton = 2;
			xc = x;
			yc = y;
			pick_color(xc, yc);
		}
	}

	if(boton == 3){
		factor *= 1.1;
		glutPostRedisplay();
	}

	if(boton == 4){
		factor *= 0.9;
		glutPostRedisplay();
	}

}



void RatonMovido(int x, int y){
	if(EstadoRaton == 1){
		Observer_angle_y=Observer_angle_y-(x-xc);
    	Observer_angle_x=Observer_angle_x+(y-yc);
     	xc=x;
     	yc=y;
     	glutPostRedisplay();
	}
}

//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Size_x=0.5;
Size_y=0.5;
Front_plane=1;
Back_plane=1000;

// se incia la posicion del observador, en el eje z
Observer_distance=4*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,Window_width,Window_high);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************


int main(int argc, char *argv[] )
{
 
// perfil 

vector<_vertex3f> perfil, poligono;
_vertex3f aux;

aux.x=1.0; aux.y=-1.5; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.4; aux.y=-0.5; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.4; aux.y=0.5; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.0; aux.y=1.5; aux.z=0.0;
perfil.push_back(aux);


rotacion.parametros(perfil,6,1,1, 0);

aux.x=1.0; aux.y=0.0; aux.z=1.0;
poligono.push_back(aux);
aux.x=1.0; aux.y=0.0; aux.z=-1.0;
poligono.push_back(aux);
aux.x=-1.2; aux.y=0.0; aux.z=-1.0;
poligono.push_back(aux);
aux.x=-0.8; aux.y=0.0; aux.z=0.0;
poligono.push_back(aux);
aux.x=-1.2; aux.y=0.0; aux.z=1.0;
poligono.push_back(aux);

extrusion= new _extrusion(poligono, 0.25, 1.0, 0.25);

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido_rotation Rotation;
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(Window_x,Window_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(Window_width,Window_high);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("PRACTICA - 2");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw);
// asignación de la funcion llamada "change_window_size" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "normal_key" al evento correspondiente
glutKeyboardFunc(normal_key);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_key);


//Animacion auto
glutIdleFunc(animacion);

// funcion de inicialización
initialize();

// creación del objeto ply
ply.parametros(argv[1]);
rotacion_ply.parametros_Ply(argv[2], 20);

//ply = new _objeto_ply(argv[1]);

// eventos ratón
glutMouseFunc(clickRaton);
glutMotionFunc(RatonMovido);

// inicio del bucle de eventos
glutMainLoop();
return 0;
}

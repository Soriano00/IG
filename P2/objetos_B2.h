//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>


const float AXIS_SIZE=5000;
typedef enum{POINTS,EDGES,SOLID,SOLID_COLORS, SOLID_COLORS_GOUROUD, SOLID_PHONG_FLAT, SOLID_PHONG_GOUROUD, SELECT} _modo;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:

  
	_puntos3D();
void 	draw_puntos(float r, float g, float b, int grosor);

vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
void 	draw_aristas(float r, float g, float b, int grosor);
void    draw_solido(float r, float g, float b);
void 	draw_solido_colores();
void   draw_solido_colores_vertices();
void 	draw(_modo modo, float r, float g, float b, float grosor);
void   draw_solido_brillo_plano();
void   draw_solido_brillo_suave();
void   draw_seleccion(int r, int g, int b);

/*asignar colores*/
void	asignar_colores_random();
void	asignar_colores_graduales();
void	asignar_colores_graduales_azul();
void	asignar_colores_graduales_rojo();
void    colors_diffuse_flat (float kr, float kg, float kb,
                             float lpx, float lpy, float lpz);
                             
void    colors_diffuse_gouraud  (float kr, float kg, float kb,
                                 float lpx, float lpy, float lpz);                            
/* calcular normales */

void    calcular_normales_caras();
void    calcular_normales_vertices();
void    calcular_normales_vertices_esfera();

int calcular_nc;
int calcular_nv;


vector<_vertex3i> caras;
vector<_vertex3f> colores_caras; 
vector<_vertex3f> colores_vertices;
vector<_vertex3f> normales_caras;
vector<_vertex3f> normales_vertices;
//material
_vertex4f ambiente;
_vertex4f difuso;
_vertex4f especular;
float brillo;


};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=1.0);
};



class _rombo: public _triangulos3D
{
public:

	_rombo(float tam=0.5, float al=1.0);
};


//*************************************************************************
// clase objeto ply
//*************************************************************************

class _objeto_ply: public _triangulos3D
{
public:
   _objeto_ply();

void  parametros(char *archivo);
};

//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion: public _triangulos3D
{
public:
       _rotacion();
       
void  parametros(vector<_vertex3f> perfil, int num, int tapa_inf, int tapa_sup, int tipo);

//0 revolucion normal
//1 esfera
//2 cono
};


//************************************************************************
// objeto por revolución
//************************************************************************

class _rotacion_Ply: public _rotacion
{

public:
       _rotacion_Ply();
       
void  parametros_Ply(char *archivo, int num);

//0 revolucion normal
//1 esfera
//2 cono
};

//************************************************************************
// clase cilindro
//************************************************************************

class _cilindro: public _rotacion
{
public:
       _cilindro(float radio = 0.5, float altura = 1.0, int lados = 24);
};


//************************************************************************
// clase esfera
//************************************************************************

class _esfera: public _rotacion
{
public:
       _esfera(float radio, int latitud, int longitud);
};


//************************************************************************
// clase cono
//************************************************************************

class _cono: public _rotacion
{
public:
       _cono(float radio, float altura, int lados);
};




//************************************************************************
// objeto por extrusión
//************************************************************************

class _extrusion: public _triangulos3D
{
public:
       _extrusion(vector<_vertex3f> poligono, float x, float y, float z);
};




//************************************************************************
// MODELO JERARQUICO PRACTICA 3
//************************************************************************


//************************************************************************
// CLASE RUEDA
//************************************************************************
class _rueda: public _triangulos3D
{
public:
       _rueda();
       void draw(_modo modo, float r, float g, float b, float grosor);

protected:
_cilindro neumatico; 
_cilindro llanta;

};


//************************************************************************
// CLASE PUERTA
//************************************************************************
class _puerta: public _triangulos3D
{
public:
       _puerta();
       void draw(_modo modo, float r, float g, float b, float grosor);

protected:
_cubo panel;
_cubo pilar1;
_cubo pilar2;
_cubo superior;
};



//************************************************************************
// CLASE ASIENTO
//************************************************************************
class _asiento: public _triangulos3D
{
public:
       _asiento();
       void draw(_modo modo, float r, float g, float b, float grosor);

protected:
_cubo sujeccion;
_cubo base;
_cubo respaldo;
_cilindro reposa_cabezas;
_cilindro sujeta_repos_1;
_cilindro sujeta_repos_2;
};



//************************************************************************
// CLASE PARED VENTANA
//************************************************************************
class _pared_ventana: public _triangulos3D
{
public:
       
       _pared_ventana();
       void draw(_modo modo, float r, float g, float b, float grosor);

protected:
_cubo tabiqueIT;
_cubo panelIS;
_cubo panelII;
_cubo panelIC;
};

//************************************************************************
// CLASE EJE RUEDAS
//************************************************************************
class _eje_ruedas: public _triangulos3D
{
public:
       _eje_ruedas();
       void draw(_modo modo, float r, float g, float b, float grosor);

float angulo_ruedas;


protected:
_rueda rueda1;
_rueda rueda2;
_cilindro eje;
};

//************************************************************************
// CLASE PLATAFORMA
//************************************************************************
class _plataforma: public _triangulos3D
{
public:

       _plataforma();
       void draw(_modo modo, float r, float g, float b, float grosor);

float posicion_asiento;
float posicion_asiento_max;
float posicion_asiento_min;


protected:
_eje_ruedas eje_delantero;
_eje_ruedas eje_trasero;
_cubo base;
_asiento asientoIzda;
_asiento asientoDcha;
};


//************************************************************************
// CLASE CHASIS
//************************************************************************
class _coche: public _triangulos3D
{
public:

       _coche();
       void draw(_modo modo, float r, float g, float b, float grosor);
       void seleccion(); //metodo para la seleccion

float angulo_puertas;
float angulo_puertas_max;
_plataforma plataforma;

//atributos para movimiento
float tam_luz;
float tam_luz_max;
float tam_luz_min;

float mov_techo_z;
float mov_techo_z_max;
float mov_techo_z_min;

float mov_techo_y;
float mov_techo_y_max;
float mov_techo_y_min;


//atributos para la seleccion
_vertex3f color_pick;
vector<_vertex3i> color_select;
vector<int> activo;
int piezas;
int grosor_select;



protected:
_cubo motor;
_pared_ventana paredI;
_pared_ventana paredD;
_puerta puertaI;
_puerta puertaD;
_cubo tabiqueDD;
_cubo tabiqueID;
_cubo maletero;
_cubo techo;
_cubo matricula;
_cilindro luzI;
_cilindro luzD;
};



//************************************************************************
// CLASE COCHE
//************************************************************************
/*class _coche:public _triangulos3D
{
public:
       _coche();
       void draw(_modo modo, float r, float g, float b, float grosor);

float angulo_ruedas;
float angulo_puertas;
float movimiento_asientos;
float escalado_luces;

protected:
_chasis chasis;
_cubo matricula;
_cilindro luzI;
_cilindro luzD;
};*/
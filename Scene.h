#ifndef __Escena
#define __Escena
#include <chrono>
#include <gl\GLU.h>
#include <gl\GL.h>
#include "SkyDome.h"
#include "Terrain.h"
#include "Model.h"
#include "Water.h"
#include "Billboard.h"
#include "Fog.h"
#include "Camera.h"
#include "Colision.h"
#include "Animacion.h"
#include<cmath>
#include "enemigo.h"
#include "Arma.h"
#include <cstdlib>
#include <vector>
#include <string>



#define BILLSIZE 50

//BIENVENIDO AL ARCHIVO MAS IMPORTANTE DE TU PROYECTO

class Scene : public Camera
{
private:
	int currentTextureIndex = 0; // Índice de la textura actual
	std::chrono::time_point<std::chrono::system_clock> lastTextureChange;
	EDXFramework:: Arma* weapon;
	//string nombre;
	//int fuerza;
	//int vida;
	//int dano;
	//int peso;
	void generarCoordenadasAleatorias(double& x, double& y, double& z, double minX, double maxX, double minY, double maxY, double minZ, double maxZ)
	{
		// Obtener el tiempo actual como semilla para la función rand()
		srand(time(nullptr));

		// Generar coordenadas aleatorias dentro del rango especificado
		x = minX + static_cast<double>(rand()) / (RAND_MAX / (maxX - minX));
		y = minY + static_cast<double>(rand()) / (RAND_MAX / (maxY - minY));
		z = minZ + static_cast<double>(rand()) / (RAND_MAX / (maxZ - minZ));
	}
	// std::vector<Billboard*> billboards; // Vector para almacenar los billboards
	//int currentImageIndex; // Índice de la imagen actual

public:

	HWND hWnd = 0;

	short int skyIndex, lightIndex;
	float skyRotation;
	bool up = false;
	int animationTimer = 0;
	int Windex = 0;
	int NoobIndex=0;
	int Paindex=0;
	int mindex=0;
	int lumaindex = 0; 
	int medindex = 0;
	int wwindex = 0;
	SkyDome* skyDome = new SkyDome(hWnd, 32, 32, 500, L"Imagenes//nocheskydome2.jpg");
	Terrain* terrain;
	Water* lago;
	GLfloat AmbMat[4] = { 255, 255, 220, 1 };
	//Scene(std::string nombre, int vida, int fuerza, EDXFramework::Arma* arma)
	//	: vida(vida), weapon(arma) {
	//	this->nombre = nombre;
	//	this->fuerza = fuerza;
	//	this->peso = this->weapon->getpeso();
	//	this->dano = this->weapon->getdano() + this->fuerza;
	//}

	//// Métodos de acceso para los atributos
	//std::string getName() { return this->nombre; }
	//int getDaño() { return this->dano; }
	//int getPeso() { return this->peso; }
	//int getVida() { return this->vida; }
	//int getFuerza() { return this->fuerza; }
	//EDXFramework::Arma* getWeapon() { return this->weapon; }

	//// Métodos para establecer los atributos
	//
	//void setNombre(std::string _Name) { nombre = _Name; }
	//void setWeapon(EDXFramework::Arma* _Weapon) {
	//	this->weapon = _Weapon;
	//	setDaño();
	//	setPeso();
	//}
	//void setFuerza(int _fuerza) {
	//	this->fuerza += _fuerza;
	//	setDaño();
	//}
	//void setDaño() {
	//	this->dano = this->weapon->getdano() + this->fuerza;
	//}
	//void setPeso() {
	//	peso = this->weapon->getpeso();
	//}
	//void setVida(int _vida) {
	//	vida = _vida;
	//}

	//Modelos "estaticos"
	EDXFramework::Model* casita;// se esparcirá en todo el espacio
	EDXFramework::Model* casita1;
	EDXFramework::Model* casita2;
	EDXFramework::Model* casita3;
	EDXFramework::Model* casita4;
	EDXFramework::Model* casita5;
	EDXFramework::Model* casita6;
	EDXFramework::Model* casita7;
	EDXFramework::Model* casita8;

	EDXFramework::Model* arbolpelon;
	EDXFramework::Model* arbolpelon1;
	EDXFramework::Model* arbolpelon2;
	EDXFramework::Model* arbolpelon3;
	EDXFramework::Model* arbolpelon4;
	EDXFramework::Model* arbolpelon5;

	EDXFramework::Model* hongos;
	EDXFramework::Model* hongos2;
	EDXFramework::Model* hongos3;
	EDXFramework::Model* hongos4;
	EDXFramework::Model* hongos5;

	//Modelos que se van a mover
	EDXFramework::Model* PC;

/*	EDXFramework::Model* nube;*/// se esparcirá en el espacio
	EDXFramework::Animacion* nube;
	EDXFramework::Animacion* nube2;
	EDXFramework::Animacion* nube3;
	EDXFramework::Animacion* nube4;
	EDXFramework::Animacion* nube5;
	EDXFramework::Animacion* nube6;
	EDXFramework::Animacion* nube7;
	EDXFramework::Animacion* nube8;
	EDXFramework::Animacion* fantasma;
//enemigo 
	EDXFramework::Animacion * corage;
	EDXFramework::Animacion* purpleguy;//benevolente
	EDXFramework::Animacion* DOOR;
	EDXFramework::Arma* espada;
	EDXFramework::Arma* martillo;
	EDXFramework::Arma* mano;
	/*EDXFramework::Model* lampara;*/
	EDXFramework::Model* lampara2;
	EDXFramework::Model* shrek;
	EDXFramework::Animacion* globo;
	EDXFramework::Animacion* globo2;
	EDXFramework::Animacion* globo3; 
	EDXFramework::Animacion * globo4;
	EDXFramework::Animacion* globo5; 
	EDXFramework::Animacion* globo6; 
	EDXFramework::Animacion* globo7; 
	EDXFramework::Animacion* globo8; 

	//modelos que se van a mover 
	EDXFramework::enemigo* PUPPET[9];
	EDXFramework::enemigo* noob[12];
	EDXFramework::Model* LUMA[15];
	EDXFramework::Model* patricio[9];
	EDXFramework::enemigo* monster[7];
	EDXFramework::Model* alien[11];
	EDXFramework::Model* medusa[29];

//Construcción
	EDXFramework::Model* frente_ext;
	EDXFramework::Model* dercha_ext;
	EDXFramework::Model* izq_ext;
	EDXFramework::Model* atras_ext; 
	EDXFramework::Model* arriba_frente_ext;
	EDXFramework::Model* arriba_derecha_ext;
	EDXFramework::Model* arriba_izq_ext;
	EDXFramework::Model* arriba_atras_ext;
	EDXFramework::Model* frente_izq_int;
	EDXFramework::Model* frente_dere_int;
	EDXFramework::Model* izq_izq_int;
	EDXFramework::Model* izq_dere_int;
	EDXFramework::Model* dere_dere_int;
	EDXFramework::Model* atras_dere_int;
	EDXFramework::Model* atras_izq_int;
	EDXFramework::Model* dere_izq_int;
	EDXFramework::Model* arriba_Atras_int;
	EDXFramework::Model* arriba_frente_int;
	EDXFramework::Model* arriba_izq_int;
	EDXFramework::Model* arriba_dere_int;
	EDXFramework::Model* piso_abajo;
	EDXFramework::Model* piso_arriba;
	EDXFramework::Model* piso_azotea;
	EDXFramework::Model* azotea_frente;
	EDXFramework::Model* techo1;
	EDXFramework::Model* techo2;
	EDXFramework::Model* escalera;
	Colision* pared_atraas;
	Colision* pared_atravesada;
	Colision* pared_izq;
	Colision* pared_Frente1;
	Colision* pared_Frente2;
	Colision* pared_Der;
	Colision* pared_atra;
	Colision* pared_ea;
	Colision* pared_ea2;
	Colision* pared_da;
	Colision* pared_ia;
	Colision* pared_aa;
	Colision* subir;
	Colision* bajar;
	Colision* bajar2;
	Colision* pg;
	Colision* pa;
	Colision* luma;
	Colision* ganar;
	Colision* aln;
	Colision* phantom;
	Colision* coward;
	Colision* ataque_noob;
	Colision* ataque_puppet;
	Colision* ataque_monster;
	Billboard* billBoard[BILLSIZE];
	


	//Scene::Scene(HWND hWnd) : weapon(new EDXFramework::Arma()) {
	//	// Inicialización de otros atributos de la escena...

	//	this->hWnd = hWnd;

	//	// Crear el objeto de arma sin argumentos
	//	this->weapon = new EDXFramework::Arma();

	//	// Otros inicializaciones si las hay...
	//}

	Scene(HWND hWnd)
	{
		this->hWnd = hWnd;
		skyIndex = lightIndex, skyRotation = 0;

		GLfloat AmbPos[] = { 0, 400, 400, 1 };

		glShadeModel(GL_SMOOTH);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LIGHTING);
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);
		glEnable(GL_NORMALIZE);
		glEnable(GL_LIGHT0);
		glLightfv(GL_LIGHT0, GL_POSITION, AmbPos);

		double minX = -50.0;
		double maxX = 50.0;
		double minY = 10;
		double maxY = 50.0;
		double minZ = -50.0;
		double maxZ = 50.0;

		// Generar coordenadas aleatorias dentro del rango
		double randomX, randomY, randomZ;
		generarCoordenadasAleatorias(randomX, randomY, randomZ, minX, maxX, minY, maxY, minZ, maxZ);


		//lago = new Water (hWnd, L"Imagenes//Heightmap.bmp", L"Imagenes//water.jpg", 1100, 1100);
		lago = new Water(hWnd, L"Imagenes//Heightmap.bmp", L"Imagenes//water3.jpg", 200, 1100, 128, 6, 170.26);
		terrain = new Terrain(hWnd, L"Imagenes//Heightmap.bmp", L"Imagenes//pasto.jpg", L"Imagenes//pasto.jpg", 1100, 1100);
		PC = new EDXFramework::Model(0, -110, 50, 5, 5, 5, "Modelos//Laptop//laptop1.obj", "Modelos//Laptop//laptop.bmp", 1);

		nube = new EDXFramework::Animacion(845, 245, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube2 = new EDXFramework::Animacion(500, 397, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube3 = new EDXFramework::Animacion(-250, 754, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube4 = new EDXFramework::Animacion(-169.33, -954, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube5 = new EDXFramework::Animacion(-317.61, -500, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube6 = new EDXFramework::Animacion(346.61, -794, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube7 = new EDXFramework::Animacion(468, 792, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		nube8 = new EDXFramework::Animacion(949, 526, 950, 5, 5, 5, "Modelos//Clouds//Cloud.obj", "Modelos//Clouds//cloud.bmp", 1);
		espada = new EDXFramework::Arma(112.92, 298.57, 8, 3, 3, 3, "Modelos//espada//espada.obj", "Modelos//espada//Material_baseColor.bmp", 1,"espada",50,40,10);
		martillo = new EDXFramework::Arma(160, 287.57, 30, 3, 3, 3, "Modelos//paleta//LolipopHammer.obj", "Modelos//paleta//candy_hammer.bmp", 1,"martillo",40,20,5);
		
		/*lampara=new EDXFramework::Model(154, 291.30, 12, 3, 3, 3, "Modelos//Lamp//LAMP.obj", "Modelos//Lamp//pngout.bmp", 1);*/

		lampara2 = new EDXFramework::Model(113.92, 298.57, 15, 3, 3, 3, "Modelos//Lamp//LAMP.obj", "Modelos//Lamp//pngout.bmp", 1);
		hongos = new EDXFramework::Model(-200, -300, 8, 7, 7, 10, "Modelos//hongo_nuevo//Mushrooms1.obj", "Modelos//hongo_nuevo//color_base.bmp", 1);
		hongos2 = new EDXFramework::Model(-328.98, -272.35, 33.70, 7, 7, 10, "Modelos//hongo_nuevo//Mushrooms1.obj", "Modelos//hongo_nuevo//color_base.bmp", 1);
		hongos3 = new EDXFramework::Model(-439.77, -217.88, 57.19, 7, 7, 10, "Modelos//hongo_nuevo//Mushrooms1.obj", "Modelos//hongo_nuevo//color_base.bmp", 1);
		hongos4 = new EDXFramework::Model(-340.16, -55.92, 30.15, 7, 7, 10, "Modelos//hongo_nuevo//Mushrooms1.obj", "Modelos//hongo_nuevo//color_base.bmp", 1);
		hongos5 = new EDXFramework::Model(-319.89, 138.59, 9.74, 7, 7, 10, "Modelos//hongo_nuevo//Mushrooms1.obj", "Modelos//hongo_nuevo//color_base.bmp", 1);
		casita = new EDXFramework::Model(-60, -160, 3, 20, 20, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita1 = new EDXFramework::Model(-121.88, 13.94, 14.72, 20, 20, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita2 = new EDXFramework::Model(-50.22, 204.08, 20.94, 19, 19, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita3 = new EDXFramework::Model(-326.61, 86.14, 10.30, 19, 20, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita4 = new EDXFramework::Model(-367.21, 263.72, 28.7, 20, 20, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita5 = new EDXFramework::Model(209, -108, 73, 19, 19, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita6 = new EDXFramework::Model(422.66, -133.79, 19.72, 19, 19, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita7 = new EDXFramework::Model(431, 12.29, 4, 19, 19, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		casita8 = new EDXFramework::Model(-1.33, 363.27, 20.46, 19, 19, 20, "Modelos//Mushroom_House//casa_hongo.obj", "Modelos//Mushroom_House//gs_house_c.bmp", 1);
		arbolpelon = new EDXFramework::Model(-133, -253, 3, 4, 4, 4, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		arbolpelon1 = new EDXFramework::Model(142.72, -234.63, 5, 3, 3, 3, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		arbolpelon2 = new EDXFramework::Model(292.34, -392.57, 9, 3, 3, 3, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		arbolpelon3 = new EDXFramework::Model(377, 195.43, 3.53, 3, 3, 3, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		arbolpelon4 = new EDXFramework::Model(65.12, -1.09, 40.41, 3, 3, 3, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		arbolpelon5 = new EDXFramework::Model(205.90, -312.43, 7.11, 3, 3, 3, "Modelos//arbol_pelon//arbolpelon.obj", "Modelos//arbol_pelon//default_baseColor.bmp", 1);
		globo = new EDXFramework::Animacion(-52, -286, 20, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);

		globo2 = new EDXFramework::Animacion(-52, -286, 20, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo3 = new EDXFramework::Animacion(162, -286.27, 22.85, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo4 = new EDXFramework::Animacion(152.24, -145.05, 33, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo5 = new EDXFramework::Animacion(86.06, 119.37, 21.87, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo6 = new EDXFramework::Animacion(-45.84, 302.6, 55.8, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo7 = new EDXFramework::Animacion(-309, 151.92, 19.41, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);
		globo8 = new EDXFramework::Animacion(-220, -71.84, 82.07, 3, 3, 3, "Modelos//globo2//globoo.obj", "Modelos//globo2//color_globo.bmp", 1);

		PUPPET[0] = new EDXFramework:: enemigo(-57.61, 101.83, 10.16, 3, 3, 3, "Modelos//PUPPET//po1.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[1] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po2.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[2] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po3.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[3] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po4.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[4] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po5.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[5] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po6.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[6] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po7.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		PUPPET[7] = new EDXFramework::enemigo(-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po8.obj", "Modelos//PUPPET//color_puppet.bmp", 1 ,"puppet",100,40);
		PUPPET[8] = new EDXFramework::enemigo (-57.61, 101.83, 13.16, 3, 3, 3, "Modelos//PUPPET//po9.obj", "Modelos//PUPPET//color_puppet.bmp", 1,"puppet",100,40);
		//
		noob[0] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n1.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[1] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n2.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[2] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n3.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[3] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n5.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[4] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n7.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[5] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n8.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[6] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n9.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[7] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n10.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[8] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n12.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[9] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n13.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[10] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n14.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		noob[11] = new EDXFramework::enemigo(66, 144.314, 23.54, 3, 3, 3, "Modelos//noob//n15.obj", "Modelos//noob//n_color.bmp", 1,"noob",100,50);
		pa = new Colision(208.47, 203.33, 18, 30, 30, 30);

		patricio[0] = new EDXFramework::Model(208.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA1.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[1] = new EDXFramework::Model(208.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA2.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[2] = new EDXFramework::Model(208.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA3.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[3] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA4.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[4] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA5.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[5] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA7.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[6] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA8.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[7] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA9.obj", "Modelos//Patrick//color.bmp", 1);
		patricio[8] = new EDXFramework::Model(207.47, 203.33, 15.56, 3, 3, 3, "Modelos//Patrick//PA10.obj", "Modelos//Patrick//color.bmp", 1);
		monster[0] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m1.obj", "Modelos//mounstro//color_m.bmp", 1,"Mounstro",100,70);
		monster[1] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m2.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);
		monster[2] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m3.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);
		monster[3] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m4.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);
		monster[4] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m5.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);
		monster[5] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m6.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);
		monster[6] = new EDXFramework::enemigo(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//mounstro//m7.obj", "Modelos//mounstro//color_m.bmp", 1,"Moustro",100,70);


		LUMA[0] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l1.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[1] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l2.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[2] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l3.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[3] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l4.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[4] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l5.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[5] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l6.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[6] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l7.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[7] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l8.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[8] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l9.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[9] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l10.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[10] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l11.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[11] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l12.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[12] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l13.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[13] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l14.obj", "Modelos//luma//luma2.bmp", 1);
		LUMA[14] = new EDXFramework::Model(419.12, -40.68, 12.58, 3, 3, 3, "Modelos//luma//poses//l15.obj", "Modelos//luma//luma2.bmp", 1);
		luma = new Colision(415, -40.86, 12.58, 20, 20, 20);
		medusa[0] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME1.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[1] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME2.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[2] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME3.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[3] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME4.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[4] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME5.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[5] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME6.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[6] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME7.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[7] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME8.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[8] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME9.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[9] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME10.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[10] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME11.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[11] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME12.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[12] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME13.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[13] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME14.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[14] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME15.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[15] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME16.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[16] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME17.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[17] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME18.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[18] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME19.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[19] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME20.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[20] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME21.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[21] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME22.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[22] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME23.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[23] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME24.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[24] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME25.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[25] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME26.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[26] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME27.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[27] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME28.obj", "Modelos//medusa//Alien.bmp", 1);
		medusa[28] = new  EDXFramework::Model(-323.35, 121.76, 11.77, 3, 3, 3, "Modelos//medusa//ME29.obj", "Modelos//medusa//Alien.bmp", 1);
		aln = new Colision(-323.35, 121.76, 15, 30, 30, 30);
		corage = new EDXFramework::Animacion(-126.55, -235.80, 3, 3, 3, 3, "Modelos//Courage//Courage.obj", "Modelos//Courage//nano_courage.bmp", 1);
		coward = new Colision(-126.55, -235.80, 3, 10, 10, 10);
		fantasma = new EDXFramework::Animacion(-156.55, -235.80, 4, 3, 3, 3, "Modelos//Ghost//fantasmin.obj", "Modelos//Ghost//Tex_fantasma.bmp", 1);
		phantom = new Colision(-156.55, -235.80, 4, 20, 20, 20);
		purpleguy = new EDXFramework::Animacion(-242, -247.80, 7, 3, 3, 3, "Modelos//Purpleguy//purpleguy.obj", "Modelos//Purpleguy//purpleguy.bmp", 1);
		pg = new Colision(-217, -232, 11, 10, 10, 11);
		
		DOOR = new EDXFramework:: Animacion(-448.22, 164.61, 59, 9, 9, 9, "Modelos//Door//Door.obj", "Modelos//Door//color_puerta.bmp", 1);
		shrek = new EDXFramework::Model(randomX, randomZ, randomY, 3, 3, 3, "Modelos//shrek//shrek.obj", "Modelos//shrek//color.bmp", 1);
		//casona
		frente_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_Frente_ext.obj", "Modelos//Partes_casa//texturas//color_paredcventanas.bmp", 1);
		dercha_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_derecha_ext.obj", "Modelos//Partes_casa//texturas//color_paredcventanas.bmp", 1);
		izq_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_izq_ext.obj", "Modelos//Partes_casa//texturas//pared.bmp", 1);
		atras_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_atras_ext.obj", "Modelos//Partes_casa//texturas//color_paredcventanas.bmp", 1);
		arriba_frente_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_frente_ext.obj", "Modelos//Partes_casa//texturas//color_paredcventanas.bmp", 1);
		arriba_derecha_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_derecha_ext.obj", "Modelos//Partes_casa//texturas//pared.bmp", 1);
		arriba_izq_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_izq_ext.obj", "Modelos//Partes_casa//texturas//pared.bmp", 1);
		arriba_atras_ext = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_atras_ext.obj", "Modelos//Partes_casa//texturas//pared.bmp", 1);
		frente_izq_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_frente1_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		frente_dere_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_frente2_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		izq_izq_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_izq1_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		izq_dere_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_izq2_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		dere_dere_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_derecha2_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		atras_izq_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_atras1_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		atras_dere_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_atras2_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		dere_izq_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_derecha1_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		arriba_Atras_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_atras_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		arriba_frente_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_Frente_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		arriba_dere_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_derecha_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		arriba_izq_int = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//p_arriba_izq_int.obj", "Modelos//Partes_casa//texturas//color_int.bmp", 1);
		piso_abajo = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//piso_abajo.obj", "Modelos//Partes_casa//texturas//piso.bmp", 1);
		piso_arriba = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//piso_arriba.obj", "Modelos//Partes_casa//texturas//piso.bmp", 1);
		piso_azotea = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//piso_azotea.obj", "Modelos//Partes_casa//texturas//piso.bmp", 1);
		azotea_frente = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//azotea_frente.obj", "Modelos//Partes_casa//texturas//color_paredcventanas.bmp", 1);
		techo1 = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//tejado1.obj", "Modelos//Partes_casa//texturas//techo_color.bmp", 1);
		techo2 = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//tejado2.obj", "Modelos//Partes_casa//texturas//techo_color.bmp", 1);
		escalera = new EDXFramework::Model(128.96, 293.61, 2, 3, 3, 3, "Modelos//Partes_casa//escalera.obj", "Modelos//Partes_casa//texturas//escalera.bmp", 1);
		pared_Frente1 = new Colision(101.69, 316.16, 7, 8, 2, 2);
		pared_Frente2 = new Colision(142.25, 316.16, 7, 26, 2, 2);
		pared_atraas = new Colision(130.95, 265.73, 9, 37, 4, 2);
		pared_atravesada = new Colision(130.95, 284, 6, 2.5, 23, 2.5);
		pared_atra = new Colision(130, 316.16, 6, 2.5, 0.7, 2.5);
		pared_izq = new Colision(92, 291.9, 6, 2.8, 26, 2.58);
		pared_Der = new Colision(167.27, 290.07, 9, 2, 30, 27);
		pared_aa = new Colision(150, 267.12, 32.41, 22, 3, 7);
		pared_da = new Colision(166.97, 286.55, 32.41, 2, 30, 7);
		pared_ia = new Colision(132.33, 291.44, 32.41, 2, 30, 7);
		pared_ea = new Colision(165.36, 315.45, 32.41, 2, 2, 7);
		pared_ea2 = new Colision(142, 315.45, 32.41, 15, 2, 7);
		subir = new Colision(137.25, 303, 6, 3, 3, 3);
		bajar = new Colision(158.25, 313, 30, 3, 3, 3);
		bajar2 = new Colision(137.48, 287, 30, 2, 2, 2);
	//Areas de ataque 
		ataque_monster = new Colision(259.58, 40.70, 20, 50, 50, 50);
		ataque_noob = new Colision(-101.37, 346, 51.19, 50, 50, 50);
		ataque_puppet = new Colision(-198.51, 26.53, 40, 50, 50, 50);
		ganar = new Colision(-448.22, 164.61, 59, 15, 15, 15); 
		skyDome->setTexture(0);
		lastTextureChange = std::chrono::system_clock::now();

	

		Billboards(billBoard, hWnd);
		


		cameraInitialize();
	}

	void Billboards(Billboard* bills[], HWND hWnd)
	{
		//Aqui puedes crear algo util con un FOR quiza.
		for (int i = 0; i < BILLSIZE; ++i)
		{
			
			float posX = px;
			float posY = py+30;
			float posZ = pz;
			float ancho = 20;
			float alto = 30;

	
			bills[i] = new Billboard(hWnd, L"Imagenes//instructivo.jpg", ancho, alto, posX, posY, posZ);
		}
	}

	//void removeWeapon()
	//{
	//	// Eliminar el modelo de arma de la escena
	//	// Esto puede implicar liberar memoria, desvincular el modelo de la escena, etc.
	//	// Por ejemplo, si tu arma se almacena en un puntero como "weapon", podrías eliminarlo así:
	//	delete espada;
	//	espada = nullptr; // Opcionalmente, establece el puntero en null para evitar referencias inválidas.
	//}

	void render(HDC hDC)
	{

		skyRotation < 360 ? skyRotation += 0.1f : skyRotation = 0;
		animationTimer++;
		Windex = animationTimer % 9;

		NoobIndex = animationTimer % 12;
		//for (int i = 0; i < 12; ++i) { // Suponiendo que tienes 12 modelos en tu arreglo
		//	noob[i]->monopersiguiendote(noob[i], i, px, pz, py); // Llamar al método para cada modelo
		//}

		animationTimer += 0.03;
		Paindex = animationTimer %9;
	
		mindex = animationTimer % 7;

		animationTimer += 0.02;
		medindex = animationTimer % 29;
		lumaindex = animationTimer % 15;

		
	   //traslacion y rotacion de nube
		if (nube) {
			// Por ejemplo, traslación en el eje X con un desplazamiento de 10 unidades
			nube->animacionTraslacion_ejex(4, 400, -400);

			
			nube->animacionRotacion(nube, 0.5);
		}
		if (nube2){
			nube2->animacionTraslacion_ejex(4, 800, -800);


			nube2->animacionRotacion(nube2, 0.5);
		}
		if (nube3) {
			nube3->animacionTraslacion_ejex(4, 500, -500);


			nube3->animacionRotacion(nube3, 0.5);
		}
		if (nube4) {
			nube4->animacionTraslacion_ejex(4, 900, -500);


			nube4->animacionRotacion(nube4, 0.5);
		}
		if (nube5) {
			nube5->animacionTraslacion_ejex(4, 800, -800);


			nube5->animacionRotacion(nube5, 0.5);
		}
		if (nube6) {
			nube6->animacionTraslacion_ejex(4, 600, -600);


			nube6->animacionRotacion(nube6, 0.5);
		}
		if (nube7) {
			nube7->animacionTraslacion_ejex(4, 600, -600);


			nube7->animacionRotacion(nube7, 0.5);
		}
		if (nube8) {
			nube8->animacionTraslacion_ejex(4, 700, -700);


			nube8->animacionRotacion(nube8, 0.5);
		}

		//traslación (zig-zag) y rotacion  de globos 
		if (globo) {
			// Llama al método animacionTraslacionZigzag2
			globo->animacionTraslacionZigzag(0.05, 0.04, -30, -60, -200, -300);
			globo->animacionRotacion(globo, 15);

		}
		if (globo2) {
			globo2->animacionTraslacionZigzag(0.05, 0.04, -10, -60, -200, -300);
			globo2->animacionRotacion(globo2, 20);
		}
		if (globo3) {
			globo3->animacionTraslacionZigzag(0.05, 0.04, 180, 160, -200, -300);
			globo3->animacionRotacion(globo3, 20);
		}
		if (globo4) {
			globo4->animacionTraslacionZigzag(0.05, 0.04, 182, 160, -145, -300);
			globo4->animacionRotacion(globo4, 20);
		}
		if (globo5) {
			globo5->animacionTraslacionZigzag(0.05, 0.04, 100, 86, 134,119);
			globo5->animacionRotacion(globo5, 20);
		}
		if (globo6) {
			globo6->animacionTraslacionZigzag(0.05, 0.04, -40, -60, 200, 302);
			globo6->animacionRotacion(globo6, 20);
		}
		if (globo7) {
			globo7->animacionTraslacionZigzag(0.05, 0.04,-60, -309, 200, 151);
			globo7->animacionRotacion(globo7, 20);
		}
		if (globo8) {
			globo8->animacionTraslacionZigzag(0.05, 0.04, -60, -220, 100, 71);
			globo8->animacionRotacion(globo8, 20);
		}
	//Animaciones de objetos
		if (espada) {
		
			espada->animacionRotacion(espada, 0.3);

		
		}
		if (martillo) {
			martillo->animacionRotacion(martillo, 1);
		}
		if (fantasma) {
		fantasma->animacionTraslacion_ejex(0.2, -146, -156);
		 fantasma->animacionTraslacion_ejey(0.2, 10, 6);
		 fantasma->animacionRotacion(fantasma, 0.3);
		}
		if (corage) {
	 		 corage->subebaja(0.2,0.4,-120,-130,10,4);
		
			
		 }
		if (purpleguy) {
		
				purpleguy->animacionCuadrado(purpleguy, 1.0, -242, -230, -250, -230);
				purpleguy->animacionRotacion(purpleguy, 1.5);
	
		}
		if (DOOR) {
			DOOR->animacionTraslacionZigzag2(0.2, 0.2, 65, 59, 170, 164);
			DOOR->animacionRotacion(DOOR, 0.3);
		}

		//colisiones nubes
		if (nube->Hitbox(px, pz, py) == true) {
			px = Xante;
			py = Yante;
			pz = Zante;
		}
		if (nube2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube3->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube4->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube5->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube6->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube7->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (nube8->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}

		//casitas colisiones
		if (casita->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita1->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita3->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita4->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (casita5->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita6->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita7->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (casita8->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}

		if (fantasma->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
				}
		if(phantom->Hitbox(px,pz,py)==true){}
		if (purpleguy->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pg->Hitbox(px,pz,py==true)){}
		
		if (DOOR->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		//Globo colisiones
		if (globo->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo3->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo4->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo5->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo6->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo7->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		if (globo8->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}

		//arbol pelon
		if (arbolpelon->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (arbolpelon1->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (arbolpelon2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (arbolpelon3->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;

		}
		if (arbolpelon4->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (arbolpelon5->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		//hongo colisiones
		if (hongos->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (hongos2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (hongos3->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (hongos4->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (hongos5->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}

		if (PUPPET[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (noob[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (corage->Hitbox(px,pz,py)==true){
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if(coward->Hitbox(px,pz,py)==true){}
		if (patricio[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if(pa->Hitbox(px,pz,py)==true){}
		if (monster[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
	   }
		if (LUMA[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (luma->Hitbox(px, pz, py) == true) {}
		if (medusa[0]->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if(aln->Hitbox(px, pz, py) == true) {}
		if (espada->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (shrek->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		//paredes
		if (pared_Frente1->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			//HACER CONDICÍÓN DE TECLA V MANDAR px=xante; pz=zante;py=yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_Frente2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_atraas->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_izq->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_Der->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_atravesada->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_aa->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_ia->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_da->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_ea->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (pared_ea2->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
			px = xante;
			pz = zante;
			py = yante;
		}
		if (subir->Hitbox(px, pz, py) == true) {
			up= true;
			px = 136;
			pz = 271;
		}
	

		if (bajar->Hitbox(px, pz, py) == true) {
			up = false;
			px = 156;
			pz = 326.92;
			py = 6;
		}
		if (bajar2->Hitbox(px, pz, py) == true) {
			up = false;
			px = 142.8;
			pz = 300.16;
			py = 6;
		}
		if (martillo->Hitbox(px, pz, py) == true) {
			px = Xante;
			pz = Zante;
			py = Yante;
		}
		////Areas de ataque 
		if (ataque_monster->Hitbox(px, pz, py) == true) {
			 for (int i = 0; i < 7; ++i) {
				monster[i]->monopersiguiendote(monster[i], i, px, pz, py,1); // Llamar al método para cada modelo
			}
		}
		if (ataque_noob->Hitbox(px, pz, py) == true) {
			for (int i = 0; i < 12; ++i) {
				noob[i]->monopersiguiendote(noob[i], i, px, pz, py,0.3);
			}
		}
		if(ataque_puppet->Hitbox(px,pz,py)==true){
			for (int i = 0; i < 9; ++i) {
				PUPPET[i]->monopersiguiendote(PUPPET[i], i, px, pz, py,1.5);
			}
		}

		
		auto currentTime = std::chrono::system_clock::now();
		// Calcular el tiempo transcurrido desde el último cambio de textura
		std::chrono::duration<double> elapsedTime = currentTime - lastTextureChange;

		// hace que pase 30 segundos paar que cambie el cielo 
		if (elapsedTime.count() >= 30.0) {
			// Cambia a la siguiente textura
			currentTextureIndex = (currentTextureIndex + 1) % 2; // Alternar entre 0 y 1
			skyDome->setTexture(currentTextureIndex);

			// Reinicia el temporizador
			lastTextureChange = currentTime;
		}
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, AmbMat);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 0);
		glLoadIdentity();

		GLfloat AmbInt[] = { 0.1, 0.1, 0.1, 1 };
		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbInt);
	
		if (up == true) {
			py = terrain->Superficie(px, pz) * 4 + 30;
		}
		else {
			py = terrain->Superficie(px, pz) * 4 + 6;
		}
		cameraUpdate();

		//Skydome
		glPushMatrix();
		glTranslatef(0, 8, 0);
		glRotatef(skyRotation, 0, 1, 0);
		skyDome->Draw();
		glPopMatrix();

		//Terreno
		glPushMatrix();
		glScalef(1, 4, 1);
		terrain->Draw();
		glPopMatrix();
		//lago
		glPushMatrix();
		glScalef(0.8, 4, 0.66);
		glTranslatef(420.92,0,61.55);
		lago->Draw();
		glPopMatrix();
		//martillo
		glPushMatrix();
		glTranslatef(martillo->getCX(), martillo->getCy(), martillo->getCz());
		glRotatef(martillo->getangle(), 0, 1, 0);
		martillo->Draw();
		glPopMatrix();
	 //lampara
	
		glPushMatrix();
		glTranslatef(lampara2->getCX(), lampara2->getCy(), lampara2->getCz());
		lampara2->Draw();
		glPopMatrix();
		//Espada
	
        glPushMatrix();
		glTranslatef(espada->getCX(), espada->getCy(), espada->getCz());
		glRotatef(espada->getangle(), 1, 0, 0);
		glScalef(2,2,2);
	    espada->Draw();
		glPopMatrix();

		//NUBE
		glPushMatrix();
		glTranslatef(nube->getCX(), nube->getCy(), nube->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		//NUBE2
		glPushMatrix();
		glTranslatef(nube2->getCX(), nube2->getCy(), nube2->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////NUBE3
		glPushMatrix();
		glTranslatef(nube3->getCX(), nube3->getCy(), nube3->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////NUBE4
		glPushMatrix();
		glTranslatef(nube4->getCX(), nube4->getCy(), nube4->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////NUBE5
		glPushMatrix();
		glTranslatef(nube5->getCX(), nube5->getCy(), nube5->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////NUBE6
		glPushMatrix();
		glTranslatef(nube6->getCX(), nube6->getCy(), nube6->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////NUBE7
		glPushMatrix();
		glTranslatef(nube7->getCX(), nube7->getCy(), nube7->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();
		////NUBE8
		glPushMatrix();
		glTranslatef(nube8->getCX(), nube8->getCy(), nube8->getCz());
		glRotatef(nube->getangle(), 0, 1, 0);
		nube->Draw();
		glPopMatrix();

		////Casita
		glPushMatrix();
		glTranslatef(casita->getCX(), casita->getCy(), casita->getCz());
		casita->Draw();
		glPopMatrix();


		//Casita1
		glPushMatrix();
		glTranslatef(casita1->getCX(), casita1->getCy(), casita1->getCz());
		casita->Draw();
		glPopMatrix();

		//Casita2
		glPushMatrix();
		glTranslatef(casita2->getCX(), casita2->getCy(), casita2->getCz());
		casita->Draw();
		glPopMatrix();

		//casita 3
		glPushMatrix();
		glTranslatef(casita3->getCX(), casita3->getCy(), casita3->getCz());
		casita->Draw();
		glPopMatrix();

		//CASITA4
		glPushMatrix();
		glTranslatef(casita4->getCX(), casita4->getCy(), casita4->getCz());
		casita->Draw();
		glPopMatrix();

		//casita5
		glPushMatrix();
		glTranslatef(casita5->getCX(), casita5->getCy(), casita5->getCz());
		casita->Draw();
		glPopMatrix();

		//casa6
		glPushMatrix();
		glTranslatef(casita6->getCX(), casita6->getCy(), casita6->getCz());
		casita->Draw();
		glPopMatrix();

		//casita7
		glPushMatrix();
		glTranslatef(casita7->getCX(), casita7->getCy(), casita7->getCz());
		casita->Draw();
		glPopMatrix();
		//casita8
		glPushMatrix();
		glTranslatef(casita8->getCX(), casita8->getCy(), casita8->getCz());
		casita->Draw();
		glPopMatrix();

		//arbol pelon
		glPushMatrix();
		glTranslatef(arbolpelon->getCX(), arbolpelon->getCy(), arbolpelon->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arbolpelon1->getCX(), arbolpelon1->getCy(), arbolpelon1->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arbolpelon2->getCX(), arbolpelon2->getCy(), arbolpelon2->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arbolpelon3->getCX(), arbolpelon3->getCy(), arbolpelon3->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arbolpelon4->getCX(), arbolpelon4->getCy(), arbolpelon4->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arbolpelon5->getCX(), arbolpelon5->getCy(), arbolpelon5->getCz());
		arbolpelon->Draw();
		glPopMatrix();

		//hongo 
		glPushMatrix();
		glTranslatef(hongos->getCX(), hongos->getCy(), hongos->getCz());
		hongos->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(hongos2->getCX(), hongos2->getCy(), hongos2->getCz());
		hongos->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(hongos3->getCX(), hongos3->getCy(), hongos3->getCz());
		hongos->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(hongos4->getCX(), hongos4->getCy(), hongos4->getCz());
		hongos->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(hongos5->getCX(), hongos5->getCy(), hongos5->getCz());
		hongos->Draw();
		glPopMatrix();

		//GloBO

		glPushMatrix();
		glTranslatef(globo->getCX(), globo->getCy(), globo->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo2->getCX(), globo2->getCy(), globo2->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo3->getCX(), globo3->getCy(), globo3->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo4->getCX(), globo4->getCy(), globo4->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo5->getCX(), globo5->getCy(), globo5->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo6->getCX(), globo6->getCy(), globo6->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo7->getCX(), globo7->getCy(), globo7->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(globo8->getCX(), globo8->getCy(), globo8->getCz());
		glRotatef(globo->getangle(), 0, 1, 0);
		globo->Draw();
		glPopMatrix();

		//puppet
		glPushMatrix();
		glTranslatef(PUPPET[Windex]->getCX(),PUPPET[Windex]->getCy(), PUPPET[Windex]->getCz());
		PUPPET[Windex]->Draw();
		glPopMatrix();
		//corage
		glPushMatrix();
		glTranslatef(corage->getCX(), corage->getCy(), corage->getCz());
		corage->Draw();
		glPopMatrix();

	
	 //fantasma
		glPushMatrix();
		glTranslatef(fantasma->getCX(), fantasma->getCy(), fantasma->getCz());
		glRotatef(fantasma->getangle(),0, 1, 0);
		fantasma->Draw();
		glPopMatrix();

		//moradp
		glPushMatrix();
		glTranslatef(purpleguy->getCX(), purpleguy->getCy(), purpleguy->getCz());
		glRotatef(purpleguy->getangle(), 0, 1, 0);
		purpleguy->Draw();
		glPopMatrix();

		//DOOR
		glPushMatrix();
		glTranslatef(DOOR->getCX(), DOOR->getCy(),DOOR->getCz());
		glRotatef(DOOR->getangle(), 0, 1, 0);
		DOOR->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(noob[NoobIndex]->getCX(),noob[NoobIndex]->getCy(), noob[NoobIndex]->getCz());
		noob[NoobIndex]->Draw();
		glPopMatrix();
		
		glPushMatrix();
		glTranslatef(patricio[Paindex]->getCX(), patricio[Paindex]->getCy(), patricio[Paindex]->getCz());
	   patricio[Paindex]->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(monster[mindex]->getCX(), monster[mindex]->getCy(), monster[mindex]->getCz());
		monster[mindex]->Draw();
		glPopMatrix();
	
		glPushMatrix();
		glTranslatef(LUMA[lumaindex]->getCX(), LUMA[lumaindex]->getCy(), LUMA[lumaindex]->getCz());
		LUMA[lumaindex]->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(medusa[medindex]->getCX(), medusa[medindex]->getCy(), medusa[medindex]->getCz());
		medusa[medindex]->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(shrek->getCX(), shrek->getCy(), shrek->getCz());
		shrek->Draw();
		glPopMatrix();


		//casa
		glPushMatrix();
		glTranslatef(frente_ext->getCX(), frente_ext->getCy(), frente_ext->getCz());
		frente_ext->Draw();
		glPopMatrix();
	

		glPushMatrix();
		glTranslatef(dercha_ext->getCX(), dercha_ext->getCy(), dercha_ext->getCz());
		dercha_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(izq_ext->getCX(),izq_ext->getCy(),izq_ext->getCz());
		izq_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(atras_ext->getCX(), atras_ext->getCy(),atras_ext->getCz());
		atras_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(atras_ext->getCX(), atras_ext->getCy(), atras_ext->getCz());
		atras_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_frente_ext->getCX(), arriba_frente_ext->getCy(),arriba_frente_ext->getCz());
		arriba_frente_ext->Draw();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(arriba_derecha_ext->getCX(), arriba_derecha_ext->getCy(), arriba_derecha_ext->getCz());
		arriba_derecha_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_izq_ext->getCX(), arriba_izq_ext->getCy(), arriba_izq_ext->getCz());
		arriba_izq_ext->Draw();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(arriba_atras_ext->getCX(), arriba_atras_ext->getCy(), arriba_atras_ext->getCz());
		arriba_atras_ext->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(frente_izq_int->getCX(), frente_izq_int->getCy(), frente_izq_int->getCz());
		frente_izq_int->Draw();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(frente_dere_int->getCX(), frente_dere_int->getCy(), frente_dere_int->getCz());
		frente_dere_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(izq_izq_int->getCX(), izq_izq_int->getCy(), izq_izq_int->getCz());
		izq_izq_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(dere_dere_int->getCX(), dere_dere_int->getCy(), dere_dere_int->getCz());
		dere_dere_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(izq_dere_int->getCX(), izq_dere_int->getCy(), izq_dere_int->getCz());
		izq_dere_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(atras_dere_int->getCX(), izq_dere_int->getCy(), izq_dere_int->getCz());
		atras_dere_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(atras_izq_int->getCX(), atras_izq_int->getCy(), atras_izq_int->getCz());
		atras_izq_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(dere_izq_int->getCX(), dere_izq_int->getCy(), dere_izq_int->getCz());
		dere_izq_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_izq_int->getCX(), arriba_izq_int->getCy(), arriba_izq_int->getCz());
		arriba_izq_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_dere_int->getCX(), arriba_dere_int->getCy(), arriba_dere_int->getCz());
		arriba_dere_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_frente_int->getCX(), arriba_frente_int->getCy(), arriba_frente_int->getCz());
		arriba_frente_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(arriba_Atras_int->getCX(), arriba_Atras_int->getCy(), arriba_Atras_int->getCz());
		arriba_Atras_int->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(piso_abajo->getCX(), piso_abajo->getCy(), piso_abajo->getCz());
		piso_abajo->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(piso_arriba->getCX(), piso_arriba->getCy(),piso_arriba->getCz());
		piso_arriba->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(piso_azotea->getCX(), piso_azotea->getCy(), piso_azotea->getCz());
		piso_azotea->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(techo1->getCX(),techo1->getCy(),techo1->getCz());
		techo1->Draw();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(techo2->getCX(), techo2->getCy(), techo2->getCz());
		techo2->Draw();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(azotea_frente->getCX(),azotea_frente->getCy(),azotea_frente->getCz());
		azotea_frente->Draw();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(escalera->getCX(), escalera->getCy(),escalera->getCz());
		escalera->Draw();
		glPopMatrix();
	
		for (int i = 0; i < BILLSIZE; i++) {

			if (billBoard[i] != nullptr) // Verifica si el billboard existe (no es nullptr)
			{
				billBoard[i]->Draw(px,py+30,pz);
			}
		}
		
			//Aqui puede ir algo en especial, en tu carpeta de HEADER_FILES, el primer archivo es la respuesta.
			glPopMatrix();


		SwapBuffers(hDC);
	


	}

	~Scene()
	{
		//NO OLVIDES PONER AQUI TODOS TUS PUNTEROS
		delete globo;
		delete globo2;
		delete globo3;
		delete globo4;
		delete globo5;
		delete globo6;
		delete globo7;
		delete globo8;
		delete skyDome;
		delete PC;
		delete frente_ext;
		delete nube;
		delete nube2;
		delete nube3;
		delete nube4;
		delete nube5;
		delete nube6;
		delete nube7;
		delete nube8;

		delete casita;
		delete casita1;
		delete casita2;
		delete casita3;
		delete casita4;
		delete casita5;
		delete casita6;
		delete casita7;
		delete casita8;

		delete purpleguy;
		delete corage;
		delete fantasma;

		delete DOOR;
		delete arbolpelon;
		delete arbolpelon1;
		delete arbolpelon2;
		delete arbolpelon3;
		delete arbolpelon4;
		delete arbolpelon5;
		delete hongos;
		delete hongos2;
		delete hongos3;
		delete hongos4;
		delete hongos5;
		delete PUPPET[0];
		delete PUPPET[1];
		delete PUPPET[2];
		delete PUPPET[3];
		delete PUPPET[4];
		delete PUPPET[5];
		delete PUPPET[6];
		delete PUPPET[7];
		delete PUPPET[8];
		delete noob[0];
		delete noob[1];
		delete noob[2];
		delete noob[3];
		delete noob[4];
		delete noob[5];
		delete noob[6];
		delete noob[7];
		delete noob[8];
		delete noob[9];
		delete noob[10];
		delete noob[11];
		delete patricio[0];
		delete patricio[1];
		delete patricio[2];
		delete patricio[3];
		delete patricio[4];
		delete patricio[5];
		delete patricio[6];
		delete patricio[7];
		delete patricio[8];
		delete monster[0];
		delete monster[1];
		delete monster[2];
		delete monster[3];
		delete monster[4];
		delete monster[5];
		delete monster[6];
		delete LUMA[0];
		delete LUMA[1];
		delete LUMA[2];
		delete LUMA[3];
		delete LUMA[4];
		delete LUMA[5];
		delete LUMA[6];
		delete LUMA[7];
		delete LUMA[8];
		delete LUMA[9];
		delete LUMA[10];
		delete LUMA[11];
		delete LUMA[12];
		delete LUMA[13];
		delete LUMA[14];
		delete medusa[0];
		delete medusa[1];
		delete medusa[2];
		delete medusa[3];
		delete medusa[4];
		delete medusa[5];
		delete medusa[6];
		delete medusa[7];
		delete medusa[8];
		delete medusa[9];
		delete medusa[10];
		delete medusa[11];
		delete medusa[12];
		delete medusa[13];
		delete medusa[14];
		delete medusa[15];
		delete medusa[16];
		delete medusa[17];
		delete medusa[18];
		delete medusa[19];
		delete medusa[20];
		delete medusa[21];
		delete medusa[22];
		delete medusa[23];
		delete medusa[24];
		delete medusa[25];
		delete medusa[26];
		delete medusa[27];
		delete medusa[28];
		delete shrek;
		delete espada;
		delete izq_ext;
		delete dercha_ext;
		delete atras_ext;
		delete arriba_atras_ext;
		delete arriba_derecha_ext;
		delete arriba_frente_ext;
		delete arriba_izq_ext;
		delete frente_izq_int;
		delete frente_dere_int;
		delete izq_izq_int;
		delete izq_dere_int;
		delete dere_dere_int;
		delete atras_dere_int;
		delete atras_izq_int;
		delete dere_izq_int;
		delete techo1;
		delete techo2;
		delete piso_azotea;
		delete azotea_frente;
		delete escalera;
		delete pared_Frente1;
		delete pared_Frente2;
		delete pared_atraas;
		delete pared_atravesada;
		delete pared_atraas;
		delete pared_izq;
		delete pared_Der;
		delete martillo;
		/*delete lampara;*/
		delete lampara2;
		delete subir;
		delete ataque_monster;
		delete ataque_noob;
		delete ataque_puppet;
		delete bajar;
		delete weapon;
	/*	for (auto billboard : billboards) {
			delete billboard;
		}
	*/
	}

};
#endif
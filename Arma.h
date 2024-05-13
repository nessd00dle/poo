#pragma once
#include <chrono>
#include "Model.h"
#include "Animacion.h"

using namespace std;
namespace EDXFramework {
	class Arma:public virtual  Model,public Animacion  {
	private:
		string nombre_arma;
		int vida;
		int dano;
		int peso;
	public:
		Arma();
		Arma (double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool model, string _nombre, int _vida, int _dano,int _peso);
	     Arma(double _cx, double _cz, double _cy, string _nombre, int _vida, int _dano, int _peso)
			: Model(0, 0, 0, 0, 0, 0, "", "", 0), Animacion(0, 0, 0, 0, 0, 0, "", "", 0), Colision(_cx, _cz, _cy, 0.0, 0.0, 0.0), nombre_arma(_nombre), vida(_vida), dano(_dano), peso(_peso) {}
	    string getnombre() { return nombre_arma; }
		int getvida() { return vida; }
		int getdano() { return dano; }
		int getpeso() { return peso; }

		void setnombre(string _name) { nombre_arma = _name; }
		void setdano(int _Dano) { dano = _Dano; }
		void setvida(int _vida) { vida = _vida; }
		void setpeso(int _peso) { peso = _peso; }
		
	};
}
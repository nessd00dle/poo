#pragma once
#include <string>
#include "Model.h"
#include "Animacion.h"
#include "Colision.h"
namespace EDXFramework {
    class enemigo :public virtual Colision, public virtual Model, public Animacion {
    private:
        string nombre;
        int vida;
        int dano;

    public:
        enemigo(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool model);
        enemigo(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool model, string _nombre, int _vida, int _dano);
        string getnombre() { return nombre; }
        int getvida() { return vida; }
        int getdano() { return dano; }
        void setnombre(string _nombre) { nombre = _nombre; }
        void setvida(int _vida) { vida = _vida; }
        void setdano(int _dano) { dano = _dano; }

        void atacar(int, int);
        void morir(int _vida);
  

    };
}


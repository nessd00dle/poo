#include "Arma.h"
#include "Model.h"
#include "Animacion.h"
//Arma::Arma
using namespace EDXFramework;
namespace EDXFramework {

    Arma::Arma() : Colision(0.0, 0.0, 0.0, 0.0, 0.0, 0.0), Model(0,0,0,0,0,0,"","",0), Animacion(0, 0, 0, 0, 0, 0, "", "", 0), nombre_arma("mano"), vida(100), dano(20), peso(0) {}

    Arma::Arma(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool model, string _nombre, int _vida, int _dano, int _peso)
        : Model(_cx, _cz, _cy, _crx, _crz, _cry, modelPath, texturePath, model), Animacion(_cx, _cz, _cy, _crx, _crz, _cry, modelPath, texturePath, model), Colision(_cx, _cz, _cy, _crx, _crz, _cry), nombre_arma(_nombre), vida(_vida), dano(_dano), peso(_peso) {}
    

}
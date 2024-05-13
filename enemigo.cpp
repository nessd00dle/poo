#include<iostream>
#include"enemigo.h"
#include "Model.h"
#include "Animacion.h"
#include "Colision.h"

namespace EDXFramework {
    enemigo::enemigo(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool model, string _nombre, int _vida, int _dano)
        : Model(_cx, _cz, _cy, _crx, _crz, _cry, modelPath, texturePath, model), Animacion(_cx, _cz, _cy, _crx, _crz, _cry, modelPath, texturePath, model), Colision(_cx, _cz, _cy, _crx, _crz, _cry), nombre(_nombre), vida(_vida), dano(_dano) {}

    void enemigo::atacar(int _vida, int _dano) {
        //  lógica para el ataque
    }

    void enemigo::morir(int _vida) {
        //  lógica para la muerte
    }

}

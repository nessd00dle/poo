#include<iostream>
#include "Animacion.h"
#include <cmath>
#include <thread>
#include <chrono>
using namespace EDXFramework;
namespace EDXFramework {


    Animacion::Animacion(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool mode)
        : Model(_cx, _cz, _cy, _crx, _crz, _cry, modelPath, texturePath, mode), Colision(_cx, _cz, _cy, _crx, _crz, _cry) {
       
    }
    
    void Animacion::animacionTraslacion_ejex(double traslacion, double limiteSuperior, double limiteInferior) {
        if (state == 0) {
            setcx(getCX() + traslacion);
            if (getCX() >= limiteSuperior) {
                setstate(1);
            }
        }
        else if (state == 1) {
            setcx(getCX() - traslacion);
            if (getCX() <= limiteInferior) {
                setstate(2);
            }
        }
        else if (state == 2) {
            setcx(getCX() + traslacion);
            if (getCX() >= limiteSuperior) {
                setstate(0);
            }
        }
    }
    void Animacion::animacionTraslacion_ejey(double traslacion, double limiteSuperior, double limiteInferior) {
        if (state == 0) {
            setcy(getCy() + traslacion);
            if (getCy() >= limiteSuperior) {
                setstate(1);
            }
        }
        else if (state == 1) {
            setcy(getCy() - traslacion);
            if (getCy() <= limiteInferior) {
                setstate(2);
            }
        }
        else if (state == 2) {
            setcy(getCy() + traslacion);
            if (getCy() >= limiteSuperior) {
                setstate(0);
            }
        }
    }
    void Animacion::animacionTraslacionZigzag(double traslacionX, double traslacionZ, double limiteSuperiorX, double limiteInferiorX, double limiteSuperiorZ, double limiteInferiorZ) {
        if (state == 0) {
            // Mover hacia adelante y hacia arriba
            setcx(getCX() + traslacionX);
            setcz(getCz() + traslacionZ);
            if (getCX() >= limiteSuperiorX || getCz() >= limiteSuperiorZ) {
                setstate(1);
            }
        }
        else if (state == 1) {
            // Mover hacia atrás y hacia arriba
            setcx(getCX() - traslacionX);
            setcz(getCz() + traslacionZ);
            if (getCX() <= limiteInferiorX || getCz() >= limiteSuperiorZ) {
                setstate(2);
            }
        }
        else if (state == 2) {
            // Mover hacia adelante y hacia abajo
            setcx(getCX() + traslacionX);
            setcz(getCz() - traslacionZ);
            if (getCX() >= limiteSuperiorX || getCz() <= limiteInferiorZ) {
                setstate(0);
            }
        }
    }
    void Animacion::animacionTraslacionZigzag2(double traslacionY, double traslacionZ, double limiteSuperiorY, double limiteInferiorY, double limiteSuperiorZ, double limiteInferiorZ) {
       
        if (state == 0) {
           setcy(getCy() + traslacionY);
           setcz(getCz() + traslacionZ);

            // Verificar límites
           if (getCy() >= limiteSuperiorY || getCz() >= limiteSuperiorZ) {
               setstate(1);
            }
        }
        // Mover hacia atrás y hacia abajo
        else if (state == 1) {
           setcy(getCy() - traslacionY);
           setcz(getCz() - traslacionZ);

            // Verificar límites
           if (getCy() <= limiteInferiorY || getCz() <= limiteInferiorZ) {
               setstate(0);
           }
        }


    }
    void Animacion::animacionCuadrado(Model* modelo, double traslacion, double rangoXInicio, double rangoXFin, double rangoZInicio, double rangoZFin) {
        enum Estado { MOVIENDO_X_POSITIVO, MOVIENDO_Z_POSITIVO, MOVIENDO_X_NEGATIVO, MOVIENDO_Z_NEGATIVO };
        static Estado estado = MOVIENDO_X_POSITIVO;
        // Incremento de ángulo por paso
        double incrementoAngulo = 90.0; // Ángulo de rotación en grados
        // Obtenemos la posición actual del modelo
        double x = modelo->getCX();
        double z = modelo->getCz();
        double anguloActual = fmod(modelo->getangle(), 360.0); // Aseguramos que el ángulo esté dentro del rango de 0 a 360 grados

        switch (estado) {
         case MOVIENDO_X_POSITIVO:
             x += traslacion;
             if (x >= rangoXFin) {
                 estado = MOVIENDO_Z_POSITIVO;
                 anguloActual = 90.0;
            }
             break;
         case MOVIENDO_Z_POSITIVO:
             z += traslacion;
            if (z >= rangoZFin) {
                 estado = MOVIENDO_X_NEGATIVO;
                anguloActual = 180.0;
            }
            break;
        case MOVIENDO_X_NEGATIVO:
            x -= traslacion;
            if (x <= rangoXInicio) {
                estado = MOVIENDO_Z_NEGATIVO;
                anguloActual = 270.0;
            }
            break;
        case MOVIENDO_Z_NEGATIVO:
            z -= traslacion;
            if (z <= rangoZInicio) {
                estado = MOVIENDO_X_POSITIVO;
                anguloActual = 0.0;
            }
            break;
        }

        // Actualizamos la posición y el ángulo del modelo
        modelo->setcx(x);
        modelo->setcz(z);
        modelo->setangle(anguloActual);
    }
    void Animacion::animacionRotacion(Model* modelo, double incremento) {
        if (angle < 360) {
            angle += incremento;
        }
        else {
            angle = 0;
        }
    }
    void Animacion::monopersiguiendote(Model* modelo, int indice, double tx, double tz, double ty, double velocidad) {
        // Coordenadas de la cámara
        double px = tx;
        double pz = tz;
        double py = ty;

        // Obtener las coordenadas del NPC
        double nx = modelo->getCX();
        double nz = modelo->getCz();
        double ny = modelo->getCy();

        // Calcular la dirección hacia la que el NPC debe moverse
        double dx = px - nx;
        double dz = pz - nz;
        double dy = py - ny;

        // Calcular la distancia entre el NPC y la cámara
        double distancia = sqrt(dx * dx + dz * dz + dy * dy);

        // Normalizar la dirección
        dx /= distancia;
        dz /= distancia;
        dy /= distancia;

        // Mover el NPC en la dirección de la cámara con la velocidad deseada
        modelo->setcx(modelo->getCX() + dx * velocidad);
        modelo->setcz(modelo->getCz() + dz * velocidad);
        modelo->setcy(modelo->getCy() + dy * velocidad);
    }
    void Animacion::subebaja(double traslacionX, double traslacionY, double limiteSuperiorX, double limiteInferiorX, double limiteSuperiorY, double limiteInferiorY) {
        if (state == 0) {
            // Movimiento hacia la derecha
            setcx(getCX() + traslacionX);
            if (getCX() >= limiteSuperiorX) {
                setstate(1);
            }
        }
        else if (state == 1) {
            // Movimiento hacia la izquierda
            setcx(getCX() - traslacionX);
            if (getCX() <= limiteInferiorX) {
                setcy(getCy() + traslacionY); // Desplazar hacia abajo
                if (getCy() >= limiteSuperiorY) {
                    setstate(2);
                }
            }
        }
        else if (state == 2) {
            // Movimiento hacia la derecha
            setcx(getCX() + traslacionX);
            if (getCX() >= limiteSuperiorX) {
                setcy(getCy() - traslacionY); // Desplazar hacia arriba
                if (getCy() <= limiteInferiorY) {
                    setstate(0);
                }
            }
        }
    }
   
}
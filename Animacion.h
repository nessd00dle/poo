#pragma once
#include <chrono>
# include "Model.h"
using namespace std;
namespace EDXFramework {
	class Animacion: public virtual Model
	{
	private:
		int state = 0;
		double size = 0;
		double angle = 0;

	public:
		Animacion(double _cx, double _cz, double _cy, double _crx, double _crz, double _cry, string modelPath, string texturePath, bool mode);
		int getstate() { return state; }
		void setstate(int _state) { state = _state; }
		double getangle() { return angle; }
		void setangle(double _angle) { angle = _angle; }
		double getsize() { return size; }
		void setsize(double _size) { size = _size; }

		void animacionTraslacion_ejex(double traslacion, double limiteSuperior, double limiteInferior);
	    void animacionTraslacion_ejey(double traslacion, double limiteSuperior, double limiteInferior);
		void animacionTraslacionZigzag(double traslacionX, double traslacionZ, double limiteSuperiorX, double limiteInferiorX, double limiteSuperiorZ, double limiteInferiorZ);
		void animacionTraslacionZigzag2(double traslacionY, double traslacionZ, double limiteSuperiorY, double limiteInferiorY, double limiteSuperiorZ, double limiteInferiorZ);
		void animacionCuadrado(Model* modelo, double traslacion, double rangoXInicio, double rangoXFin, double rangoZInicio, double rangoZFin);
		void animacionRotacion(Model* modelo, double incremento);
		void monopersiguiendote(Model* modelo, int indice, double tx, double tz, double ty, double velocidad);
		void subebaja(double traslacionX, double traslacionY, double limiteSuperiorX, double limiteInferiorX, double limiteSuperiorY, double limiteInferiorY);
	};

}
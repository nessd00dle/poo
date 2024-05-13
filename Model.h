#pragma once
#include <string>
#include <cstdlib> 
#include <ctime>
#include "glm.h"
#include "BMPLoader.h"
#include"Colision.h"
using namespace std;
namespace EDXFramework {
	
class Model:public virtual Colision {
	
public:

	Model(double _cx, double _cz,double _cy, double _crx, double _crz, double _cry);
	Model(double _cx, double _cz,double _cy, double _crx, double _crz,double _cry, string modelPath, string texturePath, bool mode);
	virtual ~Model();
	void Draw();
	
	int getstate() { return state; }
	void setstate(int _state) { state = _state; }
	double getangle() { return angle; }
	void setangle(double _angle) { angle = _angle; }
	double getsize() { return size; }
	void setsize(double _size) { size = _size; }


private:
	GLMmodel* model;
	BMPClass texture;
	unsigned int textureId;
	unsigned int new_texture;
	unsigned int drawMode;
	int state= 0;
	double angle=0;
	double size;
	/*AnimacionFXF indice;*/

};

}


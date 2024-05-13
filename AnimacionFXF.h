#pragma once
#include "Model.h"
class AnimacionFXF {
private:
	int indice;
	int frame;
public:
	AnimacionFXF(int _indice, int _frame);
	~AnimacionFXF();
	int getinidice() { return indice; }
	int getframe() { return frame; }
	void setindice(int _indice) { indice = _indice; }
	void setframe(int _frame) { indice = _frame; }
};
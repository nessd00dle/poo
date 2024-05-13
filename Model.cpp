#include "Model.h"
#include <chrono>
using namespace EDXFramework;

Model::Model(double _cx, double _cz,double _cy, double _crx, double _crz,double _cry) : Colision( _cx, _cz,_cy, _crx,_crz,_cry)
{
}

Model::~Model() {
	glmDelete(model);
}

Model::Model(double _cx, double _cz,double _cy, double _crx, double _crz,double _cry,string modelPath, string texturePath, bool mode) : textureId(0),Colision(_cx, _cz,_cy, _crx, _crz,_cry) {
	if (mode == 0)
		drawMode = GLM_FLAT | GLM_MATERIAL;
	else if (mode == 1)
		drawMode = GLM_SMOOTH | GLM_MATERIAL;
	model = glmReadOBJ((char*)modelPath.c_str());
	glmFacetNormals(model);
	glmVertexNormals(model, 90.0);
	// textura1=texturePath;
	//update();
 
	//Load Texture
	BMPError e = BMPLoad(texturePath, texture);
	if (e == BMPNOERROR) {
		drawMode |= GLM_TEXTURE;
		glGenTextures(1, &textureId);
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, texture.width, texture.height, 0, GL_RGB,GL_UNSIGNED_BYTE, texture.bytes);
	}
}

void Model::Draw() {
if (drawMode & GLM_TEXTURE) {

		glBindTexture(GL_TEXTURE_2D, textureId);
	}
	glmDraw(model, drawMode);
	glBindTexture(GL_TEXTURE_2D, NULL);
}
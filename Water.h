#ifndef _wata
#define _wata
#include "Geometrias.h"
#include "Imagenes.h"
//#include "ShaderDemo.h"

class Water : public Primitivos, public Imagenes
{

private:
	float anchof;
	float proff;
	float deltax, deltaz;
	float posX;
	float posY;
	float posZ;
	//ShaderDemo *gpuDemo;

public:

	Maya wata;
	int verx, verz;
	//el nombre numerico de la textura en cuestion, por lo pronto una
	unsigned int planoTextura;

	Water(HWND hWnd, WCHAR alturas[], WCHAR textura[], float ancho, float prof,float x, float y, float z) 
		: posX(x), posY(y), posZ(z)
	//Water(HWND hWnd, WCHAR alturas[], WCHAR textura[], float ancho, float prof)
	{
		anchof = ancho;
		proff = prof;
		//cargamos la textura de la figura
		Carga(alturas);
		//en caso del puntero de la imagen sea nulo se brica esta opcion
		wata = Plano(Ancho(), Alto(), ancho, prof, Dir_Imagen(), 30);
		deltax = anchof / Ancho();
		deltaz = proff / Alto();
		verx = Ancho();
		verz = Alto();
		//disponemos la textura del gdi.
		Descarga();

		Carga(textura);
		glGenTextures(1, &planoTextura);
		glBindTexture(GL_TEXTURE_2D, planoTextura);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Ancho(), Alto(), GL_RGBA, GL_UNSIGNED_BYTE, Dir_Imagen());
		Descarga();

		//gpuDemo = new ShaderDemo("basic.vert", "basic.frag");
		//gpuDemo->ligador(gpuDemo->vertShader, gpuDemo->fragShader);
	}

	~Water()
	{
		//nos aseguramos de disponer de los recursos previamente reservados
		delete wata.maya;
		delete wata.indices;
		glDeleteTextures(1, &planoTextura);
	}

	void Draw()
	{
		static float MovS = 0;
		MovS += .0001;
		
		//glPushMatrix(); // Guarda el estado actual de la matriz de modelado

		//// Aplica la traducción para colocar el lago en la posición especificada
	 //glTranslatef(posX, posY, posZ);

		//// Código para dibujar el lago...

	 //glPopMatrix(); // Restaura el estado anterior de la matriz de modelado

		//glPushAttrib(GL_CURRENT_BIT | GL_TEXTURE_BIT);
		//glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		static float water_factor_min = 20.0f;
		static float water_factor_max = 30.0f;
		static float water_size = 200;
		water_factor_min += .001f;
		water_factor_max += .001f;
		if (water_factor_min > 60)
		{
			water_factor_min = 20.0f;
			water_factor_max = 30.0f;
		}
		glBindTexture(GL_TEXTURE_2D, planoTextura);
		glBegin(GL_QUADS);
		glTexCoord2f(water_factor_min, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(-water_size, 2.0f, water_size);

		glTexCoord2f(water_factor_max, water_factor_min);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(water_size, 2.0f, water_size);

		glTexCoord2f(water_factor_max, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(water_size, 2.0f, -water_size);

		glTexCoord2f(water_factor_min, water_factor_max);
		glColor4f(0.1f, 0.3f, 0.6f, 0.2f);
		glVertex3f(-water_size, 2.0f, -water_size);
		glEnd();
		glPopAttrib();
		//glDisable(GL_DEPTH_TEST);


	}
	float GetPosX() const {
		return posX;
	}
	float GetPosY() const {
		return posY;
	}
	float GetPosZ() const {
		return posZ;
	}
	void SetPosition(float x, float y, float z) {
		posX = x;
		posY = y;
		posZ = z;
	}
};

#endif 
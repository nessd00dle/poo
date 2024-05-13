#ifndef _Sky
#define _Sky
#include "Geometrias.h"
#include "Imagenes.h"

class SkyDome:public Primitivos, public Imagenes
{
private:

	GLuint texturas[2];
	unsigned int textureId;
public:
	Maya cuadro;
	int st, sl;
	unsigned int esferaTextura[2];	

	SkyDome(HWND hWnd, int stacks, int slices, float radio, WCHAR nombre[])
	{
		this->hWnd=hWnd;
		cuadro=Esfera(stacks, slices, radio, 0.5, 1);
		st=stacks;
		sl=slices;
		//cargamos la textura de la figura

		update();
		
	}

	~SkyDome()
	{
		//nos aseguramos de disponer de los recursos previamente reservados
		delete[] cuadro.maya;
		delete[] cuadro.indices;
		for (size_t i = 0; i < 2; i++) {
			glDeleteTextures(1, &esferaTextura[i]);
		}
		//glDeleteTextures(1, &esferaTextura);
	}

	void cargartextura(const WCHAR textura[][MAX_PATH]) {
		for (size_t i = 0; i < 2; i++)
		{
			// Convertir WCHAR a char
			char charPath[MAX_PATH];
			wcstombs(charPath, textura[i], MAX_PATH);

			// Convertir char a WCHAR
			WCHAR wideCharPath[MAX_PATH];
			MultiByteToWideChar(CP_ACP, 0, charPath, -1, wideCharPath, MAX_PATH);

			Carga(wideCharPath);
			//en caso del puntero de la imagen sea nulo se brica esta opcion
			if (Dir_Imagen())
			{
				glGenTextures(1, &esferaTextura[i]);
				glBindTexture(GL_TEXTURE_2D, esferaTextura[i]);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
				gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, Ancho(), Alto(), GL_RGBA, GL_UNSIGNED_BYTE, Dir_Imagen());
				//disponemos la textura del gdi.
				Descarga();
			}
		}
	}
	void update() {
		WCHAR texturePaths[2][MAX_PATH];

		// Rutas de las texturas
		WCHAR texturePath1[MAX_PATH] = L"Imagenes//nocheskydome2.jpg";
		WCHAR texturePath2[MAX_PATH] = L"Imagenes//skydome1.jpg";

		// Copiar las rutas a texturePaths
		wcscpy(texturePaths[0], texturePath1);
		wcscpy(texturePaths[1], texturePath2);

		// Llamar a LoadTexture pasando texturePaths como argumento
		cargartextura(texturePaths);
	}
	void setTexture(int index)
	{
		if (index >= 0 && index < 2) {
			textureId = esferaTextura[index];
		}
		else {

		}

	}

	void Draw()
	{
		int ind = 0;
		int indice;

		 glEnable(GL_CULL_FACE);
		 glCullFace(GL_BACK);
		 glDisable(GL_DEPTH_TEST);
		 glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		 glBindTexture(GL_TEXTURE_2D, textureId);
		 //habilitamos la posibilidad de guardar arreglos de procesamiento inmediato
		 glEnableClientState(GL_VERTEX_ARRAY);
		 glEnableClientState(GL_NORMAL_ARRAY);
		 glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		//asignamos punteros de vertices, normales y texturas al buffer de conexiones que sigue
		 glVertexPointer(3, GL_FLOAT, sizeof(Vertices), &cuadro.maya[0].Posx);
		 glNormalPointer(GL_FLOAT, sizeof(Vertices), &cuadro.maya[0].Normx);
		 glTexCoordPointer(2, GL_FLOAT, sizeof(Vertices), &cuadro.maya[0].u);

		//conectamos todos los vertices previamente cargados a traves de sus punteros para procesarse
		 glDrawElements(GL_TRIANGLES, (sl - 1) * (st - 1) * 6, GL_UNSIGNED_INT, cuadro.indices);
		//desocupamos la asignacion para que podamos utilizarlo con un nuevo elemento
	 	glDisableClientState(GL_VERTEX_ARRAY);
	 	glDisableClientState(GL_NORMAL_ARRAY);
	  	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	 	glDisable(GL_CULL_FACE);
	 	glEnable(GL_DEPTH_TEST);
	}
};
#endif
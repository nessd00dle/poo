#include <Windows.h>
#include "glew.h"
#include <gl\GLU.h>
#include <gl\GL.h>
#include "Scene.h"
#include <time.h>
#include "GamePadRR.h"
#include "resource.h"
#pragma comment (lib, "glew32.lib") 
#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib") 

#define Timer1 100

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
void DefPixelFormat(HDC hDC);

HWND hInfo = 0;
HWND hText = 0;
bool ableToCheck = false;
HDC hContextoVentana;
Scene *scene;
GamePadRR *gamPad;
bool renderiza = false;
unsigned int dayTimer = 0;
bool fast=false;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hwndVentana;
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX); //Tama�o en bytes de la estructura.
	wc.style = CS_HREDRAW | CS_VREDRAW; //Entero de 16 bits que codifica el estilo de la clase de ventana.
	wc.lpfnWndProc = WindowProc;//Apunta al procedimiento de ventana.
	wc.hInstance = hInstance;//Identifica la instancia de la ventana a la que esta clase pertenece.
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//Identificador del curso de la clase. Debe ser un manipulador de un recurso de tipo icono. Si es Null, la aplicaci�n mostrar� un icono cuando el usuario minice la ventana de la aplicaci�n.
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW; //Identificador del pincel para la clase.
	wc.lpszClassName = "IvanWindow"; //Especifica el nombre de la clase ventana.
	RegisterClassEx(&wc);//Registra una clase de ventana para su uso subsecuente en llamadas a las funciones CreateWindow o CreateWindowEx
	RECT wr = { 0, 0, 1080, 720 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);//Calcula el tama�o necesario del rect�ngulo de la ventana.

	//Se crea la ventana definida previamente.
	hwndVentana = CreateWindowEx(NULL,//estilo extendido de ventana
		"IvanWindow",//puntero al nombre de la clase registrada *visto arriba*
		"Onirico",//puntero al nombre de la ventana
		WS_OVERLAPPEDWINDOW,//estilo de ventana
		0,//posici�n horizontal de la ventana
		0,//posici�n vertical de la ventana
		wr.right - wr.left,//ancho de la ventana
		wr.bottom - wr.top,//alto de la ventana
		NULL,//manejador de la ventana padre o propietaria
		NULL,//manejador del menu o identificador de ventana hija
		hInstance,//manejador de la instancia de la aplicaci�n
		NULL);//puntero a los datos de creaci�n de la ventana

	ShowWindow(hwndVentana, nCmdShow);//Muestra la ventana creada

	
	ShowWindow(hInfo, SW_SHOW);
	
	glewInit();//Inicializa glew

	//Instancia de la escena
	scene = new Scene(hwndVentana);

	gamPad = new GamePadRR(1);
	ableToCheck = true;

	//Crear un timer con el valor especificado de time-out
	SetTimer(hwndVentana,//Manejador de ventana que recibir� los mensajes del timer
		Timer1,//identificador del timer
		30,//valor de time-out
		NULL);//direcci�n del procedimiento de timer

	MSG msg = { 0 };
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				break;
		}
		else
		{
			if (renderiza)
			{
				
				
				scene->render(hContextoVentana);
				renderiza = false;
				if (gamPad->IsConnected())
				{
					//PISTA: Algo puedes lograr aqui con ayuda del autocompletador
				}


			}
		}
	}

	return msg.wParam;

}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HGLRC hContextoGL;
	static HDC hContextoAux;
	int ancho, alto;
	char epx[6] = "";
	char epz[6] = "";
	char epy[6] = "";
	char edx[6] = "";
	char edz[6] = "";
	char edy[6] = "";
	char ec[80] = "";

	switch (message)
	{
	case WM_CREATE:
		hContextoAux = GetDC(hWnd);
		hContextoVentana = hContextoAux;
		DefPixelFormat(hContextoVentana);
		hContextoGL = wglCreateContext(hContextoVentana);
		wglMakeCurrent(hContextoVentana, hContextoGL);
		srand(time(NULL));
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_F1:
		{
			string info = "X: " + to_string(scene->px) + " Y: " + to_string(scene->py) + " Z: " + to_string(scene->pz);
			MessageBox(hWnd, info.c_str(), "INFO", MB_OK);
		}
		break;
		case VK_UP:
			scene->turnUp();
			renderiza = true;
			return 0;
		case VK_DOWN:
			scene->turnDown();
			renderiza = true;
			return 0;
		case VK_LEFT:
			scene->turnLeft();
			renderiza = true;
			return 0;
		case VK_RIGHT:
			scene->turnRight();
			renderiza = true;
			return 0;
		case 0x56://v
			scene->xante = scene->Xante;
			scene->zante = scene->Zante;
			scene->yante = scene->Yante;
			scene->Xante=scene->px;
			scene->Zante=scene->pz;
			scene->Yante = scene->py;
			scene->move('f');
			scene->move('f');
			renderiza = true;
			return 0;
		case 0x0D: //enter
		 // 	if (scene->espada && scene->espada->Hitbox(scene->px, scene->pz, scene->py))
			//{
			//	// Obtener las propiedades de la espada
			//	std::string nombre = scene->espada->getnombre();
			//	 int vida = scene->espada->getvida();
			// 	int fuerzaPersonaje = scene->getFuerza(); // Si la fuerza es del personaje, como mencionaste
			// 	int dano = scene->espada->getdano();
			//	int peso = scene->espada->getpeso();

			//	// Eliminar el modelo de la espada de la escena
			//	//scene->removeWeapon(); // Esta funci�n deber�a eliminar el modelo de la espada de la escena

			//	// Indicar que se renderice la escena nuevamente
			//	renderiza = true;
			//}

			
			break;
		case 0x44: //D
			scene->Xante = scene->px;
			scene->Zante = scene->pz;
			scene->Yante = scene->py;
			scene->move('r');
			renderiza = true;
			return 0;
		case 0x41: //A
			scene->Xante = scene->px;
			scene->Zante = scene->pz;
			scene->Yante = scene->py;	
			scene->move('l');
			renderiza = true;
			return 0;
		case 0x57: //W
			scene->Xante = scene->px;
			scene->Zante = scene->pz;
			scene->Yante = scene->py;
			scene->move('f');
			renderiza = true;
			return 0;
		case 0x53: //S
			scene->Xante = scene->px;
			scene->Zante = scene->pz;
			scene->Yante = scene->py;
			scene->move('b');
			renderiza = true;
			return 0;
		case 0x51: //Q
		 {

			if (scene->pg->Hitbox(scene->px, scene->pz, scene->py)) {

				MessageBox(hWnd, "quiz� encuentres algo �til en la casa", "Purpleguy:", MB_OK | MB_ICONINFORMATION);
			}
			if (scene->pa->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;

				MessageBox(hWnd, "usa la espada y el martillo para atacar", "Patricio:", MB_OK | MB_ICONINFORMATION);
			}
			if (scene->aln->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;

				MessageBox(hWnd, "Llegale en fa ", "Medusin:", MB_OK | MB_ICONINFORMATION);
			}
			if (scene->luma->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;

				MessageBox(hWnd, "Aqui espantan", "Luma:", MB_OK | MB_ICONINFORMATION);
			}
			if (scene->ganar->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;
				MessageBox(hWnd, "sobreviviste", "Adios", MB_OK | MB_ICONINFORMATION);
				PostMessage(hWnd, WM_CLOSE, 0, 0); // Cierra la ventana de la aplicaci�n
			}

			if (scene->phantom->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;

				MessageBox(hWnd, "Aguas con el agua jiji", "Fantasmin:", MB_OK | MB_ICONINFORMATION);
			}
			if(scene->coward->Hitbox(scene->px, scene->pz, scene->py)) {
				scene->px = scene->Xante;
				scene->pz = scene->Zante;
				scene->py = scene->Yante;

				MessageBox(hWnd, "Presiona la tecla (V) para correr", "Coraje:", MB_OK | MB_ICONINFORMATION);
			}
		  }
		}
	
		break;
	    break;
		break;
	case WM_KEYUP:
		switch (wParam)
		{
			case 0x56:
				fast = false;
		    
	     	break;
		
		}
		break;

	case WM_TIMER:
	{
		renderiza = true;
	}
		break;

	
	case WM_DESTROY:
	{
		KillTimer(hWnd, Timer1);
		delete scene;
		wglMakeCurrent(hContextoVentana, NULL);
		wglDeleteContext(hContextoGL);
		PostQuitMessage(0);
		return 0;
	} break;

	case WM_SIZE:
	{
		alto = HIWORD(lParam);
		ancho = LOWORD(lParam);
		if (alto == 0)
			alto = 1;
		glViewport(0, 0, ancho, alto);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45.0f, (GLfloat)ancho / (GLfloat)alto, 1.0f, 10000.0f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void DefPixelFormat(HDC hDC)
{
	int bestmatch;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR), //tama�o de la estructura
		1, //numero de version
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, //soporta la ventana, el opengl y manejara doble buffer
		PFD_TYPE_RGBA, //formato de 32 bits rgba
		32, //tama�o del color en 32 bits
		0, 0, 0, 0, 0, 0, //bits de color, no se usan
		0, //no hay buffer para el alfa
		0, //ignore el bit de corrimiento
		0, //no hay buffer de acumulacion
		0, 0, 0, 0, //no hay bits de acumulacion
		16, //tama�o del flotante para el buffer z
		0, //no hay buffers de stencil
		0, //no hay buffers auxiliares
		PFD_MAIN_PLANE, //plano principal para dibujo
		0, //reservado
		0, 0, 0 //mascaras de capas ignoradas
	};

	bestmatch = ChoosePixelFormat(hDC, &pfd);
	SetPixelFormat(hDC, bestmatch, &pfd);
}

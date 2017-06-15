//Main
#include <SDL.h>
#include "RPGSAEMMOApp.h"
#include "MainScene.h"
#include "Box2D\Box2D.h"
#define INITIALPARAMS SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_INPUT_GRABBED

#ifdef __cplusplus
extern "C"
#endif 

int main(int argc, char *argv[])
{
	//Paso numero 1, inicializar la App.
	RPGSAEMMOApp app;
	app.App(800, 800, "TEST", SDL_WINDOW_RESIZABLE, 60, new MainScene(),b2Vec2(0,-9.0f),50);
	return 0;
}

//!Main
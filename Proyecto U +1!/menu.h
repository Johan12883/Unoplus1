#pragma once
#include <Windows.h>
class menu
{
public:
	//Resolucion para imagenes. default(1280x720)
	int ancho = 1280;
	int alto = 720;

	int x = -1, y = -1;
	int seg = 0;
	int difficulty = 0;
	// Jugar, Opciones, Salir
	int btn[] = { 0,0,0 };

	int ancho_w = GetSystemMetrics(SM_CXSCREEN);
	int alto_w = GetSystemMetrics(SM_CYSCREEN);

	int initMenu(int ancho, int alto);
	int diffmenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_0, ALLEGRO_BITMAP* menu_1, ALLEGRO_BITMAP* menu_2);

};


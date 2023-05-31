#pragma once
#include <Windows.h>
#include "menu.h"
#include "Jugador.h"
#include "deck.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
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
	int btn[3] = { 0,0,0 };

	int ancho_w = GetSystemMetrics(SM_CXSCREEN);
	int alto_w = GetSystemMetrics(SM_CYSCREEN);

	menu();

	int initMenu(int ancho, int alto);
	int diffmenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_0, ALLEGRO_BITMAP* menu_1, ALLEGRO_BITMAP* menu_2);
	int game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty);
	int OpMenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, deck midcard);
};


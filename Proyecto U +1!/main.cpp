#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include "menu.h"
#include "deck.h"
#include "Jugador.h"

int main()
{
	menu* mainmenu = new menu();
	mainmenu->initMenu(mainmenu->ancho, mainmenu->alto);
}
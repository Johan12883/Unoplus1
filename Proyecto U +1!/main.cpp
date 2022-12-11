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
#include "ingame.h"
#include "difficulty.h"

int main()
{
	//Resolucion para imagenes. default(1280x720)
	int ancho = 576;
	int alto = 580;

	int x = -1, y = -1;
	int seg = 0;
	int difficulty = 0;
	// Jugar, Opciones, Salir
	int btn[] = { 0,0,0 };

	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR", "ERROR 404", "El programa no pudo cargar correctamente", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	int ancho_w = GetSystemMetrics(SM_CXSCREEN);
	int alto_w = GetSystemMetrics(SM_CYSCREEN);
	ALLEGRO_DISPLAY* main = al_create_display(ancho, alto);

	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT* pixel_font = al_load_font("pixelmix.ttf", 50, NULL);
	al_set_window_position(main, ancho_w / 2 - ancho / 2, alto_w / 2 - alto / 2);
	al_set_window_title(main, "UNO + 1!");

	//Codigo para cargar imagenes
	al_init_image_addon();
	ALLEGRO_BITMAP* menu_null = al_load_bitmap("menu_temp.PNG");
	ALLEGRO_BITMAP* diffmenu_null = al_load_bitmap("Papaspng.png");
	ALLEGRO_BITMAP* diffmenu_0 = al_load_bitmap("Papaspng112.png");
	ALLEGRO_BITMAP* diffmenu_1 = al_load_bitmap("tenkiu.jpg");
	ALLEGRO_BITMAP* background = al_load_bitmap("fondo_rojo.jpg");



	ALLEGRO_TIMER* segTimer = al_create_timer(1.0);
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(segTimer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_start_timer(segTimer);

	al_init_primitives_addon();
	ALLEGRO_COLOR blanco = al_map_rgb(255, 255, 255);
	ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);



	while (true)
	{
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			if (evento.timer.source == segTimer)
			{
				seg++;
			}
		}
		//Las capas aqui funcionan en orden ascendente
		al_draw_bitmap(menu_null, 0, 0, 0);		//Esta es la capa 1, la parte de hasta abajo (esta funcion carga la imagen en la pantalla)
		al_draw_text(pixel_font, al_map_rgb(0, 0, 0), ancho / 2, 100,
			ALLEGRO_ALIGN_CENTER, "UNO + 1!");		// Y esta es la capa 2, que esta arriba de la capa 1

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
			printf("x: %d, y: %d\n", x, y);

			//Boton jugar
			if (x >= 180 && x <= 390 && y >= 220 && y <= 300)
			{
				btn[0] = 1;
				// Click del mouse (& 1 para el boton izquierdo, & 2 para el boton derecho y & 4 para la rueda)
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); 
					al_clear_to_color(negro);
					difficulty = diffmenu(evento, queue, diffmenu_null, diffmenu_0, diffmenu_1, diffmenu_0); //Aca entrará a la funcion para jugar
					game(evento, queue, background, difficulty);
				}
				else
				{
					btn[0] = 0;
				}
			}

			//Boton opciones
			if (x >= 180 && x <= 390 && y >= 326 && y <= 405)
			{
				btn[1] = 1;
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); //Aca entrará a la funcion para las opciones
				}
				else
				{
					btn[1] = 0;
				}
			}

			//Boton salir
			if (x >= 180 && x <= 390 && y >= 432 && y <= 513)
			{
				btn[2] = 1;
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); //Aca saldra del juego
					return 1;
				}
				else
				{
					btn[2] = 0;
				}
			}
		}


		if (x >= 180 && x <= 390 && y >= 220 && y <= 300)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 220, 390, 300, blanco); //Aqui ira el menu donde se resaltara el boton "Jugar"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 220, 390, 300, negro); //Aqui ira el menu "NULL"

		}
		if (x >= 180 && x <= 390 && y >= 326 && y <= 405)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 326, 390, 405, blanco); //Aqui ira el menu donde se resaltara el boton "Opciones"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 326, 390, 405, negro); //Aqui ira el menu "NULL"
		}
		if (x >= 180 && x <= 390 && y >= 432 && y <= 513)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 432, 390, 513, blanco); //Aqui ira el menu donde se resaltara el boton "Salir"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_filled_rectangle(180, 432, 390, 513, negro); //Aqui ira el menu "NULL"
		}


		al_flip_display();

	}
}
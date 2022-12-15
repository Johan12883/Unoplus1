#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include "ingame.h"
#include "difficulty.h"

int main()
{
	//Resolucion para imagenes. default(1280x720)
	int ancho = 1280;
	int alto = 720;

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

	//Iniciadores de Addons
	al_install_mouse();
	al_install_audio();
	al_reserve_samples(1);
	al_init_acodec_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT* pixel_font = al_load_font("pixelmix.ttf", 50, NULL);
	al_set_window_position(main, ancho_w / 2 - ancho / 2, alto_w / 2 - alto / 2);
	al_set_window_title(main, "UNO + 1!");

	ALLEGRO_SAMPLE* music = al_load_sample("music.mp3");

	//Codigo para cargar imagenes
	al_init_image_addon();
	ALLEGRO_BITMAP* menu_null = al_load_bitmap("Menu_Principal/Menu_Simp.png");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("Menu_Principal/Menu_Jugar.png");
	ALLEGRO_BITMAP* menu_inst = al_load_bitmap("Menu_Principal/Menu_Inst.png");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("Menu_Principal/Menu_Salir.png");
	ALLEGRO_BITMAP* ins_back = al_load_bitmap("Instrucciones/Ins_Volver.png");
	ALLEGRO_BITMAP* ins_menu = al_load_bitmap("Instrucciones/Ins_Base.png");
	ALLEGRO_BITMAP* diffmenu_null = al_load_bitmap("Menu_Dificultades/Menu_Dif_Base.png");
	ALLEGRO_BITMAP* diffmenu_hard = al_load_bitmap("Menu_Dificultades/Menu_Dif_Dificil.png");
	ALLEGRO_BITMAP* diffmenu_ez = al_load_bitmap("Menu_Dificultades/Menu_Dif_Facil.png");
	ALLEGRO_BITMAP* diffmenu_normal = al_load_bitmap("Menu_Dificultades/Menu_Dif_Media.png");
	ALLEGRO_BITMAP* background = al_load_bitmap("fondo_rojo.jpg");


	//Temporizador
	ALLEGRO_TIMER* segTimer = al_create_timer(1.0);
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	//Eventos
	al_register_event_source(queue, al_get_timer_event_source(segTimer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_start_timer(segTimer);

	//Addon para figuras primitivasD
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

		al_play_sample(music, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
		//Las capas aqui funcionan en orden ascendente
		al_draw_bitmap(menu_null, 0, 0, 0);		//Esta es la capa 1, la parte de hasta abajo (esta funcion carga la imagen en la pantalla)
		al_draw_text(pixel_font, al_map_rgb(0, 0, 0), ancho / 2, 100,
			ALLEGRO_ALIGN_CENTER, "");		// Y esta es la capa 2, que esta arriba de la capa 1

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
			printf("x: %d, y: %d\n", x, y);

			//Boton jugar
			if (x >= 425 && x <= 785 && y >= 190 && y <= 320)
			{
				btn[0] = 1;
				// Click del mouse (& 1 para el boton izquierdo, & 2 para el boton derecho y & 4 para la rueda)
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); 
					al_clear_to_color(negro);
					difficulty = diffmenu(evento, queue, diffmenu_null, diffmenu_ez,diffmenu_normal,diffmenu_hard); //Aca entrará a la funcion para jugar
					game(evento, queue, background, difficulty);
				}
				else
				{
					btn[0] = 0;
				}
			}

			//Boton opciones
			if (x >= 413 && x <= 810 && y >= 369 && y <= 500)
			{
				btn[1] = 1;
				if (evento.mouse.button & 1)
				{
					if (x>= 0 && x<= 0 && y>= 0 && y <= 0)
					{
						printf("");
					}
				}
				else
				{
					btn[1] = 0;
				}
			}

			//Boton salir
			if (x >= 444 && x <= 783 && y >= 535 && y <= 665)
			{
				btn[2] = 1;
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); //Aca saldra del juego
					exit(0);
				}
				else
				{
					btn[2] = 0;
				}
			}
		}


		if (x >= 425 && x <= 785 && y >= 190 && y <= 320)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_jugar, 0, 0, 0); //Aqui ira el menu donde se resaltara el boton "Jugar"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_null, 0, 0, 0); //Aqui ira el menu "NULL"

		}
		if (x >= 413 && x <= 810 && y >= 369 && y <= 500)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_inst, 0, 0, 0); //Aqui ira el menu donde se resaltara el boton "Opciones"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_null, 0, 0, 0); //Aqui ira el menu "NULL"
		}
		if (x >= 444 && x <= 783 && y >= 535 && y <= 665)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_salir, 0, 0, 0); //Aqui ira el menu donde se resaltara el boton "Salir"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu_null, 0, 0, 0); //Aqui ira el menu "NULL"
		}


		al_flip_display();

	}
}
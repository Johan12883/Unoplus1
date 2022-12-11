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

int main()
{
	//Resolucion para imagenes. default(1280x720)
	int ancho = 576;
	int alto = 580;
	int x = -1, y = -1;
	int seg = 0;
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
	
	ALLEGRO_TIMER* segTimer = al_create_timer(1.0);
	ALLEGRO_EVENT evento;	
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(segTimer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_start_timer(segTimer);

	al_init_primitives_addon();
	ALLEGRO_COLOR blanco = al_map_rgb(255, 255, 255);



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
		al_draw_text(pixel_font, al_map_rgb(0, 0, 0), ancho/2, 100, 
			ALLEGRO_ALIGN_CENTER, "UNO + 1!");		// Y esta es la capa 2, que esta arriba de la capa 1

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;

			// Click del mouse (& 1 para el boton izquierdo, & 2 para el boton derecho y & 4 para la rueda)
			if (x >= 180 && x <= 390 && y >= 220 && y <= 300 && evento.mouse.button & 1)
			{
				al_draw_filled_rectangle(180, 220, 390, 300, blanco);
				printf("x: %d, y: %d\n", x, y);
			}
		}
		al_flip_display();
	}
}
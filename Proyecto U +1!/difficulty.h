#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

int diffmenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_0, ALLEGRO_BITMAP* menu_1, ALLEGRO_BITMAP* menu_2)
{
	int x = -1, y = -1;
	ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
	while (true)
	{
		al_wait_for_event(queue, &evento);
		al_draw_bitmap(menu_null, 0, 0, 0);


		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
		}

			if (x >= 56 && x <= 168 && y >= 290 && y <= 402)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); 
					return 1;
				}
			}

			if (x >= 280 && x <= 392 && y >= 290 && y <= 402)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y);
					return 2;
				}
			}

			if (x >= 504 && x <= 576 && y >= 290 && y <= 402)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y);
					return 3;
				}
			}


		if (x >= 56 && x <= 168 && y >= 290 && y <= 402)
		{
			al_draw_bitmap(menu_0, 56, 290, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		if (x >= 280 && x <= 392 && y >= 290 && y <= 402)
		{
			al_draw_bitmap(menu_1, 280, 290, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		if (x >= 504 && x <= 576 && y >= 290 && y <= 402)
		{
			al_draw_bitmap(menu_2, 504, 290, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		al_flip_display();
	}
	
}
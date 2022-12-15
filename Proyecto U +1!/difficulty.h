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
			printf("x: %d, y: %d\n", x, y);
			x = evento.mouse.x;
			y = evento.mouse.y;
		}

			if (x >= 138 && x <= 480 && y >= 290 && y <= 418)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y); 
					return 1;
				}
			}

			if (x >= 522 && x <= 860 && y >= 290 && y <= 420)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y);
					return 2;
				}
			}

			if (x >= 905 && x <= 1245 && y >= 290 && y <= 420)
			{
				if (evento.mouse.button & 1)
				{
					printf("x: %d, y: %d\n", x, y);
					return 3;
				}
			}

		if (x >= 138 && x <= 480 && y >= 290 && y <= 418)
		{
			al_draw_bitmap(menu_0, 0, 0, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		if (x >= 522 && x <= 860 && y >= 290 && y <= 420)
		{
			al_draw_bitmap(menu_1, 0, 0, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		if (x >= 905 && x <= 1245 && y >= 290 && y <= 420)
		{
			al_draw_bitmap(menu_2, 0, 0, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}

		al_flip_display();
	}
	
}
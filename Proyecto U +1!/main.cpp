#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR", "ERROR 404", "El programa no pudo cargar correctamente", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	int ancho = GetSystemMetrics(SM_CXSCREEN);
	int alto = GetSystemMetrics(SM_CYSCREEN);

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_DISPLAY* main = al_create_display(ancho/2, alto/2);
	ALLEGRO_FONT* pixel_font = al_load_font("pixelmix.ttf", 50, NULL);
	al_set_window_position(main, ancho / 2, alto / 2);
	al_set_window_title(main, "UNO + 1!");

	while (true)
	{
		al_draw_text(pixel_font, al_map_rgb(255, 255, 255), ancho/4, 100, ALLEGRO_ALIGN_CENTER, "UNO + 1!");
		al_flip_display();
	}
}
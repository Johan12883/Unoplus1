#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>



typedef struct deck
{
	ALLEGRO_BITMAP *card_0, *card_1, *card_2, *card_3, *card_4, *card_5, *card_6;
} Tdeck;

struct deck Vdeck[4];

int game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	while (true)
	{
		if (difficulty == 1)
		{
			al_wait_for_event(queue, &evento);
			al_draw_bitmap(bg, 0, 0, 0);

		}


		al_flip_display();
	}
	return 1;
}

Tdeck genDeck(int difficulty)
{
	int i, colorRand, numCard;
	srand(NULL);

	for (i = 0; i < 4; i++)
	{
		colorRand = rand() % 4;

		// Color verde
		if (colorRand == 1)
		{


			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_0 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}
			//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

			//Generacion de la segunda carta
			colorRand = rand() % 4;
			// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
				else if (numCard == 4)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_1 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}

		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Generacion de la tercera carta
		colorRand = rand() % 4;
		// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_2 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Generacion de la cuarta carta
		colorRand = rand() % 4;
		// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_3 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Generacion de la quinta carta
		colorRand = rand() % 4;
		// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_4 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Generacion de la sexta carta
		colorRand = rand() % 4;
		// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_5 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		//Generacion de la septima carta
		colorRand = rand() % 4;
		// Color verde
		if (colorRand == 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}

		}		//Color rojo
		else if (colorRand == 2)
		{

			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta rojo con numero 9
			}
		}		//Color amarillo
		else if (colorRand == 3)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}		//Color azul
		else if (colorRand == 4 && difficulty != 1)
		{
			numCard = rand() % 9;
			if (numCard == 1)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 1
			}
			else if (numCard == 2)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 2
			}
			else if (numCard == 3)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 3
			}
			else if (numCard == 4)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 4
			}
			else if (numCard == 5)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 5
			}
			else if (numCard == 6)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 6
			}
			else if (numCard == 7)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 7
			}
			else if (numCard == 8)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 8
			}
			else if (numCard == 9)
			{
				Vdeck[i].card_6 = al_load_bitmap(""); // Nombre de la imagen de la carta verde con numero 9
			}
		}

	}
}
	
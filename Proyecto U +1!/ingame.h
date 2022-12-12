#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

int genDeck(int difficulty);

typedef struct deck
{
	ALLEGRO_BITMAP *card[7];
	int numcard[7];
	int color0, color1, color2, color3, color4, color5, color6;
} Tdeck;

struct deck Vdeck[4];

int game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	genDeck(difficulty);
	Tdeck playerDeck = Vdeck[0];
	while (true)
	{
		if (difficulty == 1)
		{
			al_wait_for_event(queue, &evento);
			al_draw_bitmap(bg, 0, 0, 0);
			al_draw_bitmap(playerDeck.card[0], 320, 650, 0);
			al_draw_bitmap(playerDeck.card[1], 380, 650, 0);
			al_draw_bitmap(playerDeck.card[2], 440, 650, 0);
			al_draw_bitmap(playerDeck.card[3], 500, 650, 0);
			al_draw_bitmap(playerDeck.card[4], 560, 650, 0);
			al_draw_bitmap(playerDeck.card[5], 620, 650, 0);
			al_draw_bitmap(playerDeck.card[6], 680, 650, 0);




		}


		al_flip_display();
	}
	return 1;
}

int genDeck(int difficulty)
{
	int i, j, colorRand, numCard;
	srand(time(NULL));

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 7; j++)
		{
			if (difficulty == 3)
			{
				colorRand = rand() % 5 + 1;
			}
			else if (difficulty == 1)
			{
				colorRand = rand() % 3 + 1;
			}
			else
			{
				colorRand = rand() % 4 + 1;
			}

			Vdeck[i].color0 = colorRand;

			// Color verde
			if (colorRand == 1)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png"); // Nombre de la imagen de la carta verde con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png"); // Nombre de la imagen de la carta verde con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png"); // Nombre de la imagen de la carta verde con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png"); // Nombre de la imagen de la carta verde con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png"); // Nombre de la imagen de la carta verde con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png"); // Nombre de la imagen de la carta verde con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png"); // Nombre de la imagen de la carta verde con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png"); // Nombre de la imagen de la carta verde con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png"); // Nombre de la imagen de la carta verde con numero 9
					Vdeck[i].numcard[j] = 9;
				}

			}		//Color rojo
			else if (colorRand == 2)
			{

				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png"); // Nombre de la imagen de la carta rojo con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png"); // Nombre de la imagen de la carta rojo con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png"); // Nombre de la imagen de la carta rojo con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png"); // Nombre de la imagen de la carta rojo con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png"); // Nombre de la imagen de la carta rojo con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png"); // Nombre de la imagen de la carta rojo con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png"); // Nombre de la imagen de la carta rojo con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png"); // Nombre de la imagen de la carta rojo con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png"); // Nombre de la imagen de la carta rojo con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color amarillo
			else if (colorRand == 3)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png"); // Nombre de la imagen de la carta amarillo con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png"); // Nombre de la imagen de la carta amarillo con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png"); // Nombre de la imagen de la carta amarillo con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png"); // Nombre de la imagen de la carta amarillo con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png"); // Nombre de la imagen de la carta amarillo con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png"); // Nombre de la imagen de la carta amarillo con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png"); // Nombre de la imagen de la carta amarillo con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png"); // Nombre de la imagen de la carta amarillo con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png"); // Nombre de la imagen de la carta amarillo con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color azul
			else if (colorRand == 4 && difficulty != 1)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_1.png"); // Nombre de la imagen de la carta azul con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_2.png"); // Nombre de la imagen de la carta azul con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_3.png"); // Nombre de la imagen de la carta azul con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_4.png"); // Nombre de la imagen de la carta azul con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_5.png"); // Nombre de la imagen de la carta azul con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_6.png"); // Nombre de la imagen de la carta azul con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_7.png"); // Nombre de la imagen de la carta azul con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_8.png"); // Nombre de la imagen de la carta azul con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_9.png"); // Nombre de la imagen de la carta azul con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color negro (Exponeciales)
			else if (colorRand == 5 && difficulty == 3)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}
		}
	}

	return 1;
}
	
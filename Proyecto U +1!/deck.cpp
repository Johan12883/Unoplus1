#include "deck.h"
#include "Jugador.h"

int deck::game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	genDeck(difficulty);
	//Tdeck playerDeck = Vdeck[0];
	
	for (auto it : deck::GetDeckP1().deckcards)
	{
		int x = 320, y = 650;
		al_wait_for_event(queue, &evento);
		al_draw_bitmap(bg, 0, 0, 0);
		al_draw_bitmap(it.first, x, y, 0);
		x += 200;	
	}
		al_flip_display();
	return 1;
}




deck::deck()
{

}

int deck::genDeck(int difficulty)
{
	int i, j, colorRand, numCard;
	srand(time(NULL));
	deck* Pdeck = new deck;


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

			//////////////Vdeck[i].color0 = colorRand;

			numCard = rand() % 9 + 1;
			deck::GetDeckP1().color_numcard.insert(std::make_pair(colorRand, numCard));

			// Color verde
			if (colorRand == 1)
			{
				if (numCard == 1)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_1.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png"); // Nombre de la imagen de la carta verde con numero 1
					/////Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					//Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png"); // Nombre de la imagen de la carta verde con numero 2
					//Vdeck[i].numcard[j] = 2;
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_2.png"), color_numcard));

				}
				else if (numCard == 3)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_3.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png"); // Nombre de la imagen de la carta verde con numero 3
					////Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_4.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png"); // Nombre de la imagen de la carta verde con numero 4
					/////Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_5.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png"); // Nombre de la imagen de la carta verde con numero 5
					/////Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_6.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png"); // Nombre de la imagen de la carta verde con numero 6
					////Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_7.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png"); // Nombre de la imagen de la carta verde con numero 7
					////Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_8.png"), color_numcard));
					///Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png"); // Nombre de la imagen de la carta verde con numero 8
					///Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Verdes/Ve_Num_9.png"), color_numcard));
					///Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png"); // Nombre de la imagen de la carta verde con numero 9
					////Vdeck[i].numcard[j] = 9;
				}

			}		//Color rojo
			else if (colorRand == 2)
			{
				if (numCard == 1)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_1.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png"); // Nombre de la imagen de la carta rojo con numero 1
					////Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_2.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png"); // Nombre de la imagen de la carta rojo con numero 2
					////Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_3.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png"); // Nombre de la imagen de la carta rojo con numero 3
					////Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_4.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png"); // Nombre de la imagen de la carta rojo con numero 4
					////Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_5.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png"); // Nombre de la imagen de la carta rojo con numero 5
					////Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_6.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png"); // Nombre de la imagen de la carta rojo con numero 6
					////Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_7.png"), color_numcard));
					//////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png"); // Nombre de la imagen de la carta rojo con numero 7
					/////Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_8.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png"); // Nombre de la imagen de la carta rojo con numero 8
					/////Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Rojas/Ro_Num_9.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png"); // Nombre de la imagen de la carta rojo con numero 9
					////Vdeck[i].numcard[j] = 9;
				}
			}		//Color amarillo
			else if (colorRand == 3)
			{
				if (numCard == 1)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_1.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png"); // Nombre de la imagen de la carta amarillo con numero 1
					/////Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_2.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png"); // Nombre de la imagen de la carta amarillo con numero 2
					////Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_3.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png"); // Nombre de la imagen de la carta amarillo con numero 3
					////Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_4.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png"); // Nombre de la imagen de la carta amarillo con numero 4
					////Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_5.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png"); // Nombre de la imagen de la carta amarillo con numero 5
					////Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_6.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png"); // Nombre de la imagen de la carta amarillo con numero 6
					////Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_7.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png"); // Nombre de la imagen de la carta amarillo con numero 7
					/////Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_8.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png"); // Nombre de la imagen de la carta amarillo con numero 8
					////Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Amarillas/Am_Num_9.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png"); // Nombre de la imagen de la carta amarillo con numero 9
					////Vdeck[i].numcard[j] = 9;
				}
			}		//Color azul
			else if (colorRand == 4 && difficulty != 1)
			{
				if (numCard == 1)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_1.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_1.png"); // Nombre de la imagen de la carta azul con numero 1
					////Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_2.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_2.png"); // Nombre de la imagen de la carta azul con numero 2
					////Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_3.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_3.png"); // Nombre de la imagen de la carta azul con numero 3
					////Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_4.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_4.png"); // Nombre de la imagen de la carta azul con numero 4
					////Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_5.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_5.png"); // Nombre de la imagen de la carta azul con numero 5
					////Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_6.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_6.png"); // Nombre de la imagen de la carta azul con numero 6
					////Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_7.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_7.png"); // Nombre de la imagen de la carta azul con numero 7
					////Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_8.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_8.png"); // Nombre de la imagen de la carta azul con numero 8
					////Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Azules/Az_Num_9.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_9.png"); // Nombre de la imagen de la carta azul con numero 9
					////Vdeck[i].numcard[j] = 9;
				}
			}		//Color negro (Exponeciales)
			else if (colorRand == 5 && difficulty == 3)
			{
				if (numCard == 1)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_1.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 1
					////Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_2.png"), color_numcard));
					//Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 2
					//Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_3.png"), color_numcard));
					///Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 3
					///Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_4.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 4
					////Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_5.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 5
					////Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_6.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 6
					////Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_7.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 7
					////Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_8.png"), color_numcard));
					/////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 8
					/////Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					deck::GetDeckP1().deckcards.insert(std::make_pair(al_load_bitmap("Cartas_Negras/Ne_Num_9.png"), color_numcard));
					////Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_0.png"); // Nombre de la imagen de la carta negro con numero 9
					////Vdeck[i].numcard[j] = 9;
				}
				//Jugador* Player = new Jugador(i, Pdeck);

			}
		}
	}
	return 1;
}

deck& deck::GetDeckP1()
{
	static deck	singletonP1;
	return singletonP1;
}
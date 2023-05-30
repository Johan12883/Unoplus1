#include "deck.h"
#include "Jugador.h"


deck::~deck()
{
	for (auto& dc : deckcards)
		delete dc.second;
	deckcards.clear();
	color_numcard.clear();
}

ALLEGRO_BITMAP* deck::genMidCard(int difficulty)
{
	int colorRand, numCard;
	ALLEGRO_BITMAP* midcard;
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

	numCard = rand() % 9 + 1;

	// Color verde
	if (colorRand == 1)
	{
		if (numCard == 1)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png");
		}
		else if (numCard == 2)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png");

		}
		else if (numCard == 3)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png");
		}
		else if (numCard == 4)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png");
		}
		else if (numCard == 5)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png");
		}
		else if (numCard == 6)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png");
		}
		else if (numCard == 7)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png");
		}
		else if (numCard == 8)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png");
		}
		else if (numCard == 9)
		{
			midcard = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png");
		}

	}		//Color rojo
	else if (colorRand == 2)
	{
		if (numCard == 1)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png");
		}
		else if (numCard == 2)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png");
		}
		else if (numCard == 3)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png");
		}
		else if (numCard == 4)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png");
		}
		else if (numCard == 5)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png");
		}
		else if (numCard == 6)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png");
		}
		else if (numCard == 7)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png");
		}
		else if (numCard == 8)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png");
		}
		else if (numCard == 9)
		{
			midcard = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png");
		}
	}		//Color amarillo
	else if (colorRand == 3)
	{
		if (numCard == 1)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png");
		}
		else if (numCard == 2)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png");
		}
		else if (numCard == 3)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png");
		}
		else if (numCard == 4)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png");
		}
		else if (numCard == 5)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png");
		}
		else if (numCard == 6)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png");
		}
		else if (numCard == 7)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png");
		}
		else if (numCard == 8)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png");
		}
		else if (numCard == 9)
		{
			midcard = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png");
		}
	}		//Color azul
	else if (colorRand == 4 && difficulty != 1)
	{
		if (numCard == 1)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_1.png");
		}
		else if (numCard == 2)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_2.png");
		}
		else if (numCard == 3)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_3.png");
		}
		else if (numCard == 4)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_4.png");
		}
		else if (numCard == 5)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_5.png");
		}
		else if (numCard == 6)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_6.png");
		}
		else if (numCard == 7)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_7.png");
		}
		else if (numCard == 8)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_8.png");
		}
		else if (numCard == 9)
		{
			midcard = al_load_bitmap("Cartas_Azules/Az_Num_9.png");
		}
	}		//Color negro (Exponeciales)
	else if (colorRand == 5 && difficulty == 3)
	{
		if (numCard == 1)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_1.png");
		}
		else if (numCard == 2)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_2.png");
		}
		else if (numCard == 3)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_3.png");
		}
		else if (numCard == 4)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_4.png");
		}
		else if (numCard == 5)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_5.png");
		}
		else if (numCard == 6)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_6.png");
		}
		else if (numCard == 7)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_7.png");
		}
		else if (numCard == 8)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_8.png");
		}
		else if (numCard == 9)
		{
			midcard = al_load_bitmap("Cartas_Negras/Ne_Num_9.png");
		}
	}
	return midcard;

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


			numCard = rand() % 9 + 1;
			Pdeck->color_numcard.insert(std::make_pair(colorRand, numCard));

			// Color verde
			if (colorRand == 1)
			{
				if (numCard == 1)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_1.png")));
				}
				else if (numCard == 2)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_2.png")));

				}
				else if (numCard == 3)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_3.png")));
				}
				else if (numCard == 4)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_4.png")));
				}
				else if (numCard == 5)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_5.png")));
				}
				else if (numCard == 6)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_6.png")));
				}
				else if (numCard == 7)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_7.png")));
				}
				else if (numCard == 8)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_8.png")));
				}
				else if (numCard == 9)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Verdes/Ve_Num_9.png")));
				}

			}		//Color rojo
			else if (colorRand == 2)
			{
				if (numCard == 1)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_1.png")));
				}
				else if (numCard == 2)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_2.png")));
				}
				else if (numCard == 3)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_3.png")));
				}
				else if (numCard == 4)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_4.png")));
				}
				else if (numCard == 5)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_5.png")));
				}
				else if (numCard == 6)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_6.png")));
				}
				else if (numCard == 7)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_7.png")));
				}
				else if (numCard == 8)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_8.png")));
				}
				else if (numCard == 9)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Rojas/Ro_Num_9.png")));
				}
			}		//Color amarillo
			else if (colorRand == 3)
			{
				if (numCard == 1)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_1.png")));
				}
				else if (numCard == 2)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_2.png")));
				}
				else if (numCard == 3)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_3.png")));
				}
				else if (numCard == 4)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_4.png")));
				}
				else if (numCard == 5)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_5.png")));
				}
				else if (numCard == 6)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_6.png")));
				}
				else if (numCard == 7)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_7.png")));
				}
				else if (numCard == 8)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_8.png")));
				}
				else if (numCard == 9)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Amarillas/Am_Num_9.png")));
				}
			}		//Color azul
			else if (colorRand == 4 && difficulty != 1)
			{
				if (numCard == 1)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_1.png")));
				}
				else if (numCard == 2)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_2.png")));
				}
				else if (numCard == 3)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_3.png")));
				}
				else if (numCard == 4)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_4.png")));
				}
				else if (numCard == 5)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_5.png")));
				}
				else if (numCard == 6)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_6.png")));
				}
				else if (numCard == 7)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_7.png")));
				}
				else if (numCard == 8)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_8.png")));
				}
				else if (numCard == 9)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Azules/Az_Num_9.png")));
				}
			}		//Color negro (Exponeciales)
			else if (colorRand == 5 && difficulty == 3)
			{
				if (numCard == 1)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_1.png")));
				}
				else if (numCard == 2)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_2.png")));
				}
				else if (numCard == 3)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_3.png")));
				}
				else if (numCard == 4)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_4.png")));
				}
				else if (numCard == 5)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_5.png")));
				}
				else if (numCard == 6)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_6.png")));
				}
				else if (numCard == 7)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_7.png")));
				}
				else if (numCard == 8)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_8.png")));
				}
				else if (numCard == 9)
				{
					Pdeck->deckcards.insert(std::make_pair(color_numcard, al_load_bitmap("Cartas_Negras/Ne_Num_9.png")));
				}

				
			}
		}
		if(i == 1)
			Jugador::GetJugador1().Pdeck = Pdeck;
		if (i == 2)
			Jugador::GetJugador2().Pdeck = Pdeck;
		if (i == 3)
			Jugador::GetJugador3().Pdeck = Pdeck;
		if (i == 4)
			Jugador::GetJugador4().Pdeck = Pdeck;
	}
	return 1;
}


deck& deck::GetDeckP1()
{
	static deck	singletonP1;
	return singletonP1;
}
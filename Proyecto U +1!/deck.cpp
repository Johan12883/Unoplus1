#include "deck.h"
#include "Jugador.h"


deck::~deck()
{
	color.clear();
	numcard.clear();
	deckcards.clear();
}

ALLEGRO_BITMAP* deck::genCard(int difficulty, int colorRand, int numCard)
{
	ALLEGRO_BITMAP* card;
	
	// Color verde
	if (colorRand == 1)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png");
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png");

		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png");
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png");
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png");
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png");
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png");
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png");
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png");
		}

	}		//Color rojo
	else if (colorRand == 2)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png");
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png");
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png");
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png");
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png");
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png");
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png");
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png");
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png");
		}
	}		//Color amarillo
	else if (colorRand == 3)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png");
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png");
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png");
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png");
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png");
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png");
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png");
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png");
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png");
		}
	}		//Color azul
	else if (colorRand == 4 && difficulty != 1)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_1.png");
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_2.png");
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_3.png");
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_4.png");
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_5.png");
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_6.png");
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_7.png");
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_8.png");
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_9.png");
		}
	}		//Color negro (Exponeciales)
	else if (colorRand == 5 && difficulty == 3)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_1.png");
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_2.png");
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_3.png");
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_4.png");
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_5.png");
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_6.png");
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_7.png");
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_8.png");
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_9.png");
		}
	}
	return card;

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
			Pdeck->color.push_back(colorRand);
			Pdeck->numcard.push_back(numCard);
			Pdeck->deckcards.push_back(genCard(difficulty, colorRand, numCard));
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
	delete Pdeck;
	return 1;
}
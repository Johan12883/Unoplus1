#include "Card.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

Card::Card(int color, int numcard, ALLEGRO_BITMAP* asset_card)
{
	this->color = color;
	this->numcard = numcard;
	this->asset_card = asset_card;
}

Card::~Card()
{
	this->asset_card = nullptr;
	this->color = NULL;
	this->numcard = NULL;
}

ALLEGRO_BITMAP* Card::genCard(int difficulty, int colorRand, int numCard)
{
	ALLEGRO_BITMAP* card;

	// Color verde
	if (colorRand == 1)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png");
			return card;
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png");
			return card;
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png");
			return card;
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png");
			return card;
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png");
			return card;
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png");
			return card;
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png");
			return card;
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png");
			return card;
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png");
			return card;
		}

	}		//Color rojo
	else if (colorRand == 2)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png");
			return card;
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png");
			return card;
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png");
			return card;
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png");
			return card;
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png");
			return card;
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png");
			return card;
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png");
			return card;
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png");
			return card;
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png");
			return card;
		}
	}		//Color amarillo
	else if (colorRand == 3)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png");
			return card;
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png");
			return card;
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png");
			return card;
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png");
			return card;
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png");
			return card;
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png");
			return card;
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png");
			return card;
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png");
			return card;
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png");
			return card;
		}
	}		//Color azul
	else if (colorRand == 4 && difficulty != 1)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_1.png");
			return card;
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_2.png");
			return card;
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_3.png");
			return card;
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_4.png");
			return card;
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_5.png");
			return card;
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_6.png");
			return card;
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_7.png");
			return card;
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_8.png");
			return card;
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Azules/Az_Num_9.png");
			return card;
		}
	}		//Color negro (Exponeciales)
	else if (colorRand == 5 && difficulty == 3)
	{
		if (numCard == 1)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_1.png");
			return card;
		}
		else if (numCard == 2)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_2.png");
			return card;
		}
		else if (numCard == 3)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_3.png");
			return card;
		}
		else if (numCard == 4)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_4.png");
			return card;
		}
		else if (numCard == 5)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_5.png");
			return card;
		}
		else if (numCard == 6)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_6.png");
			return card;
		}
		else if (numCard == 7)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_7.png");
			return card;
		}
		else if (numCard == 8)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_8.png");
			return card;
		}
		else if (numCard == 9)
		{
			card = al_load_bitmap("Cartas_Negras/Ne_Num_9.png");
			return card;
		}
	}

}
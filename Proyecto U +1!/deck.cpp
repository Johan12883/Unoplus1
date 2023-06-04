#include "deck.h"
#include "Jugador.h"
#include "Card.h"
#include <stdlib.h>
#include <memory>
using std::unique_ptr;

deck::~deck()
{
	deckcards.clear();
}


deck* deck::genDeck(int difficulty)
{
	int i, colorRand, numCard;
	srand(time(NULL));
	deck* Pdeck = new deck;


	for (i = 0; i < 6; i++)
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

		Card* card = new Card(colorRand, numCard);
		card->asset_card = card->genCard(difficulty, colorRand, numCard);
		
		Pdeck->deckcards.push_back(card);
	}
	return Pdeck;
}
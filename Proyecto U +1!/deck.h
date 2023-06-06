#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include "Card.h"
using std::vector;
class deck
{
public:
	int numPlayerDeck = 0, CardsLeft = 7;
	vector <Card*> deckcards;
	vector <bool> CardsFlags = { true,true,true,true,true,true,true };
	
	~deck();
	deck* genDeck(int difficulty);
};


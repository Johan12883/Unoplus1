#pragma once
#include <allegro5/allegro.h>
class Card
{
public:
	int color = 0, numcard = 0;
	bool flag = true;
	Card(int color = 0, int numcard = 0, ALLEGRO_BITMAP* asset_card = nullptr);
	~Card();
	ALLEGRO_BITMAP* asset_card = nullptr;
	ALLEGRO_BITMAP* genCard(int difficulty, int colorRand, int numCard);
};


#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <map>

using std::map;

class deck
{
public:
	ALLEGRO_BITMAP* card;
	// first: color; second: numcard;
	map <int, int> color_numcard;
	map < ALLEGRO_BITMAP*, map <int, int>> deckcards;
	
	deck();
	int genDeck(int difficulty);
	int game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty);
	static deck& GetDeckP1();
};


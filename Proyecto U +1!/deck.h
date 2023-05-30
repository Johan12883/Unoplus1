#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <map>

using std::map;

class deck
{
public:
	int numPlayerDeck;
	// first: color; second: numcard;
	map <int, int> color_numcard;
	map <map <int, int>, ALLEGRO_BITMAP*> deckcards;
	
	~deck();
	ALLEGRO_BITMAP* genMidCard(int difficulty);
	int genDeck(int difficulty);
	static deck& GetDeckP1();
};


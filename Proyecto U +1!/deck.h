#pragma once
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <map>
#include <vector>
#include <list>
using std::map;
using std::vector;
using std::list;
class deck
{
public:
	int numPlayerDeck;
	// first: color; second: numcard;
	//map <int, int> color_numcard;
	vector<int> color;
	vector<int> numcard;
	vector <ALLEGRO_BITMAP*> deckcards;
	
	~deck();
	ALLEGRO_BITMAP* genCard(int difficulty, int colorRand, int numCard);
	int genDeck(int difficulty);
};


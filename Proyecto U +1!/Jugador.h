#pragma once
#include "deck.h"
class Jugador
{
public:
	int Pnum;
	bool turn = false, AnsweredBool = false;
	deck* Pdeck;

	Jugador(int Pnum_, deck* deck_ = nullptr);
	static Jugador& GetJugador1();
	static Jugador& GetJugador2();
	static Jugador& GetJugador3();
	static Jugador& GetJugador4();

};


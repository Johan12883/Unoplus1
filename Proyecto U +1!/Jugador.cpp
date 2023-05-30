#include "Jugador.h"

Jugador::Jugador(int Pnum_, deck* deck_)
{
	this->Pnum = Pnum_;
	this->Pdeck = deck_;
}

Jugador& Jugador::GetJugador1()
{
	static Jugador singletonP1(1);
	return singletonP1;
	// TODO: Insertar una instrucción "return" aquí
}

Jugador& Jugador::GetJugador2()
{
	static Jugador singletonP2(2);
	return singletonP2;
	// TODO: Insertar una instrucción "return" aquí
}

Jugador& Jugador::GetJugador3()
{
	static Jugador singletonP3(3);
	return singletonP3;
	// TODO: Insertar una instrucción "return" aquí
}

Jugador& Jugador::GetJugador4()
{
	static Jugador singletonP4(4);
	return singletonP4;
	// TODO: Insertar una instrucción "return" aquí
}
#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <math.h>
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

int main();
int genDeck(int difficulty);
int gameover(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue);
ALLEGRO_BITMAP* load_cardmid(int color, int numCard);
int cardOp(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, int numcard1, int color1, int numcard2, int color2, int pobturn);
int ansOp(int numcard1, int numcard2, int color2, int randOp);



typedef struct deck
{
	ALLEGRO_BITMAP *card[7];
	int numcard[7];
	int color[7];
	int qcard = 7;
} Tdeck;

struct deck Vdeck[4];

int game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	srand(time(NULL));
	int ans = 2, ansbot1 = 2, ansbot2 = 2, ansbot3 = 2;
	int x = -1, y = -1;
	int randPC, randNC, randPC_aux, randNC_aux;
	int btn[] = { 0,0,0,0,0,0,0 };
	int clickflag[7] = { 0,0,0,0,0,0,0 };
	int turn = 0;
	int cardflag = 0;

	int cardflagbot1 = 0;
	int cardflagbot2 = 0;
	int cardflagbot3 = 0;

	int clickflagbot1[7] = { 0,0,0,0,0,0,0 };
	int clickflagbot2[7] = { 0,0,0,0,0,0,0 };
	int clickflagbot3[7] = { 0,0,0,0,0,0,0 };

	int cardStart = 0;
	int qturn = 0;
	randPC = rand() % 4;
	randNC = rand() % 7;

	ALLEGRO_BITMAP* cardmid_draw[25];
	ALLEGRO_BITMAP* engr = al_load_bitmap("engranaje.png");
	ALLEGRO_BITMAP* backcard = al_load_bitmap("Carta_Atras.png");
	ALLEGRO_BITMAP* revder = al_load_bitmap("Carta_Atras_Botder.png");
	ALLEGRO_BITMAP* revizq = al_load_bitmap("Carta_Atras_Botizq.png");
	ALLEGRO_BITMAP* revrev = al_load_bitmap("Carta_Atras_Botrev.png");
	ALLEGRO_BITMAP* passCard = al_load_bitmap("passCard.png");

	genDeck(difficulty);

	Tdeck cardmid = Vdeck[randPC];
	Tdeck cardmid_aux;
	cardmid_draw[24] = cardmid.card[randNC];
	Tdeck playerDeck = Vdeck[0];

	while (true)
	{

		al_wait_for_event(queue, &evento);
		al_draw_bitmap(bg, 0, 0, 0);

		al_draw_bitmap(cardmid.card[randNC], 580, 260, 0);



		al_draw_bitmap(revder, 0, 110, 0);
		al_draw_bitmap(revder, 0, 170, 0);
		al_draw_bitmap(revder, 0, 230, 0);
		al_draw_bitmap(revder, 0, 290, 0);
		al_draw_bitmap(revder, 0, 350, 0);
		al_draw_bitmap(revder, 0, 410, 0);
		al_draw_bitmap(revder, 0, 470, 0);

		al_draw_bitmap(revizq, 1200, 110, 0);
		al_draw_bitmap(revizq, 1200, 170, 0);
		al_draw_bitmap(revizq, 1200, 230, 0);
		al_draw_bitmap(revizq, 1200, 290, 0);
		al_draw_bitmap(revizq, 1200, 350, 0);
		al_draw_bitmap(revizq, 1200, 410, 0);
		al_draw_bitmap(revizq, 1200, 470, 0);

		al_draw_bitmap(revrev, 420, 0, 0);
		al_draw_bitmap(revrev, 480, 0, 0);
		al_draw_bitmap(revrev, 540, 0, 0);
		al_draw_bitmap(revrev, 600, 0, 0);
		al_draw_bitmap(revrev, 660, 0, 0);
		al_draw_bitmap(revrev, 720, 0, 0);
		al_draw_bitmap(revrev, 780, 0, 0);

		if (clickflag[0] == 0)
		{
			al_draw_bitmap(playerDeck.card[0], 100, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 100, 535, 0);
		}

		if (clickflag[1] == 0)
		{
			al_draw_bitmap(playerDeck.card[1], 240, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 240, 535, 0);

		}

		if (clickflag[2] == 0)
		{
			al_draw_bitmap(playerDeck.card[2], 380, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 380, 535, 0);

		}

		if (clickflag[3] == 0)
		{
			al_draw_bitmap(playerDeck.card[3], 520, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 520, 535, 0);
		}

		if (clickflag[4] == 0)
		{
			al_draw_bitmap(playerDeck.card[4], 660, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 660, 535, 0);
		}

		if (clickflag[5] == 0)
		{
			al_draw_bitmap(playerDeck.card[5], 800, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 800, 535, 0);
		}

		if (clickflag[6] == 0)
		{
			al_draw_bitmap(playerDeck.card[6], 940, 535, 0);
		}
		else
		{
			al_draw_bitmap(backcard, 940, 535, 0);
		}


		al_draw_bitmap(passCard, 980, 475, 0);
		al_draw_bitmap(engr, 1230, 0, 0);

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
		}

		if (turn == 0)
		{
			if (cardStart == 1 && cardflag == 0 && ans == 2)
			{
				ans = cardOp(evento, queue, cardmid_aux.numcard[randNC_aux], cardmid_aux.color[randNC_aux], cardmid.numcard[randNC], cardmid.color[randNC], 1);
				ansbot1 = 2;
				ansbot2 = 2;
				ansbot3 = 2;
			}

			if (ans == 0)
			{
				cardflag = 1;
				turn++;
			}

			if (x >= 980 && x <= 1028 && y >= 475 && y <= 515)
			{
				if (evento.mouse.button & 1)
				{
					turn++;
					cardflag = 1;
					printf("A saltado turno!\n");
				}
			}

			if (cardflag == 0)
			{
				//Boton carta 1
				if (x >= 100 && x <= 225 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[0] == Vdeck[randPC].color[randNC] || playerDeck.numcard[0] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[0] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[0] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 0;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}

				}
			}


			if (cardflag == 0)
			{
				//Boton carta 2
				if (x >= 240 && x <= 365 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[1] == Vdeck[randPC].color[randNC] || playerDeck.numcard[1] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[1] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[1] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 1;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}
				}
			}

			if (cardflag == 0)
			{
				//Boton carta 3
				if (x >= 380 && x <= 505 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[2] == Vdeck[randPC].color[randNC] || playerDeck.numcard[2] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[2] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[2] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 2;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}

				}
			}


			if (cardflag == 0)
			{
				//Boton carta 4
				if (x >= 520 && x <= 645 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[3] == Vdeck[randPC].color[randNC] || playerDeck.numcard[3] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[3] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[3] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 3;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}
				}
			}

			if (cardflag == 0)
			{
				//Boton carta 5
				if (x >= 660 && x <= 785 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[4] == Vdeck[randPC].color[randNC] || playerDeck.numcard[4] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[4] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[4] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 4;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}

				}
			}

			if (cardflag == 0)
			{
				//Boton carta 6
				if (x >= 800 && x <= 925 && y >= 535 && y <= 710)
				{
					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[5] == Vdeck[randPC].color[randNC] || playerDeck.numcard[5] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[5] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[5] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 5;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}

				}
			}

			if (cardflag == 0)
			{
				//Boton carta 7
				if (x >= 940 && x <= 1065 && y >= 535 && y <= 710)
				{

					if (evento.mouse.button & 1)
					{
						if (playerDeck.color[6] == Vdeck[randPC].color[randNC] || playerDeck.numcard[6] == Vdeck[randPC].numcard[randNC])
						{
							if (clickflag[6] == 0)
							{
								printf("x: %d, y: %d\n", x, y);
								cardmid_aux = cardmid;
								cardmid = playerDeck;
								clickflag[6] = 1;
								randNC_aux = randNC;
								randPC_aux = randPC;
								randNC = 6;
								randPC = 0;
								cardflag = 1;
								turn++;
								playerDeck.qcard = playerDeck.qcard - 1;
								cardStart = 1;
							}
						}
					}

				}
			}



		}

		if (turn == 1)
		{
			if (cardStart == 1 && cardflagbot1 == 0 && ansbot1 == 2)
			{
				ansbot1 = cardOp(evento, queue, cardmid_aux.numcard[randNC_aux], cardmid_aux.color[randNC_aux], cardmid.numcard[randNC], cardmid.color[randNC], 0);
				ans = 2;
				ansbot2 = 2;
				ansbot3 = 2;
			}

			if (ansbot1 == 0)
			{
				cardflagbot1 = 1;
				turn++;
			}

			Sleep(2000);
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[0] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[0] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[0] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 0;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[0] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[1] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[1] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[1] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 1;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[1] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[2] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[2] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[2] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 2;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[2] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[3] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[3] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[3] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 3;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[3] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[4] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[4] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[4] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 4;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[4] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[5] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[5] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1[5] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 5;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[5] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot1 == 0)
			{
				if (Vdeck[1].color[6] == Vdeck[randPC].color[randNC] || Vdeck[1].numcard[6] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot1 == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[1];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 6;
						randPC = 1;
						turn++;
						Vdeck[1].qcard = Vdeck[1].qcard - 1;
						clickflagbot1[6] = 1;
						cardflagbot1 = 1;
						printf("Turno de bot 1\n");
						cardStart = 1;
					}

				}
			}

			if (cardflagbot1 == 0)
			{
				turn++;
			}

		}


		if (turn == 2)
		{
			if (cardStart == 1 && cardflagbot2 == 0 && ansbot2 == 2)
			{
				ansbot2 = cardOp(evento, queue, cardmid_aux.numcard[randNC_aux], cardmid_aux.color[randNC_aux], cardmid.numcard[randNC], cardmid.color[randNC], 0);
				ans = 2;
				ansbot1 = 2;
				ansbot3 = 2;
			}

			if (ansbot2 == 0)
			{
				cardflagbot2 = 1;
				turn++;
			}
			Sleep(2000);
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[0] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[0] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[0] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 0;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[0] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[1] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[1] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[1] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 1;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[1] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[2] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[2] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[2] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 2;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[2] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[3] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[3] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[3] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 3;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[3] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[4] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[4] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[4] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 4;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[4] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}

				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[5] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[5] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2[5] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 5;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[5] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[2].color[6] == Vdeck[randPC].color[randNC] || Vdeck[2].numcard[6] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot2 == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[2];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 6;
						randPC = 2;
						turn++;
						Vdeck[2].qcard = Vdeck[2].qcard - 1;
						clickflagbot2[6] = 1;
						cardflagbot2 = 1;
						printf("Turno de bot 2\n");
						cardStart = 1;
					}

				}
			}

			if (cardflagbot2 == 0)
			{
				turn++;
			}
		}

		if (turn == 3)
		{

			if (cardStart == 1 && cardflagbot3 == 0 && ansbot3 == 2)
			{
				ansbot3 = cardOp(evento, queue, cardmid_aux.numcard[randNC_aux], cardmid_aux.color[randNC_aux], cardmid.numcard[randNC], cardmid.color[randNC], 0);
				ans = 2;
				ansbot1 = 2;
				ansbot2 = 2;
			}

			if (ansbot3 == 0)
			{
				cardflagbot3 = 1;
				turn++;
			}

			Sleep(2000);
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[0] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[0] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[0] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 0;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[0] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						printf("%d %d %d\n", Vdeck[3].numcard[0], Vdeck[3].color[0], Vdeck[3].qcard);
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[1] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[1] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[1] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 1;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[1] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[2] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[2] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[2] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 2;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[2] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot2 == 0)
			{
				if (Vdeck[3].color[3] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[3] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[3] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 3;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[3] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[4] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[4] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[4] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 4;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[4] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[5] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[5] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[5] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 5;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[5] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				if (Vdeck[3].color[6] == Vdeck[randPC].color[randNC] || Vdeck[3].numcard[6] == Vdeck[randPC].numcard[randNC])
				{
					if (clickflagbot3[6] == 0)
					{
						cardmid_aux = cardmid;
						cardmid = Vdeck[3];
						randNC_aux = randNC;
						randPC_aux = randPC;
						randNC = 6;
						randPC = 3;
						turn++;
						Vdeck[3].qcard = Vdeck[3].qcard - 1;
						clickflagbot3[6] = 1;
						cardflagbot3 = 1;
						printf("Turno de bot 3\n");
						cardStart = 1;
					}
				}
			}
			if (cardflagbot3 == 0)
			{
				turn++;
			}
		}
		cardflag = 0;
		cardflagbot1 = 0;
		cardflagbot2 = 0;
		cardflagbot3 = 0;
		turn = 0;



		if (playerDeck.qcard == 0 || Vdeck[1].qcard == 0 || Vdeck[2].qcard == 0 || Vdeck[3].qcard == 0)
		{
			int menu;
			menu = gameover(evento, queue);
			if (menu == 1)
			{
				return 1;
			}
		}

		al_flip_display();
	}
}


int genDeck(int difficulty)
{
	int i, j, colorRand, numCard;

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
			
			Vdeck[i].color[j] = colorRand;

			// Color verde
			if (colorRand == 1)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png"); // Nombre de la imagen de la carta verde con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png"); // Nombre de la imagen de la carta verde con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png"); // Nombre de la imagen de la carta verde con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png"); // Nombre de la imagen de la carta verde con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png"); // Nombre de la imagen de la carta verde con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png"); // Nombre de la imagen de la carta verde con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png"); // Nombre de la imagen de la carta verde con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png"); // Nombre de la imagen de la carta verde con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png"); // Nombre de la imagen de la carta verde con numero 9
					Vdeck[i].numcard[j] = 9;
				}

			}		//Color rojo
			else if (colorRand == 2)
			{

				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png"); // Nombre de la imagen de la carta rojo con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png"); // Nombre de la imagen de la carta rojo con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png"); // Nombre de la imagen de la carta rojo con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png"); // Nombre de la imagen de la carta rojo con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png"); // Nombre de la imagen de la carta rojo con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png"); // Nombre de la imagen de la carta rojo con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png"); // Nombre de la imagen de la carta rojo con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png"); // Nombre de la imagen de la carta rojo con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png"); // Nombre de la imagen de la carta rojo con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color amarillo
			else if (colorRand == 3)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png"); // Nombre de la imagen de la carta amarillo con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png"); // Nombre de la imagen de la carta amarillo con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png"); // Nombre de la imagen de la carta amarillo con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png"); // Nombre de la imagen de la carta amarillo con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png"); // Nombre de la imagen de la carta amarillo con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png"); // Nombre de la imagen de la carta amarillo con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png"); // Nombre de la imagen de la carta amarillo con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png"); // Nombre de la imagen de la carta amarillo con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png"); // Nombre de la imagen de la carta amarillo con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color azul
			else if (colorRand == 4 && difficulty != 1)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_1.png"); // Nombre de la imagen de la carta azul con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_2.png"); // Nombre de la imagen de la carta azul con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_3.png"); // Nombre de la imagen de la carta azul con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_4.png"); // Nombre de la imagen de la carta azul con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_5.png"); // Nombre de la imagen de la carta azul con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_6.png"); // Nombre de la imagen de la carta azul con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_7.png"); // Nombre de la imagen de la carta azul con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_8.png"); // Nombre de la imagen de la carta azul con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Azules/Az_Num_9.png"); // Nombre de la imagen de la carta azul con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}		//Color negro (Exponeciales)
			else if (colorRand == 5 && difficulty == 3)
			{
				numCard = rand() % 9 + 1;
				if (numCard == 1)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_1.png"); // Nombre de la imagen de la carta negro con numero 1
					Vdeck[i].numcard[j] = 1;
				}
				else if (numCard == 2)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_2.png"); // Nombre de la imagen de la carta negro con numero 2
					Vdeck[i].numcard[j] = 2;
				}
				else if (numCard == 3)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_3.png"); // Nombre de la imagen de la carta negro con numero 3
					Vdeck[i].numcard[j] = 3;
				}
				else if (numCard == 4)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_4.png"); // Nombre de la imagen de la carta negro con numero 4
					Vdeck[i].numcard[j] = 4;
				}
				else if (numCard == 5)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_5.png"); // Nombre de la imagen de la carta negro con numero 5
					Vdeck[i].numcard[j] = 5;
				}
				else if (numCard == 6)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_6.png"); // Nombre de la imagen de la carta negro con numero 6
					Vdeck[i].numcard[j] = 6;
				}
				else if (numCard == 7)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_7.png"); // Nombre de la imagen de la carta negro con numero 7
					Vdeck[i].numcard[j] = 7;
				}
				else if (numCard == 8)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_8.png"); // Nombre de la imagen de la carta negro con numero 8
					Vdeck[i].numcard[j] = 8;
				}
				else if (numCard == 9)
				{
					Vdeck[i].card[j] = al_load_bitmap("Cartas_Negras/Ne_Num_9.png"); // Nombre de la imagen de la carta negro con numero 9
					Vdeck[i].numcard[j] = 9;
				}
			}
		}
	}

	return 1;
}

int gameover(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE *queue)
{
	printf("Se a acabado el juego!");
	int x = -1, y = -1;
	ALLEGRO_FONT* mine_font = al_load_font("Minecraftia-Regular.ttf", 50, NULL);

	while (true)
	{

		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
		}
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "Menu");

		if (x >= 640 && x <= 804 && y >= 305 && y <= 405)
		{
			if (evento.mouse.button & 1)
			{
				return 1;
			}
		}
		al_flip_display();

	}
}

ALLEGRO_BITMAP *load_cardmid(int color, int numCard)
{
	
	if (color == 1)
	{
		if (numCard == 1)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_1.png"); // Nombre de la imagen de la carta verde con numero 1
			return cardmid_loaded;
		}
		else if (numCard == 2)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_2.png"); // Nombre de la imagen de la carta verde con numero 2
			return cardmid_loaded;
		}
		else if (numCard == 3)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_3.png"); // Nombre de la imagen de la carta verde con numero 3
			return cardmid_loaded;
		}
		else if (numCard == 4)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_4.png"); // Nombre de la imagen de la carta verde con numero 4
			return cardmid_loaded;
		}
		else if (numCard == 5)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_5.png"); // Nombre de la imagen de la carta verde con numero 5
			return cardmid_loaded;
		}
		else if (numCard == 6)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_6.png"); // Nombre de la imagen de la carta verde con numero 6
			return cardmid_loaded;
		}
		else if (numCard == 7)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_7.png"); // Nombre de la imagen de la carta verde con numero 7
			return cardmid_loaded;
		}
		else if (numCard == 8)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_8.png"); // Nombre de la imagen de la carta verde con numero 8
			return cardmid_loaded;
		}
		else if (numCard == 9)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Verdes/Ve_Num_9.png"); // Nombre de la imagen de la carta verde con numero 9
			return cardmid_loaded;
		}

	}
	else if (color == 2)
	{

		if (numCard == 1)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_1.png"); // Nombre de la imagen de la carta rojo con numero 1
			return cardmid_loaded;
		}
		else if (numCard == 2)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_2.png"); // Nombre de la imagen de la carta rojo con numero 2
			return cardmid_loaded;
		}
		else if (numCard == 3)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_3.png"); // Nombre de la imagen de la carta rojo con numero 3
			return cardmid_loaded;
		}
		else if (numCard == 4)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_4.png"); // Nombre de la imagen de la carta rojo con numero 4
			return cardmid_loaded;
		}
		else if (numCard == 5)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_5.png"); // Nombre de la imagen de la carta rojo con numero 5
			return cardmid_loaded;
		}
		else if (numCard == 6)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_6.png"); // Nombre de la imagen de la carta rojo con numero 6
			return cardmid_loaded;
		}
		else if (numCard == 7)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_7.png"); // Nombre de la imagen de la carta rojo con numero 7
			return cardmid_loaded;
		}
		else if (numCard == 8)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_8.png"); // Nombre de la imagen de la carta rojo con numero 8
			return cardmid_loaded;
		}
		else if (numCard == 9)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Rojas/Ro_Num_9.png"); // Nombre de la imagen de la carta rojo con numero 9
			return cardmid_loaded;
		}
	}
	else if (color == 3)
	{
		if (numCard == 1)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_1.png"); // Nombre de la imagen de la carta amarillo con numero 1
			return cardmid_loaded;
		}
		else if (numCard == 2)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_2.png"); // Nombre de la imagen de la carta amarillo con numero 2
			return cardmid_loaded;
		}
		else if (numCard == 3)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_3.png"); // Nombre de la imagen de la carta amarillo con numero 3
			return cardmid_loaded;
		}
		else if (numCard == 4)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_4.png"); // Nombre de la imagen de la carta amarillo con numero 4
			return cardmid_loaded;
		}
		else if (numCard == 5)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_5.png"); // Nombre de la imagen de la carta amarillo con numero 5
			return cardmid_loaded;
		}
		else if (numCard == 6)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_6.png"); // Nombre de la imagen de la carta amarillo con numero 6
			return cardmid_loaded;
		}
		else if (numCard == 7)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_7.png"); // Nombre de la imagen de la carta amarillo con numero 7
			return cardmid_loaded;
		}
		else if (numCard == 8)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_8.png"); // Nombre de la imagen de la carta amarillo con numero 8
			return cardmid_loaded;
		}
		else if (numCard == 9)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Amarillas/Am_Num_9.png"); // Nombre de la imagen de la carta amarillo con numero 9
			return cardmid_loaded;
		}

	}
	else if (color == 4)
	{
		if (numCard == 1)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_1.png"); // Nombre de la imagen de la carta azul con numero 1
			return cardmid_loaded;
		}
		else if (numCard == 2)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_2.png"); // Nombre de la imagen de la carta azul con numero 2
			return cardmid_loaded;
		}
		else if (numCard == 3)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_3.png"); // Nombre de la imagen de la carta azul con numero 3
			return cardmid_loaded;
		}
		else if (numCard == 4)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_4.png"); // Nombre de la imagen de la carta azul con numero 4
			return cardmid_loaded;
		}
		else if (numCard == 5)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_5.png"); // Nombre de la imagen de la carta azul con numero 5
			return cardmid_loaded;
		}
		else if (numCard == 6)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_6.png"); // Nombre de la imagen de la carta azul con numero 6
			return cardmid_loaded;
		}
		else if (numCard == 7)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_7.png"); // Nombre de la imagen de la carta azul con numero 7
			return cardmid_loaded;
		}
		else if (numCard == 8)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_8.png"); // Nombre de la imagen de la carta azul con numero 8
			return cardmid_loaded;
		}
		else if (numCard == 9)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Azules/Az_Num_9.png"); // Nombre de la imagen de la carta azul con numero 9
			return cardmid_loaded;
		}
	}
	else if (color == 5)
	{
		if (numCard == 1)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_1.png"); // Nombre de la imagen de la carta negro con numero 1
			return cardmid_loaded;
		}
		else if (numCard == 2)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_2.png"); // Nombre de la imagen de la carta negro con numero 2
			return cardmid_loaded;
		}
		else if (numCard == 3)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_3.png"); // Nombre de la imagen de la carta negro con numero 3
			return cardmid_loaded;
		}
		else if (numCard == 4)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_4.png"); // Nombre de la imagen de la carta negro con numero 4
			return cardmid_loaded;
		}
		else if (numCard == 5)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_5.png"); // Nombre de la imagen de la carta negro con numero 5
			return cardmid_loaded;
		}
		else if (numCard == 6)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_6.png"); // Nombre de la imagen de la carta negro con numero 6
			return cardmid_loaded;
		}
		else if (numCard == 7)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_7.png"); // Nombre de la imagen de la carta negro con numero 7
			return cardmid_loaded;
		}
		else if (numCard == 8)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_8.png"); // Nombre de la imagen de la carta negro con numero 8
			return cardmid_loaded;
		}
		else if (numCard == 9)
		{
			ALLEGRO_BITMAP* cardmid_loaded = al_load_bitmap("Cartas_Negras/Ne_Num_9.png"); // Nombre de la imagen de la carta negro con numero 9
			return cardmid_loaded;

		}
	}

}

int cardOp(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, int numcard1, int color1, int numcard2, int color2, int pobturn)
{

	int randOp = rand() % 3;
	int x = -1, y = -1, i;
	int ans[3] = { 1000,1000,1000 };
	int randAns = rand() % 3;
	ans[randAns] = ansOp(numcard1, numcard2, color2, randOp);

	for (i = 0; i < 3; i++)
	{
		if (ans[i] == 1000)
		{
			ans[i] = rand() % 81 + 1;
		}
	}

	int randbotAns = rand() % 3;
	ALLEGRO_BITMAP* card1 = load_cardmid(color1, numcard1);
	ALLEGRO_BITMAP* card2 = load_cardmid(color2, numcard2);
	ALLEGRO_BITMAP* bg = al_load_bitmap("menu_op.jpg");

	ALLEGRO_FONT* mine_font = al_load_font("Minecraftia-Regular.ttf", 50, NULL);

	while (true)
	{

		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			printf("x: %d y: %d\n", x, y);
			x = evento.mouse.x;
			y = evento.mouse.y;
		}

		al_draw_bitmap(bg, 0, 0, 0);
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 240, 560, ALLEGRO_ALIGN_CENTER, std::to_string(ans[0]).c_str());
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 660, 560, ALLEGRO_ALIGN_CENTER, std::to_string(ans[1]).c_str());
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 1050, 560, ALLEGRO_ALIGN_CENTER, std::to_string(ans[2]).c_str());

		if (color2 == 1)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "+");
		}
		else if (color2 == 2)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "-");
		}
		else if (color2 == 3)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "*");
		}
		else if (color2 == 4)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "/");
		}
		else if (color2 == 5)
		{
			if (randOp == 0)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 480, 250, ALLEGRO_ALIGN_CENTER, "+");
			}
			else if (randOp == 1)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 480, 250, ALLEGRO_ALIGN_CENTER, "-");
			}
			else if (randOp == 2)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 480, 250, ALLEGRO_ALIGN_CENTER, "*");
			}
		}

		al_draw_bitmap(card1, 360, 250, 0);
		al_draw_bitmap(card2, 810, 250, 0);

		if (pobturn == 1)
		{
			al_draw_text(mine_font, al_map_rgb(250, 250, 250), 515, 145, NULL, "Tu turno!");
			if (x >= 94 && x <= 390 && y >= 533 && y <= 650)
			{
				if (evento.mouse.button & 1)
				{
					if (randAns == 0)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return 1;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return 0;
					}

				}
			}

			if (x >= 510 && x <= 804 && y >= 530 && y <= 645)
			{
				if (evento.mouse.button & 1)
				{
					if (randAns == 1)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return 1;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return 0;
					}
				}
			}

			if (x >= 900 && x <= 1195 && y >= 525 && y <= 645)
			{
				if (evento.mouse.button & 1)
				{
					if (randAns == 2)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return 1;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return 0;
					}
				}
			}
		}
		else
		{
			al_draw_text(mine_font, al_map_rgb(250, 250, 250), 515, 145, NULL, "Turno del bot!");
			int randChbot = rand() % 3;
			if (randChbot == randAns)
			{
				return 1;
			}
			else
			{
				return 0;
			}
			
		}

		al_flip_display();

	}
}

int ansOp(int numcard1, int numcard2, int color2, int randOp)
{
	int ans;
	if (color2 == 1)
	{
		ans = numcard1 + numcard2;
		return ans;
	}
	else if (color2 == 2)
	{
		ans = numcard1 - numcard2;
		return ans;
	}
	else if (color2 == 3)
	{
		ans = numcard1 * numcard2;
		return ans;
	}
	else if (color2 == 4)
	{
		ans = numcard1 / numcard2;
		return ans;
	}
	else if (color2 == 5)
	{
		if (randOp == 0)
		{
			ans = numcard1 + pow(numcard2, 2);
			return ans;
		}
		else if (randOp == 1)
		{
			ans = numcard1 - pow(numcard2, 2);
			return ans;
		}
		else if (randOp == 2)
		{
			ans = numcard1 * pow(numcard2, 2);
			return ans;
		}
	}
}
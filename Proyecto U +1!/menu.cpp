#include "menu.h"
#include "Jugador.h"
#include "deck.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>


using std::cout;
using std::endl;

menu::menu()
{

}

int menu::initMenu(int ancho, int alto)
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR", "ERROR 404", "El programa no pudo cargar correctamente", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	}
	ALLEGRO_DISPLAY* main = al_create_display(ancho, alto);
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_set_window_position(main, ancho_w / 2 - ancho / 2, alto_w / 2 - alto / 2);
	al_set_window_title(main, "UNO + 1!");

	//Codigo para cargar imagenes
	al_init_image_addon();
	ALLEGRO_BITMAP* menu0 = al_load_bitmap("Menus/Main/Main_menu0.jpg");
	ALLEGRO_BITMAP* menu1 = al_load_bitmap("Menus/Main/Main_menu1.jpg");
	ALLEGRO_BITMAP* menu2 = al_load_bitmap("Menus/Main/Main_menu2.jpg");
	ALLEGRO_BITMAP* menu3 = al_load_bitmap("Menus/Main/Main_menu3.jpg");

	ALLEGRO_BITMAP* diff_menu0 = al_load_bitmap("Menus/Diff/Diff_menu0.jpg");
	ALLEGRO_BITMAP* diff_menu1 = al_load_bitmap("Menus/Diff/Diff_menu1.jpg");
	ALLEGRO_BITMAP* diff_menu2 = al_load_bitmap("Menus/Diff/Diff_menu2.jpg");
	ALLEGRO_BITMAP* diff_menu3 = al_load_bitmap("Menus/Diff/Diff_menu3.jpg");

	ALLEGRO_BITMAP* background = al_load_bitmap("fondo_rojo.jpg");



	ALLEGRO_TIMER* segTimer = al_create_timer(1.0);
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(segTimer));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_start_timer(segTimer);

	while (true)
	{
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			if (evento.timer.source == segTimer)
			{
				seg++;
			}
		}
		//Las capas aqui funcionan en orden ascendente
		al_draw_bitmap(menu0, 0, 0, 0);		//Esta es la capa 1, la parte de hasta abajo (esta funcion carga la imagen en la pantalla)

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
			cout << "x: " << x << "y: " << y << endl;
			//Boton jugar
			if (x >= 491 && x <= 800 && y >= 345 && y <= 437)
			{
				btn[0] = 1;
				// Click del mouse (& 1 para el boton izquierdo, & 2 para el boton derecho y & 4 para la rueda)
				if (evento.mouse.button & 1)
				{
					cout << "x: " << x << "y: " << y << endl;
					difficulty = diffmenu(evento, queue, diff_menu0, diff_menu1, diff_menu2, diff_menu3); //Aca entrará a la funcion para jugar
					game(evento, queue, background, difficulty);
				}
				else
				{
					btn[0] = 0;
				}
			}

			//Boton opciones
			if (x >= 180 && x <= 390 && y >= 326 && y <= 405)
			{
				btn[1] = 1;
				if (evento.mouse.button & 1)
				{
					//Aca entrará a la funcion para las opciones
					cout << "x: " << x << "y: " << y << endl;
				}
				else
				{
					btn[1] = 0;
				}
			}

			//Boton salir
			if (x >= 491 && x <= 800 && y >= 564 && y <= 657)
			{
				btn[2] = 1;
				if (evento.mouse.button & 1)
				{
					//Aca saldra del juego
					cout << "x: " << x << "y: " << y << endl;
					exit(1);
				}
				else
				{
					btn[2] = 0;
				}
			}
		}


		if (x >= 491 && x <= 800 && y >= 345 && y <= 437)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu1, 0, 0, 0);	 //Aqui ira el menu donde se resaltara el boton "Jugar"
		}
		else if (x >= 491 && x <= 800 && y >= 455 && y <= 547)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu2, 0, 0, 0); //Aqui ira el menu donde se resaltara el boton "Opciones"
		}
		else if (x >= 491 && x <= 800 && y >= 564 && y <= 657)
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu3, 0, 0, 0);; //Aqui ira el menu donde se resaltara el boton "Salir"
		}
		else
		{							//Cordenadas (x1,y1) y (x2,y2)
			al_draw_bitmap(menu0, 0, 0, 0);; //Aqui ira el main menu
		}


		al_flip_display();

	}
}

int menu::diffmenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* menu_null, ALLEGRO_BITMAP* menu_0, ALLEGRO_BITMAP* menu_1, ALLEGRO_BITMAP* menu_2)
{
	int x = -1, y = -1;
	ALLEGRO_COLOR negro = al_map_rgb(0, 0, 0);
	while (true)
	{
		al_wait_for_event(queue, &evento);
		al_draw_bitmap(menu_null, 0, 0, 0);


		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
			cout << "x: " << x << "y: " << y << endl;
			if (x >= 74 && x <= 382 && y >= 435 && y <= 527)
			{
				if (evento.mouse.button & 1)
				{
					cout << "x: " << x << "y: " << y << endl;
					return 1;
				}
			}

			if (x >= 500 && x <= 809 && y >= 435 && y <= 527)
			{
				if (evento.mouse.button & 1)
				{
					cout << "x: " << x << "y: " << y << endl;
					return 2;
				}
			}

			if (x >= 905 && x <= 1214 && y >= 435 && y <= 527)
			{
				if (evento.mouse.button & 1)
				{
					cout << "x: " << x << "y: " << y << endl;
					return 3;
				}
			}

		}

		if (x >= 74 && x <= 382 && y >= 435 && y <= 527)
		{
			al_draw_bitmap(menu_0, 0, 0, 0);
		}
		else if (x >= 500 && x <= 809 && y >= 435 && y <= 527)
		{
			al_draw_bitmap(menu_1, 0, 0, 0);
		}
		else if (x >= 905 && x <= 1214 && y >= 435 && y <= 527)
		{
			al_draw_bitmap(menu_2, 0, 0, 0);
		}
		else
		{
			al_draw_bitmap(menu_null, 0, 0, 0);
		}
		
		al_flip_display();
	}

}



int menu::game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	Jugador::GetJugador1().Pdeck->genDeck(difficulty);
	srand(time(NULL));
	int colorRand, numCard;
	
	int ans = 2, ansbot1 = 2, ansbot2 = 2, ansbot3 = 2;
	int x = -1, y = -1;
	int randPC, randNC, randPC_aux, randNC_aux;
	int btn[7] = { 0,0,0,0,0,0,0 };
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

	//Carga de bitmaps
	ALLEGRO_BITMAP* cardmid_draw[25];
	ALLEGRO_BITMAP* engr = al_load_bitmap("Menus/engranaje.png");
	ALLEGRO_BITMAP* backcard = al_load_bitmap("Cartas_Reverso/Carta_Atras.png");
	ALLEGRO_BITMAP* revder = al_load_bitmap("Cartas_Reverso/Carta_Atras_Botder.png");
	ALLEGRO_BITMAP* revizq = al_load_bitmap("Cartas_Reverso/Carta_Atras_Botizq.png");
	ALLEGRO_BITMAP* revrev = al_load_bitmap("Cartas_Reverso/Carta_Atras_Botrev.png");
	ALLEGRO_BITMAP* passCard = al_load_bitmap("Menus/passCard.png");

	//inicializacion del color y el numero de carta aleatorio para llamar a la funcion para generar
	//la carta del medio de tablero
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

	ALLEGRO_BITMAP* midcard = Jugador::GetJugador1().Pdeck->genCard(difficulty, colorRand, numCard);

	deck* cardmidDeck = new deck;

	cardmidDeck->color.push_back(colorRand);
	cardmidDeck->numcard.push_back(numCard);
	cardmidDeck->deckcards.push_back(midcard);

	while (true)
	{

		al_wait_for_event(queue, &evento);
		al_draw_bitmap(bg, 0, 0, 0);

		//Cargar la primera carta del medio del tablero con la clase "deck"
		al_draw_bitmap(cardmidDeck->deckcards[0], 580, 260, 0);

		//Dibuja los reversos de las cartas
		int i, j, x, y;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 7; j++)
			{
				if (i == 0)
				{
					x = 0, y = 110;
					al_draw_bitmap(revder, x, y, 0);
					y += 60;
				}
				else if (i == 1)
				{
					x = 1200, y = 110;
					al_draw_bitmap(revizq, x, y, 0);
					y += 60;
				}
				else if (i == 2)
				{
					x = 420, y = 0;
					al_draw_bitmap(revrev, x, y, 0);
					x += 60;
				}
			}
		}
		
		//Dibuja las cartas del jugador
		i = 0, x = 100, y = 535;
		for (auto crd : Jugador::GetJugador1().Pdeck->deckcards)
		{
			if (clickflag[i] == 0)
			{
				al_draw_bitmap(crd, x, y, 0);
				i++;
				x += 140;
			}
			// Y, en tal caso que haya usado esa carta, se pondra el reverso de la carta y se
			//deshablilitara su uso
			else
				al_draw_bitmap(backcard, x, y, 0);

		}

		//Dibuja obejtos del menu para las opciones y para pasar de turno
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
				ans = 1;
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
				ansbot1 = 1;
			}

			if (ansbot1 == 0)
			{
				cardflagbot1 = 1;
				turn++;
			}

			Sleep(500);
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
				ansbot2 = 1;
			}

			if (ansbot2 == 0)
			{
				cardflagbot2 = 1;
				turn++;
			}
			Sleep(500);
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
				ansbot3 = 1;

			}

			if (ansbot3 == 0)
			{
				cardflagbot3 = 1;
				turn++;
			}

			Sleep(500);
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
			menu = gameover(evento, queue, playerDeck.qcard);
			if (menu == 1)
			{
				return 1;
			}
		}

		al_flip_display();
	}
}

int menu::OpMenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, deck midcard)
{
	while (true)
	{
		al_wait_for_event(queue, &evento);
		al_draw_bitmap(bg, 0, 0, 0);

		al_draw_bitmap(midcard.deckcards[0], 0, 0, 0);

	}
	return 0;
}

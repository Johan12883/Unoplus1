#include "menu.h"
#include "Jugador.h"
#include "deck.h"
#include "Card.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <Windows.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>


using std::cout;
using std::endl;
using std::to_string;
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
		}
		al_flip_display();
	}

}



int menu::game(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, ALLEGRO_BITMAP* bg, int difficulty)
{
	Jugador::GetJugador1().Pdeck = Jugador::GetJugador1().Pdeck->genDeck(difficulty);
	Jugador::GetJugador2().Pdeck = Jugador::GetJugador1().Pdeck->genDeck(difficulty);
	Jugador::GetJugador3().Pdeck = Jugador::GetJugador1().Pdeck->genDeck(difficulty);
	Jugador::GetJugador4().Pdeck = Jugador::GetJugador1().Pdeck->genDeck(difficulty);
	srand(time(NULL));
	int colorRand, numCard;
	bool StartGame = true;

	int x = -1, y = -1;


	//Carga de bitmaps
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

	Card* prevcard = new Card;
	Card* cardmid = new Card(colorRand, numCard);
	cardmid->asset_card = cardmid->genCard(difficulty, colorRand, numCard);
	while (true)
	{

		al_wait_for_event(queue, &evento);
		al_draw_bitmap(bg, 0, 0, 0);

		//Cargar la primera carta del medio del tablero con la clase "deck"
		al_draw_bitmap(cardmid->asset_card, 580, 260, 0);

		//Dibuja los reversos de las cartas
		int i, j, xB = -1, yB = -1;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 7; j++)
			{
				if (i == 0)
				{
					if (j == 0)
						yB = 110;
					x = 0;
					al_draw_bitmap(revder, xB, yB, 0);
					yB += 60;
				}
				else if (i == 1)
				{
					if (j == 0)
						yB = 110;
					xB = 1200;
					al_draw_bitmap(revizq, xB, yB, 0);
					yB += 60;
				}
				else if (i == 2)
				{
					if (j == 0)
						xB = 420;
					yB = 0;
					al_draw_bitmap(revrev, xB, yB, 0);
					xB += 60;
				}
			}
		}
		
		//Dibuja las cartas del jugador
		int xP = 100, yP = 535;
		for (i = 0; i < 6; i++)
		{
			if (Jugador::GetJugador1().Pdeck->CardsFlags[i] == true)
			{
				al_draw_bitmap(Jugador::GetJugador1().Pdeck->deckcards.at(i)->asset_card, xP, yP, 0);
				xP += 140;
			}
			// Y, en tal caso que haya usado esa carta, se pondra el reverso de la carta y se
			//deshablilitara su uso
			else
				al_draw_bitmap(backcard, xP, yP, 0);

		}

		//Dibuja obejtos del menu para las opciones y para pasar de turno
		al_draw_bitmap(passCard, 980, 475, 0);
		al_draw_bitmap(engr, 1230, 0, 0);

		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;

			cout << "x: " << x << " y: " << y << endl;

			Jugador::GetJugador1().turn = true;
			if (Jugador::GetJugador1().turn == true)
			{
				if (StartGame == false && Jugador::GetJugador1().AnsweredBool == false)
				{
					Jugador::GetJugador1().AnsweredBool = OpMenu(evento, queue, cardmid, prevcard);
				}

				if (Jugador::GetJugador1().AnsweredBool == false)
				{
					Jugador::GetJugador1().turn = false;
				}

				if (x >= 980 && x <= 1028 && y >= 475 && y <= 515)
				{
					if (evento.mouse.button & 1)
					{
						Jugador::GetJugador1().turn = false;
						Jugador::GetJugador1().AnsweredBool = false;
						printf("A saltado turno!\n");
					}
				}

				if (Jugador::GetJugador1().turn == true)
				{
					if (Jugador::GetJugador1().Pdeck->CardsFlags[0] == true)
					{
						//Boton carta 1
						if (x >= 100 && x <= 225 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(0)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(0)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(0);
									Jugador::GetJugador1().Pdeck->CardsFlags[0] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;

								}
							}
						}
					}



					if (Jugador::GetJugador1().Pdeck->CardsFlags[1] == true)
					{
						//Boton carta 2
						if (x >= 240 && x <= 365 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(1)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(1)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(1);
									Jugador::GetJugador1().Pdeck->CardsFlags[1] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}
						}
					}


					if (Jugador::GetJugador1().Pdeck->CardsFlags[2] == true)
					{
						//Boton carta 3
						if (x >= 380 && x <= 505 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(2)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(2)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(2);
									Jugador::GetJugador1().Pdeck->CardsFlags[2] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}
						}
					}

					if (Jugador::GetJugador1().Pdeck->CardsFlags[3] == true)
					{
						//Boton carta 4
						if (x >= 520 && x <= 645 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(3)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(3)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(3);
									Jugador::GetJugador1().Pdeck->CardsFlags[3] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}
						}
					}

					if (Jugador::GetJugador1().Pdeck->CardsFlags[4] == true)
					{
						//Boton carta 5
						if (x >= 660 && x <= 785 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(4)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(4)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(4);
									Jugador::GetJugador1().Pdeck->CardsFlags[4] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}

						}
					}

					if (Jugador::GetJugador1().Pdeck->CardsFlags[5] == true)
					{
						//Boton carta 6
						if (x >= 800 && x <= 925 && y >= 535 && y <= 710)
						{
							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(5)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(5)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(5);
									Jugador::GetJugador1().Pdeck->CardsFlags[5] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}

						}
					}


					if (Jugador::GetJugador1().Pdeck->CardsFlags[6] == true)
					{
						//Boton carta 7
						if (x >= 940 && x <= 1065 && y >= 535 && y <= 710)
						{

							if (evento.mouse.button & 1)
							{
								if (Jugador::GetJugador1().Pdeck->deckcards.at(6)->color == cardmid->color || Jugador::GetJugador1().Pdeck->deckcards.at(6)->numcard == cardmid->numcard)
								{
									//midcard en la funcion de OpMenu
									prevcard = cardmid;
									//ChoosenCard en la funcion OpMenu
									cardmid = Jugador::GetJugador1().Pdeck->deckcards.at(6);
									Jugador::GetJugador1().Pdeck->CardsFlags[6] = false;
									Jugador::GetJugador1().turn = false;
									Jugador::GetJugador1().Pdeck->CardsLeft = Jugador::GetJugador1().Pdeck->CardsLeft - 1;
									Jugador::GetJugador1().AnsweredBool = false;
									if (StartGame == true)
										StartGame = false;
								}
							}
						}
					}
				}
			}

			Jugador::GetJugador2().turn = true;
			if (Jugador::GetJugador2().turn == true)
			{
				if (StartGame == false && Jugador::GetJugador2().AnsweredBool == false)
				{
					Jugador::GetJugador2().AnsweredBool = OpMenu(evento, queue, cardmid, prevcard);
				}

				if (Jugador::GetJugador2().AnsweredBool == false)
				{
					Jugador::GetJugador2().turn = false;
				}

				Sleep(500);
				if (Jugador::GetJugador2().turn == true)
				{
					if (Jugador::GetJugador2().Pdeck->CardsFlags[0] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(0)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(0)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(0);
							Jugador::GetJugador2().Pdeck->CardsFlags[0] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}



					if (Jugador::GetJugador2().Pdeck->CardsFlags[1] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(1)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(1)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(1);
							Jugador::GetJugador2().Pdeck->CardsFlags[1] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}


					if (Jugador::GetJugador2().Pdeck->CardsFlags[2] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(2)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(2)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(2);
							Jugador::GetJugador2().Pdeck->CardsFlags[2] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador2().Pdeck->CardsFlags[3] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(3)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(3)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(3);
							Jugador::GetJugador2().Pdeck->CardsFlags[3] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador2().Pdeck->CardsFlags[4] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(4)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(4)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(4);
							Jugador::GetJugador2().Pdeck->CardsFlags[4] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador2().Pdeck->CardsFlags[5] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(5)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(5)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(5);
							Jugador::GetJugador2().Pdeck->CardsFlags[5] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}


					if (Jugador::GetJugador2().Pdeck->CardsFlags[6] == true)
					{
						if (Jugador::GetJugador2().Pdeck->deckcards.at(6)->color == cardmid->color || Jugador::GetJugador2().Pdeck->deckcards.at(6)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador2().Pdeck->deckcards.at(6);
							Jugador::GetJugador2().Pdeck->CardsFlags[6] = false;
							Jugador::GetJugador2().turn = false;
							Jugador::GetJugador2().Pdeck->CardsLeft = Jugador::GetJugador2().Pdeck->CardsLeft - 1;
							Jugador::GetJugador2().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}
				}
			}

			if (Jugador::GetJugador2().turn == true && Jugador::GetJugador2().AnsweredBool == true)
			{
				Jugador::GetJugador2().turn = false;
				Jugador::GetJugador2().AnsweredBool = false;
			}

			Jugador::GetJugador3().turn = true;
			if (Jugador::GetJugador3().turn == true)
			{
				if (StartGame == false && Jugador::GetJugador3().AnsweredBool == false)
				{
					Jugador::GetJugador3().AnsweredBool = OpMenu(evento, queue, cardmid, prevcard);
				}

				if (Jugador::GetJugador3().AnsweredBool == false)
				{
					Jugador::GetJugador3().turn = false;
				}

				Sleep(500);
				if (Jugador::GetJugador3().turn == true)
				{
					if (Jugador::GetJugador3().Pdeck->CardsFlags[0] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(0)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(0)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(0);
							Jugador::GetJugador3().Pdeck->CardsFlags[0] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}



					if (Jugador::GetJugador3().Pdeck->CardsFlags[1] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(1)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(1)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(1);
							Jugador::GetJugador3().Pdeck->CardsFlags[1] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}


					if (Jugador::GetJugador3().Pdeck->CardsFlags[2] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(2)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(2)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(2);
							Jugador::GetJugador3().Pdeck->CardsFlags[2] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador3().Pdeck->CardsFlags[3] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(3)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(3)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(3);
							Jugador::GetJugador3().Pdeck->CardsFlags[3] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador3().Pdeck->CardsFlags[4] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(4)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(4)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(4);
							Jugador::GetJugador3().Pdeck->CardsFlags[4] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}

					if (Jugador::GetJugador3().Pdeck->CardsFlags[5] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(5)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(5)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(5);
							Jugador::GetJugador3().Pdeck->CardsFlags[5] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}


					if (Jugador::GetJugador3().Pdeck->CardsFlags[6] == true)
					{
						if (Jugador::GetJugador3().Pdeck->deckcards.at(6)->color == cardmid->color || Jugador::GetJugador3().Pdeck->deckcards.at(6)->numcard == cardmid->numcard)
						{
							//midcard en la funcion de OpMenu
							prevcard = cardmid;
							//ChoosenCard en la funcion OpMenu
							cardmid = Jugador::GetJugador3().Pdeck->deckcards.at(6);
							Jugador::GetJugador3().Pdeck->CardsFlags[6] = false;
							Jugador::GetJugador3().turn = false;
							Jugador::GetJugador3().Pdeck->CardsLeft = Jugador::GetJugador3().Pdeck->CardsLeft - 1;
							Jugador::GetJugador3().AnsweredBool = false;
							if (StartGame == true)
								StartGame = false;
						}
					}
				}
			}

			if (Jugador::GetJugador4().turn == true && Jugador::GetJugador4().AnsweredBool == true)
			{
				Jugador::GetJugador4().turn = false;
				Jugador::GetJugador4().AnsweredBool = false;
			}


			Sleep(500);
			if (Jugador::GetJugador4().turn == true)
			{
				if (Jugador::GetJugador4().Pdeck->CardsFlags[0] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(0)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(0)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(0);
						Jugador::GetJugador4().Pdeck->CardsFlags[0] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}



				if (Jugador::GetJugador4().Pdeck->CardsFlags[1] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(1)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(1)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(1);
						Jugador::GetJugador4().Pdeck->CardsFlags[1] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}


				if (Jugador::GetJugador4().Pdeck->CardsFlags[2] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(2)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(2)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(2);
						Jugador::GetJugador4().Pdeck->CardsFlags[2] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}

				if (Jugador::GetJugador4().Pdeck->CardsFlags[3] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(3)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(3)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(3);
						Jugador::GetJugador4().Pdeck->CardsFlags[3] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}

				if (Jugador::GetJugador4().Pdeck->CardsFlags[4] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(4)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(4)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(4);
						Jugador::GetJugador4().Pdeck->CardsFlags[4] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}

				if (Jugador::GetJugador4().Pdeck->CardsFlags[5] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(5)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(5)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(5);
						Jugador::GetJugador4().Pdeck->CardsFlags[5] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}


				if (Jugador::GetJugador4().Pdeck->CardsFlags[6] == true)
				{
					if (Jugador::GetJugador4().Pdeck->deckcards.at(6)->color == cardmid->color || Jugador::GetJugador4().Pdeck->deckcards.at(6)->numcard == cardmid->numcard)
					{
						//midcard en la funcion de OpMenu
						prevcard = cardmid;
						//ChoosenCard en la funcion OpMenu
						cardmid = Jugador::GetJugador4().Pdeck->deckcards.at(6);
						Jugador::GetJugador4().Pdeck->CardsFlags[6] = false;
						Jugador::GetJugador4().turn = false;
						Jugador::GetJugador4().Pdeck->CardsLeft = Jugador::GetJugador4().Pdeck->CardsLeft - 1;
						Jugador::GetJugador4().AnsweredBool = false;
						if (StartGame == true)
							StartGame = false;
					}
				}
			}
			if (Jugador::GetJugador4().turn == true && Jugador::GetJugador4().AnsweredBool == true)
			{
				Jugador::GetJugador4().turn = false;
				Jugador::GetJugador4().AnsweredBool = false;
			}
		}
		if (Jugador::GetJugador1().Pdeck->CardsLeft == 0 || Jugador::GetJugador2().Pdeck->CardsLeft == 0 || Jugador::GetJugador3().Pdeck->CardsLeft == 0 || Jugador::GetJugador4().Pdeck->CardsLeft == 0)
		{
			int menu;
			menu = GameOverMenu(evento, queue, Jugador::GetJugador1().Pdeck->CardsLeft);
			if (menu == 1)
			{
				return 1;
			}
		}

		al_flip_display();
	}
}

bool menu::OpMenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, Card* prevcard, Card* ChoosenCard)
{
	//RandPosOp sera la posicion en la que estara la opcion correcta y randOpPow sera la operacion de las cartas negras
	int i, randPosOp = rand() % 3, randOpPow = rand() % 3, Ans;
	Ans = Operaciones(prevcard, ChoosenCard, randOpPow);
	ALLEGRO_BITMAP* bg = al_load_bitmap("/Menus/OpMenu/menu_op.jpg");
	vector <int> Opciones;
	for (i = 0; i < 3; i++)
	{
		if (i == randPosOp)
		{
			Opciones.push_back(Ans);
		}
		else
			Opciones.push_back(rand() % 81 + 1);
	}



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

		//Operacion segun el color de la carta del medio
		if (prevcard->color == 1)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "+");
		}
		else if (prevcard->color == 2)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "-");
		}
		else if (prevcard->color == 3)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "*");
		}
		else if (prevcard->color == 4)
		{
			al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "/");
		}
		else if (prevcard->color == 5)
		{
			//Operacion aleatoria ya que las cartas son color negro, esto quiere decir que esa carta sera una exponencial.
			if (randOpPow == 0)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "+");
			}
			else if (randOpPow == 1)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "-");
			}
			else if (randOpPow == 2)
			{
				al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 305, ALLEGRO_ALIGN_CENTER, "*");
			}
		}


		al_draw_bitmap(bg, 0, 0, 0);

		al_draw_bitmap(prevcard->asset_card, 360, 250, 0);
		al_draw_bitmap(ChoosenCard->asset_card, 810, 250, 0);

		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 240, 560, ALLEGRO_ALIGN_CENTER, to_string(Opciones[0]).c_str());
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 660, 560, ALLEGRO_ALIGN_CENTER, to_string(Opciones[1]).c_str());
		al_draw_text(mine_font, al_map_rgb(0, 0, 0), 1050, 560, ALLEGRO_ALIGN_CENTER, to_string(Opciones[2]).c_str());
		
		if (Jugador::GetJugador1().turn == true)
		{
			al_draw_text(mine_font, al_map_rgb(250, 250, 250), 515, 145, NULL, "Tu turno!");
			if (x >= 94 && x <= 390 && y >= 533 && y <= 650)
			{
				if (evento.mouse.button & 1)
				{
					if (Opciones[0] == Ans)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return true;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return false;
					}

				}
			}

			if (x >= 510 && x <= 804 && y >= 530 && y <= 645)
			{
				if (evento.mouse.button & 1)
				{
					if (Opciones[1] == Ans)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return true;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return false;
					}
				}
			}

			if (x >= 900 && x <= 1195 && y >= 525 && y <= 645)
			{
				if (evento.mouse.button & 1)
				{
					if (Opciones[3] == Ans)
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Correcto!");
						Sleep(1000);
						return true;
					}
					else
					{
						al_draw_text(mine_font, al_map_rgb(0, 0, 0), 640, 405, NULL, "Incorrecto!");
						Sleep(1000);
						return false;
					}
				}
			}
		}
		else
		{
			al_draw_text(mine_font, al_map_rgb(250, 250, 250), 515, 145, NULL, "Turno del bot!");
			if (Opciones[rand() % 3] == Ans)
			{
				Sleep(1000);
				return true;
			}
			else
			{
				Sleep(1000);
				return false;
			}

		}
		
	}
}

int menu::Operaciones(Card* midcard, Card* ChoosenCard, int randOp)
{
	int ans;
	if (midcard->color == 1)
	{
		ans = midcard->numcard + ChoosenCard->numcard;
		return ans;
	}
	else if (midcard->color == 2)
	{
		ans = midcard->numcard - ChoosenCard->numcard;
		return ans;
	}
	else if (midcard->color == 3)
	{
		ans = midcard->numcard * ChoosenCard->numcard;
		return ans;
	}
	else if (midcard->color == 4)
	{
		ans = midcard->numcard / ChoosenCard->numcard;
		return ans;
	}
	else if (midcard->color == 5)
	{
		if (randOp == 0)
		{
			ans = pow(midcard->numcard, 2) + ChoosenCard->numcard;
			return ans;
		}
		else if (randOp == 1)
		{
			ans = pow(midcard->numcard, 2) - ChoosenCard->numcard;
			return ans;
		}
		else if (randOp == 2)
		{
			ans = pow(midcard->numcard, 2) * ChoosenCard->numcard;
			return ans;
		}
	}
}

int menu::GameOverMenu(ALLEGRO_EVENT evento, ALLEGRO_EVENT_QUEUE* queue, int qcards)
{
	printf("Se a acabado el juego!");
	int x = -1, y = -1;
	ALLEGRO_FONT* mine_font = al_load_font("Minecraftia-Regular.ttf", 50, NULL);
	ALLEGRO_BITMAP* gameover_null_win = al_load_bitmap("Menus/GameOverMenu/GameOverMenuWin0.jpg");
	ALLEGRO_BITMAP* gameover_play_win = al_load_bitmap("Menus/GameOverMenu/GameOverMenuWin1.jpg");
	ALLEGRO_BITMAP* gameover_menu_win = al_load_bitmap("Menus/GameOverMenu/GameOverMenuWin2.jpg");
	ALLEGRO_BITMAP* gameover_null_lose = al_load_bitmap("Menus/GameOverMenu/GameOverMenuLose0.jpg");
	ALLEGRO_BITMAP* gameover_play_lose = al_load_bitmap("Menus/GameOverMenu/GameOverMenuLose1.jpg");
	ALLEGRO_BITMAP* gameover_menu_lose = al_load_bitmap("Menus/GameOverMenu/GameOverMenuLose2.jpg");

	while (true)
	{
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_MOUSE_AXES || evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			//Posicion del mouse
			x = evento.mouse.x;
			y = evento.mouse.y;
		}

		if (qcards == 0)
		{
			al_draw_bitmap(gameover_null_win, 0, 0, 0);
			if (x >= 640 && x <= 804 && y >= 305 && y <= 405)
			{
				if (evento.mouse.button & 1)
				{
					return 1;
				}
			}
		}
		else
		{
			al_draw_bitmap(gameover_null_lose, 0, 0, 0);
			if (x >= 640 && x <= 804 && y >= 305 && y <= 405)
			{
				if (evento.mouse.button & 1)
				{
					return 1;
				}
			}
		}

		
		al_flip_display();
	}
}

#include <stdio.h>
#include <ctype.h>

#include "menu.h"

#define VERTICAL 7
#define KEYS 7
#define KEY_LEFT 0
#define KEY_RIGHT 1
#define KEY_CENTER 2
#define KEY_UP 3
#define KEY_DOWN 4
#define KEY_S1_BACK 5
#define KEY_S2_FORWARD 6

/* Control del menu */
int indexMenu;
int minMenu, maxMenu;
char * stringMenu [VERTICAL];
void (*functionMenu [VERTICAL]) ();

/* Control del teclat */
int key;
void (*functionKey [KEYS]) ();

/* Funcions que farem anar */
void confWelcom ();
void confFirstMenu ();
void confLEDMenu ();
void confMotorMenu ();
void confUARTMenu ();
void confDetectMenu ();



void empty () {}; // Aquest, opino que hauria d'estar en globals o algo aixi

void initMenu ()
{
	menuWhile = 1; /* per estar dins el bucle */
	confWelcom ();
	key = 0;
}

/* Si dona errors, podriem intentar fer un oldkey, aixi, no poder premer el mateix boto rapidament */
int menu ()
{
	key = getchar ();
	if ( isdigit ( key ) )
	{
/* o fer una variable auxiliar, o desactivar les interrupcions */
		functionKey [ key - '0' ] ();
		key = 0;
/* Si interrupcions, llavors ara tornar-les a activar */
	}
return 5; /* espera mitg segon */
}

void keyMenuUP ()
{
	printf ( "Normal: %s\n", stringMenu[indexMenu] );
	indexMenu--;
	if (indexMenu < 0)
		indexMenu = maxMenu -1;
	printf ( "Select: %s\n", stringMenu[indexMenu] );
}

void keyMenuDOWN ()
{
	printf ( "Normal: %s\n", stringMenu[indexMenu] );
	indexMenu++;
	if (indexMenu == maxMenu)
		indexMenu = 0;
	printf ( "Select: %s\n", stringMenu[indexMenu] );
}

void keyMenuSelect ()
{ functionMenu [indexMenu] (); }

/*
Reclama de:
	- minMenu
	- maxMenu
	- stringMenu
Defineix:
	- indexMenu
	- key
*/
void ShowOptions ()
{
/* Hauriem de fer un clear pantalla :) */
	int i;
	indexMenu = 0;
	key = 0;

	for ( i = 0; i < maxMenu; i++ )
	{
		printf ( "%s\n", stringMenu[i] );
	}
}

void quit () { menuWhile = 0; }

void confWelcom ()
{
	stringMenu [0] = "12345";
	stringMenu [1] = "Benbingut";
	stringMenu [2] = "Carregant configuracio UART";
	maxMenu = 3;
	minMenu = 0;
	functionKey[0] = confFirstMenu;
	functionKey[1] = confFirstMenu;
	functionKey[2] = confFirstMenu;
	functionKey[3] = confFirstMenu;
	functionKey[4] = confFirstMenu;
	functionKey[5] = confFirstMenu;
	functionKey[6] = confFirstMenu;
	ShowOptions ();
}

void confFirstMenu ()
{
	stringMenu [0] = "Encendre LED";
	stringMenu [1] = "Encendre Motor";
	stringMenu [2] = "Reton UART";
	stringMenu [3] = "Detector";
	stringMenu [4] = "EXIT";
	maxMenu = 5; /* hi ha 4 elements */
	minMenu = 0; /* Es pel robot */
	functionMenu [0] = confLEDMenu;
	functionMenu [1] = empty;
	functionMenu [2] = empty;
	functionMenu [3] = empty;
	functionMenu [4] = quit;
	functionKey [KEY_LEFT]		= empty;
	functionKey [KEY_RIGHT]		= empty;
	functionKey [KEY_CENTER]	= empty;
	functionKey [KEY_UP]		= keyMenuUP;
	functionKey [KEY_DOWN]		= keyMenuDOWN;
	functionKey [KEY_S1_BACK]	= empty;
	functionKey [KEY_S2_FORWARD]	= keyMenuSelect;

// Aquest ordre, perque el show fa un clear de pantalla (al reves, ja m'entens)
	printf ( "Menu principal\n" );
	ShowOptions ();
}

void confLEDMenu ()
{
	stringMenu [0] = "Encendre LED 1";
	stringMenu [1] = "Encendre LED 2";
	stringMenu [2] = "Encendre LED 3";
	stringMenu [3] = "Encendre LED 4";
	stringMenu [4] = "Encendre LED ->";
	stringMenu [5] = "Encendre LED <-";
	stringMenu [6] = "Encendre LED tots";
	maxMenu = 7; /* hi ha 4 elements */
	minMenu = 0; /* Es pel robot */
	functionMenu [0] = empty;
	functionMenu [1] = empty;
	functionMenu [2] = empty;
	functionMenu [3] = empty;
	functionMenu [4] = empty;
	functionMenu [5] = empty;
	functionMenu [6] = empty;
	functionKey [KEY_LEFT]		= empty;
	functionKey [KEY_RIGHT]		= empty;
	functionKey [KEY_CENTER]	= empty;
	functionKey [KEY_UP]		= keyMenuUP;
	functionKey [KEY_DOWN]		= keyMenuDOWN;
	functionKey [KEY_S1_BACK]	= confFirstMenu;
	functionKey [KEY_S2_FORWARD]	= keyMenuSelect;

// Aquest ordre, perque el show fa un clear de pantalla (al reves, ja m'entens)
	printf ( "Menu principal\n" );
	ShowOptions ();
}
void confMotorMenu ();
void confUARTMenu ();
void confDetectMenu ();

#include "menu.h"
#include "tmpForEste.h"

// Definim teclat
#define KEY_EMPTY	0
#define KEY_LEFT	1
#define KEY_RIGHT	2
#define KEY_CENTER	3
#define KEY_UP		4
#define KEY_DOWN	5
#define KEY_S1_BACK	6
#define KEY_S2_FORWARD	7

// Definim menus
//#define MENU_END_WHILE 0
#define MENU_WELCOME		1
#define MENU_PRINCIPAL_1	2

void initMenu ( uint8_t *indexMenu, uint8_t *statusKey )
{
	*indexMenu = MENU_WELCOME; /* per estar dins el bucle */
	*statKey = KEY_EMPTY;

	escribirInvertido	( "   Practica 5    ", 0 );
	escribir		( " Benbingut ", 2 );
}

uint8_t menu ( uint8_t *indexMenu, uint8_t statusKey )
{
	statusKey -= '1';
	switch ( *indexMenu )
	{
	case MENU_WELCOME:
		ClearScreen();
// Mostra Menu Principal
	case MENU_PRINCIPAL_1:
	}
}

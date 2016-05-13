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
#define MENU_PRINCIPAL 1

void initMenu ( uint8_t *indexMenu, uint8_t *statusKey )
{
	*indexMenu = MENU_WELCOM; /* per estar dins el bucle */
	*statKey = KEY_EMPTY;
}

uint8_t menu ( uint8_t *indexMenu, uint8_t statusKey )
{
	statusKey -= '1';
	switch ( *indexMenu )
	{
	case MENU_WELCOME:
		ClearScreen();
		escribirInvertido	( "   Practica 5    ", 0 );
		escribir		( " Benbingut ", 2 );
	}
}

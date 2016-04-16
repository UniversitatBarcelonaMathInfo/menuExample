#include <stdio.h>
#define FirstMenu 5
int menustatus = -1;

char * minitS [] =
{
	"menu Init 1",
	"menu Init 2",
	"menu Init 3",
	"menu Init 4",
	"menu Init 5"
};
char minitD = FirstMenu;
//minitE

/* Els que farem anar ara per ara */
char ** mSeeS = minitS;
char mSeeD = FirstMenu;
int menu ()
{
int i;
char c;
	if (menustatus < 0)
	{
		menustatus = 0;//\033[Fm
		printf ("-%s-\n", mSeeS[0]);
		for (i = 1; i < mSeeD; i++)
			printf ("%s\n", mSeeS[i]);
	}
	scanf (" %c", &c);
	switch (c)
	{
	case 'k': // cap aball
		printf ("Normal: %s\n", mSeeS[menustatus]);
		menustatus--;
		if ( menustatus < 0 )
			menustatus = mSeeD -1;
		printf ("Xulo: -%s-\n", mSeeS[menustatus]);
		break;
	case 'j': // cap amunt
		printf ("Normal: %s\n", mSeeS[menustatus]);
		menustatus++;
		if ( menustatus == mSeeD )
			menustatus = 0;
		printf ("Xulo: -%s-\n", mSeeS[menustatus]);
		break;
	case 'q': return 0;
	default: break;
	}
return 1;
}

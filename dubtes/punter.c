#include <stdint.h>
#include <stdio.h>

void entradaTimes3 ( uint8_t *times )
{	*times *= 3;	}


int main ()
{
	uint8_t a;

	a = 9;

	entradaTimes3 ( &a );
	printf ( "Llegit: %d\n", a );

return 0;
}

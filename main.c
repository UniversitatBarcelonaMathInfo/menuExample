#include <time.h>
#include "menu.h"

int main ()
{
	int i = 1;
//	struct timespec tim = {.tv_sec = 0, .tv_nsec = 500000000 }, tim2;
//	nanosleep (&tim, &tim2);
	while ( i )
	{
		i = menu ();
//		nanosleep (&tim, &tim2);
	}
return 0;
}

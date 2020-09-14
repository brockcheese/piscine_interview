#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 990);
	tankPush(tank, 100);
	tankPush(tank, 10);
	tankPop(tank);
	tankPush(tank, 10);
	tankPush(tank, 50);
	while(tankPop(tank) != -1);
	return (0);
}



// Function used for the test
// Don't go further :)

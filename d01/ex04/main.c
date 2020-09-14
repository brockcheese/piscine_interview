#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/
	struct s_queue *queue;

	queue = queueInit();
	printf("Is Empty: %d\n", isEmpty(queue));
	printf("dequeue: %s\n", dequeue(queue));
	printf("peek: %s\n", peek(queue));
	enqueue(queue, "Big");
	enqueue(queue, "Chonky");
	enqueue(queue, "Boi!");
	printf("Is Empty: %d\n", isEmpty(queue));
	printf("peek: %s\n", peek(queue));
	while(!(isEmpty(queue))) {
		printf("dequeue: %s\n", dequeue(queue));
	}
	return (0);
}



// Function used for the test
// Don't go further :)


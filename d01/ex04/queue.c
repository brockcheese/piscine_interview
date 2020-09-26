/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:55:46 by bpace             #+#    #+#             */
/*   Updated: 2020/02/26 18:27:12 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//initializes the queue

struct s_queue *queueInit(void) {
	struct s_queue *ans; //new queue

	ans = malloc(sizeof(struct s_queue)); //allocates memory for queue
	ans->first = NULL; //initialize first item in queue
	ans->last = NULL; //initialize last item in queue
	return (ans); //return queue
}

//remove the first item from the queue and return it

char *dequeue(struct s_queue *queue) {
	struct s_node *item; //stores first node in queue
	char *ans; //string to return front of queue

	item = queue->first; //store first node in queue
	if (item == NULL) //error checking
		return (NULL);
	queue->first = item->next; //set front of queue to next item
	if (queue->first == NULL) //sets end of queue to NULL if list is empty
		queue->last = NULL;
	ans = item->message; //sets return value
	free(item); //frees node
	return (ans); //return string
}

//add a message to the end of the queue

void enqueue(struct s_queue *queue, char *message) {
	struct s_node *newitem; //node to insert

	newitem = malloc(sizeof(struct s_node)); //allocates memory for node
	newitem->message = message; //store message in node
	newitem->next = NULL; //initialize next to NULL
	if (queue->last == NULL) { //if queue is empty set item as end of q
		queue->first = newitem;
	}
	else //attaches node to end of queue
		queue->last->next = newitem;
	queue->last = newitem; //sets end of queue as node
}

//returns the first item of the queue

char *peek(struct s_queue *queue) {
	if (queue->first == NULL) //error check
		return (NULL);
	return(queue->first->message); //return the first string in the queue
}

//returns 1 if the queue is empty, 0 otherwise

int isEmpty(struct s_queue *queue) {
	if (queue->first == NULL) //if queue is empty return 1
		return (1);
	return (0); //return 0 if the queue contains an item
}

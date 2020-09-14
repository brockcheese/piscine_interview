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

struct s_queue *queueInit(void) {
	struct s_queue *ans;

	ans = malloc(sizeof(struct s_queue));
	ans->first = NULL;
	ans->last = NULL;
	return (ans);
}

char *dequeue(struct s_queue *queue) {
	struct s_node *item;
	char *ans;

	item = queue->first;
	if (item == NULL)
		return (NULL);
	queue->first = item->next;
	if (queue->first == NULL)
		queue->last = NULL;
	ans = item->message;
	free(item);
	return (ans);
}

void enqueue(struct s_queue *queue, char *message) {
	struct s_node *newitem;

	newitem = malloc(sizeof(struct s_node));
	newitem->message = message;
	newitem->next = NULL;
	if (queue->last == NULL) {
		queue->first = newitem;
	}
	else
		queue->last->next = newitem;
	queue->last = newitem;
}

char *peek(struct s_queue *queue) {
	if (queue->first == NULL)
		return (NULL);
	return(queue->first->message);
}

int isEmpty(struct s_queue *queue) {
	if (queue->first == NULL)
		return (1);
	return (0);
}

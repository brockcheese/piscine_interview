/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   junkFood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 04:21:38 by bpace             #+#    #+#             */
/*   Updated: 2020/03/06 21:36:35 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	saveTime(char **arr, int i) {
	for (int j = 0; j < i; j++)
		arr[j] = NULL;
}

struct s_sellers *closestSellers(struct s_graph *parisPlaces, char *youAreHere) {
	struct s_queue *q = queueInit();
	struct s_node *temp;
	int i, d, nd, pd, check;

	for (i = 0; parisPlaces->places[i] && strcmp(parisPlaces->places[i]->name, youAreHere); i++);
	if (!parisPlaces->places[i])
		return (NULL);
	enqueue(q, parisPlaces->places[i]);
	for(; parisPlaces->places[i]; i++);
	char *arr[i];
	saveTime(arr, i);
	i = 0;
	d = 0;
	nd = 1;
	pd = 0;
	check = 0;
	while((temp = dequeue(q)) && (check == 0 || nd > 0)) {
		nd--;
		if (temp->visited == 0) {
			temp->visited = 1;
			if (temp->hasCerealBar) {
				arr[i++] = temp->name;
				check = 1;
			}
			for (int j = 0; check == 0 && temp->connectedPlaces[j]; j++) {
				enqueue(q, temp->connectedPlaces[j]);
				pd++;
			}
		}
		if (check == 0 && nd == 0) {
			d++;
			nd = pd;
			pd = 0;
		}
	}
	for(int j = 0; parisPlaces->places[j]; j++)
		parisPlaces->places[j]->visited = 0;
	while(dequeue(q));
	free(q);
	if (i == -1)
		return (NULL);
	struct s_sellers *s = malloc(sizeof(struct s_sellers));
	s->distance = d;
	s->placeNames = malloc(sizeof(char *) * (i + 1));
	s->placeNames[i] = NULL;
	for(int j = 0; j < i; j++)
		s->placeNames[j] = arr[j];
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxTraffic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 22:35:37 by bpace             #+#    #+#             */
/*   Updated: 2020/03/06 23:40:34 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float maxTraffic(struct s_graph *parisPlaces, char *eventHere) {
	int i;

	for (i = 0; parisPlaces->places[i]; i++);
	int arr[i];
	for (int j = 0; j < i; j++) {
		arr[i] = -1;
	}
}

void	saveTime(struct s_node **arr, int i) {
	for (int j = 0; j < i; j++)
		arr[j] = NULL;
}

void	saveTime2(int **arr, int i) {
	for (int j = 0; j < i; j++) {
		arr[j] = -1;
	}
}

void	saveTime3(float **arr, int i) {
	for (int j = 0; j < i; j++)
		arr[j] = -1;
}

int		notIn(struct s_node *check, struct s_node **arr) {
	for (int j = 0; arr[j]; j++) {
		if (check == arr[j])
			return (1);
	}
	return (0);
}

float maxTraffic(struct s_graph *parisPlaces, char *eventHere) {
	struct s_queue *q = queueInit();
	struct s_node *temp;
	int i, nd, pd, k, l, rand;
	float tmax, ans, n, d;

	for (i = 0; parisPlaces->places[i] && strcmp(parisPlaces->places[i]->name, eventHere); i++);
	if (!parisPlaces->places[i])
		return (-1);
	enqueue(q, parisPlaces->places[i]);
	for(; parisPlaces->places[i]; i++);
	struct s_node *arr[i];
	int arr2[i];
	float arr3[i];
	saveTime(arr, i);
	saveTime2(arr2, i);
	saveTime3(arr3, i);
	k = l = 0;
	nd = 1;
	pd = 0;
	tmax = 0;
	ans = 0;
	n = d = 0;
	while((temp = dequeue(q))) {
		nd--;
		if (temp->visited == 0) {
			arr[k++] = temp;
			temp->visited = 1;
			arr2[l] = 0;
			for (int j = 0; temp->connectedPlaces[j]; j++) {
				enqueue(q, temp->connectedPlaces[j]);
				pd++;
				arr2[l]++;
			}
			for (int j = 0; temp->connectedPlaces[j]; j++) {
				if (temp->connectedPlaces[j]->visited == 1 && notIn(temp->connectedPlaces[j], arr))
					d++;
			}
			n = ((float)temp->population) / d;
			for(rand = 0; arr2[rand] < 1; rand++);
			arr3[l] = n + arr3[rand];
			l++;
		}
		if (nd == 0) {
			saveTime(arr, i);
			k = 0;
			nd = pd;
			pd = 0;
		}
		for (rand = 0; arr2[rand] < 1; rand++)
		arr2[rand]--;
	}
	for(int j = 0; parisPlaces->places[j]; j++)
		parisPlaces->places[j]->visited = 0;
	while(dequeue(q));
	free(q);
	ans = arr3[0];
	for (rand = 1; arr3[rand] >= 0; rand++) {
		if (arr3[rand] > ans)
			ans = arr3[rand];
	}
	return (ans);
}

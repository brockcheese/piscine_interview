/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:51:40 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 14:08:48 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sorts section of array

int		sort(struct s_player **players, int start, int end) {
	struct s_player *temp; //storage for swap
	int i = start - 1; //initialize index for pivot

	//sorts items at pivot
	for (int j = start; j < end; j++) {
		//swaps items at pivot if they need to be sorted
		if (players[j]->score > players[end]->score) {
			i++;
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
		}
	}
	//swaps pivot with current pivot index
	temp = players[++i];
	players[i] = players[end];
	players[end] = temp;
	return (i); //return pivot index
}

//helper function for recursion

void quickSortHelper(struct s_player **players, int start, int end) {
	if (start < end) { //error check
		int pivot = sort(players, start, end); //sorts array
		//recursively sorts everything to the left of the pivot
		quickSortHelper(players, start, pivot - 1);
		//recursively sorts everything to the right of the pivot
		quickSortHelper(players, pivot + 1, end);
	}
}

//quicksort that sorts player structure by score in descending order

void quickSort(struct s_player **players) {
	int i; //indexer

	i = -1; //initialize index
	while(players[++i]) //sets i to count
		;
	quickSortHelper(players, 0, i - 1); //pushes it to recursive function
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:43:15 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 15:39:19 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//merges arrays

struct s_player	**merge(struct s_player **players, int start, int m, int end) {
	struct s_player **playersleft; //stores left half of array
	struct s_player **playersright; //stores right half of array
	int i, j; //indexes

	//allocates memory for array left of pivot
	playersleft = malloc(sizeof(struct s_player*) * (m - start + 2));
	//allocates memory for array right of pivot
	playersright = malloc(sizeof(struct s_player*) * (end - m + 1));
	i = -1; //index intialization
	for(int k = start; k <= end; k++) {
		if (k <= m) //fills left half of array
			playersleft[++i] = players[k];
		if (k == m + 1) { //null terminates left array
			playersleft[++i] = NULL;
			i = -1; //resets the index
		}
		if (k > m) //fills right half of array
			playersright[++i] = players[k];
	}
	playersright[++i] = NULL; //null terminates right array
	i = 0; //reset indexes
	j = 0;
	for (int k = start; k <=end; k++) { //merges arrays back into original
		if (playersleft[i] && (!(playersright[j]) || playersleft[i]->score >= playersright[j]->score)) {
			players[k] = playersleft[i++]; //inserts left items
		}
		else
			players[k] = playersright[j++]; //inserts right items
	}
	free(playersleft); //frees left array
	free(playersright); //frees right array
	return (players); //return sorted array
}

//helper function for recursion

void			mergeSortHelper(struct s_player **players, int start, int end) {
	int m = (start + (end - 1)) / 2; //stores index of middle of array

	if (start < end) { //recursively sorts array
		mergeSortHelper(players, start, m); //sorts left of middle
		mergeSortHelper(players, m + 1, end); //sorts right of middle
		players = merge(players, start, m, end); //merge arrays
	}
}

//merge sort that sorts players by score in descending order

struct s_player **mergeSort(struct s_player **players) {
	int i = -1; //initializes count

	while(players[++i]); //counts items in players
	mergeSortHelper(players, 0, i - 1); //function for recursion
	return players; //return sorted array
}

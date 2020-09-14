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

int		sort(struct s_player **players, int start, int end) {
	struct s_player *temp;
	int i = start - 1;

	for (int j = start; j < end; j++) {
		if (players[j]->score > players[end]->score) {
			i++;
			temp = players[i];
			players[i] = players[j];
			players[j] = temp;
		}
	}
	temp = players[++i];
	players[i] = players[end];
	players[end] = temp;
	return (i);
}

void quickSortHelper(struct s_player **players, int start, int end) {
	if (start < end) {
		int pivot = sort(players, start, end);
		quickSortHelper(players, start, pivot - 1);
		quickSortHelper(players, pivot + 1, end);
	}
}

void quickSort(struct s_player **players) {
	int i;

	i = -1;
	while(players[++i])
		;
	quickSortHelper(players, 0, i - 1);
}

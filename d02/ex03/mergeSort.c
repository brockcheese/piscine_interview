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

struct s_player	**merge(struct s_player **players, int start, int m, int end) {
	struct s_player **playersleft;
	struct s_player **playersright;
	int i, j;

	playersleft = malloc(sizeof(struct s_player*) * (m - start + 2));
	playersright = malloc(sizeof(struct s_player*) * (end - m + 1));
	i = -1;
	for(int k = start; k <= end; k++) {
		if (k <= m)
			playersleft[++i] = players[k];
		if (k == m + 1) {
			playersleft[++i] = NULL;
			i = -1;
		}
		if (k > m)
			playersright[++i] = players[k];
	}
	playersright[++i] = NULL;
	i = 0;
	j = 0;
	for (int k = start; k <=end; k++) {
		if (playersleft[i] && (!(playersright[j]) || playersleft[i]->score >= playersright[j]->score)) {
			players[k] = playersleft[i++];
		}
		else
			players[k] = playersright[j++];
	}
	free(playersleft);
	free(playersright);
	return (players);
}

void			mergeSortHelper(struct s_player **players, int start, int end) {
	int m = (start + (end - 1)) / 2;

	if (start < end) {
		mergeSortHelper(players, start, m);
		mergeSortHelper(players, m + 1, end);
		players = merge(players, start, m, end);
	}
}

struct s_player **mergeSort(struct s_player **players) {
	int i = -1;

	while(players[++i]);
	mergeSortHelper(players, 0, i - 1);
	return players;
}

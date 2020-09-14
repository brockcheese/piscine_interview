/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpace <bpace@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:31:21 by bpace             #+#    #+#             */
/*   Updated: 2020/02/27 13:40:41 by bpace            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void insertionSort(struct s_player **players) {
	struct s_player *player;
	int				i, j;

	i = 0;
	while(players[++i]) {
		player = players[i];
		for(j = i - 1; j != -1 && player->score > players[j]->score; j--) {
			players[j + 1] = players[j];
		}
		players[j + 1] = player;
	}
}

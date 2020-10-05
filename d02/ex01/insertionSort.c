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

//simple insertion sort that sorts scores in descending order

void insertionSort(struct s_player **players) {
	struct s_player *player; //stores single item in array
	int				i, j;

	i = 0; //index initialization
	while(players[++i]) { //sorts each item in the array
		player = players[i]; //stores current item
		for(j = i - 1; j != -1 && player->score > players[j]->score; j--) {
			players[j + 1] = players[j]; //moves item up in array
		}
		players[j + 1] = player; //inserts item back into the array
	}
}
